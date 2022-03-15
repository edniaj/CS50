// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = (LENGTH+1) * 'z';

// Hash table


int totalWords = 0;
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index  = hash(word);

    node *cursor = table[index];
    while(cursor!=NULL)
    {
        if(strcasecmp(cursor->, word) ==0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    // TODO
    // int hashIndex = hash(word);
    // node *tmp = table[hashIndex];
    // while (tmp != NULL)
    // {
    //     if (strcasecmp(tmp->word, word) == 0)
    //     {
    //         return true;
    //     }
    //     tmp = tmp->next;
    // }
    // return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int hashIndex = ((int)toupper(word[0]) * 4) % 40;
    return toupper(word[0]);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        strcpy(new_node->word, word);
        new_node->next = NULL;

        int index = hash(word);
        if (table[index] == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
        totalWords++;
    }
    fclose(file);
    return true;
}
// TODO
// FILE *pRead = fopen(dictionary, "r");
// if (pRead == NULL)
// {
//     printf("Memory ran out of space");
//     return false;
// }

// char word[LENGTH + 1];

// while (fscanf(pRead, "%s", word) != EOF)
// {
//     node *n = malloc(sizeof(node));
//     n->next = NULL; // We will insert node from the front
//     strcpy(n->word, word);
//     int hashIndex = hash(word);
//     if (table[hashIndex] == NULL)
//     {
//         table[hashIndex] = n;
//     }
//     else
//     {
//         n->next = table[hashIndex];
//         table[hashIndex] = n;
//     }
//     totalWords++;
// }
// free(word);
// fclose(pRead);
// return true;
// }

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return totalWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
    // for (int i = 0; i < N; i++)
    // {
    //     if (table[i] != NULL)
    //     {
    //         node *tmp = table[i]->next;
    //         free(table[i]);
    //         while (tmp != NULL)
    //         {
    //             node *tmp2 = tmp;
    //             tmp = tmp->next;
    //             free(tmp2);
    //         }
    //         free(tmp);
    //     }
    //     else
    //     {
    //         free(table[i]);
    //     }
    // }
    // return true;
// }
