// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // traverse linked list, looking for the word (strcasecmp)
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *pRead = fread()
    // TODO
    // Open dictionary file
        // Check if return value is NULL

    // Read strings from file one at a time
        // fscanf(file, "%s", word) , reads word until it returns EOF (end of file)
    //Create a new node for each word
        // Use malloc =>  if it returns NULL then fn return false
        // strcpy into node using strcpy
    /// Hash word to obtain a hash value
        // Generate our own hash function // all of them are islower()
    // Insert node into hash table at that location

    return false; // If unable to open up a fiel
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
