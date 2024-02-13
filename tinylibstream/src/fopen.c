#include "../include/libstream.h"

#include <stdlib.h>
#include <string.h>

/*
** Opens the file at some path with the flags described by mode, and wrap it in
** a buffered stream. It works just like fopen(3), except you only have to
** handle the modes r, r+, w and w+
*/
struct stream *lbs_fopen(const char *path, const char *mode)
{
    if (!path || !mode)
        return NULL;

    // Make sure the mode is valid
    if (strcmp(mode, "r") != 0 && strcmp(mode, "r+") != 0 &&
        strcmp(mode, "w") != 0 && strcmp(mode, "w+") != 0)
        return NULL;

    // Get the flags
    int flags = 0;

    if (strcmp(mode, "r") == 0)
        flags = O_RDONLY;

    else if (strcmp(mode, "r+") == 0)
        flags = O_RDWR;
        
    else if (strcmp(mode, "w") == 0)
        flags = O_WRONLY | O_CREAT | O_TRUNC;

    else if (strcmp(mode, "w+") == 0)
        flags = O_RDWR | O_CREAT | O_TRUNC;


    int fd = open(path, flags, 0644);
    if (fd == -1)
        return NULL;

    return lbs_fdopen(fd, mode);
}

/*
** Initializes a stream structure with the given file descriptor and mode. It
** works just like lbs_fopen() except it takes the file descriptor instead of
** the path.
**
** It can be used by lbs_fopen() to make implementation clearer.
** It will also be useful to initialize streams to already open file
** descriptors, such as stdin, stdout and stderr.
**
** It may fail when calling isatty() and the file descriptor is invalid.
** Returns NULL on failure.
*/
struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (fd < 0 || !mode)
        return NULL;

    // Make sure the mode is valid
    if (strcmp(mode, "r") != 0 && strcmp(mode, "r+") != 0 &&
        strcmp(mode, "w") != 0 && strcmp(mode, "w+") != 0)
        return NULL;

    // Get the flags
    int flags = 0;

    if (strcmp(mode, "r") == 0)
        flags = O_RDONLY;

    else if (strcmp(mode, "r+") == 0)
        flags = O_RDWR;
        
    else if (strcmp(mode, "w") == 0)
        flags = O_WRONLY | O_CREAT | O_TRUNC;

    else if (strcmp(mode, "w+") == 0)
        flags = O_RDWR | O_CREAT | O_TRUNC;

    struct stream *s = malloc(sizeof(struct stream));
    if (!s)
        return NULL;
    
    s->error = 0;

    s->flags = flags;
    s->fd = fd;

    if (isatty(fd))
        s->buffering_mode = STREAM_LINE_BUFFERED;
    else
        s->buffering_mode = STREAM_BUFFERED;

    s->buffered_size = 0;
    s->already_read = 0;

    return s;
}

/*
** Closes the stream and underlying file descriptor, flushing buffered data.
** No other function should be called on the stream after lbs_fclose(), as
** the stream is freed if the function returns successfully.
** Works just like fclose(3).
*/
int lbs_fclose(struct stream *file)
{
    if (!file)
        return -1;

    int flush_res = lbs_fflush(file);
    if (flush_res == -1)
        return -1;

    int close_res = close(file->fd);
    if (close_res == -1)
        return -1;
    
    free(file);

    return 0;
}

/*
** Flushes the stream's buffer to the underlying file descriptor, making sure
** the stream position is correct. When there is some write data buffered, it
** has to be written. When there is some read data buffered, it has to be
** discarded and the process must seek the file descriptor back to the
** position the user expects.
**
** Works just like fflush(3), except:
**  - lbs_fflush() *DOES NOT* flush all open output streams if stream is NULL.
** May set the error indicator.
*/
int lbs_fflush(struct stream *stream)
{
    if (!stream)
        return -1;

    if (stream->io_operation == STREAM_WRITING)
    {
        if (stream->buffered_size > 0)
        {
            int res = write(stream->fd, stream->buffer, stream->buffered_size);
            if (res == -1)
            {
                stream->error = 1;
                return -1;
            }

            stream->already_read = 0;
            stream->buffered_size = 0;

            return 0;
        }
    }
    else if (stream->io_operation == STREAM_READING)
    {
        if (stream->buffered_size > 0)
        {
            if (stream_remaining_buffered(stream) == 0)
            {
                stream->buffered_size = 0;
                stream->already_read = 0;
                return 0;
            }

            int pos = lseek(stream->fd, -stream_remaining_buffered(stream), SEEK_CUR);
            if (pos == -1)
            {
                stream->error = 1;
                return -1;
            }

            stream->buffered_size = 0;
            stream->already_read = 0;
            return 0;
        }
    }

    return 0;
}

/*
** Reads a new character from the stream's buffer.
** If the buffer it empty, it should be refilled.
** Works just like fgetc(3). May set the error indicator.
*/
int lbs_fgetc(struct stream *stream)
{
    if (!stream || !stream_readable(stream))
        return -1;
    
    if (stream->io_operation != STREAM_READING)
    {
        // Flush the buffer
        int flush_res = lbs_fflush(stream);
        if (flush_res == -1)
            return -1;

        stream->io_operation = STREAM_READING;  
    }

    if (stream_remaining_buffered(stream) == 0)
    {
        // Flush the buffer
        int flush_res = lbs_fflush(stream);
        if (flush_res == -1)
            return -1;

        // Refill the buffer
        int bytes_read = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
        if (bytes_read == -1)
        {
            stream->error = 1;
            return -1;
        }

        stream->buffered_size = bytes_read;
        stream->already_read = 0;
    }

    if (stream->buffered_size == 0)
        return -1; // EOF (no more data to read)

    unsigned char c = stream->buffer[stream->already_read];
    stream->already_read++;

    return c;
}

/*
** Writes a single character to some stream.
** It may cause the stream to flush if the buffer is full or the current
** buffering policy requires it.
** Works just like fputc(3). May set the error indicator.
*/
int lbs_fputc(int c, struct stream *stream)
{
    if (!stream || !stream_writable(stream))
        return -1;

    if (stream->io_operation != STREAM_WRITING)
    {
        // Flush the buffer
        int flush_res = lbs_fflush(stream);
        if (flush_res == -1)
            return -1;

        stream->io_operation = STREAM_WRITING;
    }

    if (stream_unused_buffer_space(stream) == 0)
    {
        int res = lbs_fflush(stream);
        if (res == -1)
            return -1;
    }

    if (stream->buffering_mode == STREAM_LINE_BUFFERED && c == '\n')
    {
        int res = lbs_fflush(stream);
        if (res == -1)
            return -1;
    }

    // Write the character to the file
    stream->buffer[stream->buffered_size] = c;
    stream->buffered_size++;

    if (stream->buffering_mode == STREAM_UNBUFFERED)
    {
        int res = lbs_fflush(stream);
        if (res == -1)
            return -1;
    }

    return c;
}
