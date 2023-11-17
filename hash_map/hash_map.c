#include "hash_map.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_map *hash_map_init(size_t size)
{
    // Allocate a new hash map
    struct hash_map *new = malloc(sizeof(struct hash_map));
    if (!new)
        return NULL;

    // Init size
    new->size = size;

    // Allocate the linked matrix data of size 'size'
    new->data = calloc(size, sizeof(struct pair_list *));
    if (!new->data)
    {
        free(new);
        return NULL;
    }

    return new;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    // Check hash_map
    if (!hash_map || hash_map->size == 0)
        return false;

    // Hash the key
    size_t hashed_key = hash(key);
    size_t h = hashed_key % hash_map->size;

    // Try to insert in hash map
    if (!hash_map->data[h])
    {
        // There is space for our value so we insert
        hash_map->data[h] = malloc(sizeof(struct pair_list));
        if (!hash_map->data[h])
            return false;

        // Set the values
        hash_map->data[h]->key = key;
        hash_map->data[h]->value = value;
        hash_map->data[h]->next = NULL;

        // We have not updated any value
        if (updated)
            *updated = false;

        return true;
    }

    // Resolve the collision
    struct pair_list *tail = hash_map->data[h];

    while (tail)
    {
        // Does our element already exist ?
        if (strcmp(tail->key, key) == 0)
        {
            tail->value = value;
            if (updated)
                *updated = true;
            return true;
        }

        // We loop on the next element of the list
        tail = tail->next;
    }

    // We can insert
    // Init new element
    struct pair_list *head = malloc(sizeof(struct pair_list));

    head->key = key;
    head->value = value;
    head->next = hash_map->data[h];

    // We add it to the linked list
    hash_map->data[h] = head;

    // We have not updated any value
    if (updated)
        *updated = false;

    return true;
}

/*--- FREE FUNCTIONS -- */
void pair_list_free(struct pair_list *pair_list)
{
    struct pair_list *tail = pair_list;

    while (tail->next)
    {
        struct pair_list *head = tail;

        tail = tail->next;

        free(head);
    }

    free(tail);
}

void hash_map_free(struct hash_map *hash_map)
{
    if (!hash_map || hash_map->size == 0)
        return;

    for (size_t h = 0; h < hash_map->size; h++)
    {
        if (hash_map->data[h])
            pair_list_free(hash_map->data[h]);
    }

    free(hash_map->data);
    free(hash_map);
}
/*--- !FREE FUNCTIONS! ---*/

/*--- DUMP FUNCTIONS ---*/
void pair_list_dump(struct pair_list *pair_list)
{
    struct pair_list *head = pair_list;

    while (head)
    {
        printf("%s: %s", head->key, head->value);

        if (!head->next)
            printf("\n");
        else
            printf(", ");

        head = head->next;
    }
}

void hash_map_dump(struct hash_map *hash_map)
{
    for (size_t h = 0; h < hash_map->size; h++)
        pair_list_dump(hash_map->data[h]);
}
/*--- !DUMP FUNCTIONS! ---*/

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (!hash_map || hash_map->size == 0)
        return NULL;

    // Compute hash key
    size_t hashed_key = hash(key);
    size_t h = hashed_key % hash_map->size;

    // Look for key
    if (!hash_map->data[h]) // No value
        return NULL;

    struct pair_list *head = hash_map->data[h];

    while (head)
    {
        if (strcmp(head->key, key) == 0)
            return head->value;

        head = head->next;
    }

    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (!hash_map || hash_map->size == 0)
        return NULL;

    // Compute hash key
    size_t hashed_key = hash(key);
    size_t h = hashed_key % hash_map->size;

    // Look for key
    if (!hash_map->data[h]) // No value
        return false;

    struct pair_list *head = hash_map->data[h];

    // Check first array value
    if (strcmp(head->key, key) == 0)
    {
        // Behead the list
        hash_map->data[h] = head->next;

        // Free head
        free(head);

        return true;
    }

    // look for the key in the list
    struct pair_list *posthead = head->next;
    while (posthead)
    {
        if (strcmp(posthead->key, key) == 0)
        {
            // Remove posthead from the list
            head->next = posthead->next;

            // Free head
            free(posthead);

            return true;
        }

        head = head->next;
        posthead = head->next;
    }

    return false;
}
