// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

unsigned int totalWords = 0;
// TODO: Choose number of buckets in hash table
const unsigned int N = 50;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashIndex = hash(word);
    node *tmp = table[hashIndex];
    while (tmp != NULL)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
        node *tmp2 = table[i]->next;
        tmp = tmp2;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'a' + strlen(word);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *pReadFile = fread();
    if (pReadFile == NULL)
    {
        printf("Lack of memory") return false;
    }

    char *word[20];
    while (fscanf(pReadFile, "%s", word) != NULL)
    {
        node *n = malloc(sizeof(node));
        n->word = strcpy(word);
        int hashIndex = hash(n->word);
        if (table[hashIndex] == NULL)
        { // table[hashIndex] -> Head of pointer
            table[hashIndex] = n
        }
        else
        {
            n->next = table[hasIndex];
        }
        totalWords++;
    }
    // TODO
    // Open dictionary file
    // Check if return value is NULL

    // Read strings from file one at a time
    // fscanf(file, "%s", word) , reads word until it returns EOF (end of file)
    // Create a new node for each word
    //  Use malloc =>  if it returns NULL then fn return false
    //  strcpy into node using strcpy
    /// Hash word to obtain a hash value
    // Generate our own hash function // all of them are islower()
    // Insert node into hash table at that location

    return false; // If unable to open up a file
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return totalWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        while (tmp != NULL)
        {
            node *tmp2 = table[i]->next;
            free(table[i]);
            tmp = tmp2;
        }
        if (i == N - 1)
            return true;
    }
    return false;
}
