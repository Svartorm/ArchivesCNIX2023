#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static int signal_count = 0;
static int generation = 0;

void handle_signal(int signal);

int main(void)
{
    pid_t pid;
    // Fork the process
    pid = fork();

    // If the fork failed, exit with an error
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }

    // If the fork succeeded, exit the parent process
    if (pid > 0)
    {
        exit(0);
    }

    // Set up signal handling
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    if (sigaction(SIGTERM, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
        exit(1);
    }

    // Main loop
    while (1)
        continue;

    return 0;
}

void handle_signal(int signal)
{
    switch (signal)
    {
    case SIGUSR1:
        signal_count++;

        printf("Received %d signals.\n", signal_count);
        fflush(stdout);
        break;

    case SIGUSR2:
        signal_count++;
        printf("Current generation: %d\n", generation);
        fflush(stdout);
        break;

    case SIGTERM:
        generation++;
        signal_count = 0;
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(1);
        }
        if (pid > 0)
        {
            exit(0);
        }
        break;

    case SIGINT:
        exit(0);
        break;

    default:
        break;
    }
}
