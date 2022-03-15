// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 40;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int hashIndex = ((int)toupper(word[0]) * 4) % 40 return toupper(word[0]);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *pRead = fopen(dictionary, 'r');
    if (pRead == NULL)
    {
        printf("Memory ran out of space");
        return false
    }

    char *word = malloc(LENGTH + 1);
    ;
    while (fscanf(word, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        strcpy(n->word,word);
        n->next = NULL; // We will insert node from the front
        int hashIndex = hash(word);
        if (table[hashIndex] == NULL)
        {
            table[hashIndex] =  n;
        }
        
    }

    free(word);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
