// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char hashAlpha[N];
    // Just for a test
    hashAlpha[0] = 'a';
    hashAlpha[1] = 'b';
    hashAlpha[2] = 'c';

    for (unsigned int i = 0; i < 3; i++)
    {
        if (word[0] == hashAlpha[i])
        {
            //printf("%i %c\n", i, hashAlpha[i]);
            return i;
        }
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
     // Open the Dictionary file
    FILE *dictionaryFile = fopen(dictionary, "r");

    if (dictionaryFile == NULL)
    {
        return false;
    }

    // Word Buffer
    char wordBuffer[45];

    while (true)
    {
        // Read string from file
        size_t fileRead = fscanf(dictionaryFile, "%s", wordBuffer);

        // Stop loading words if fileRead is EOF
        if (fileRead == EOF)
        {
            break;
        }
        // Create a new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node != NULL)
        {
            // Copy the word into new_node->word
            strcpy(new_node->word, wordBuffer);
            // Point the first node to NULL
            new_node->next = NULL;
            // Hash the word
            hash(new_node->word);

            // The hash table not pointing
            if (table[hash(new_node->word)] == NULL)
            {
                // insert the word into the hash table
                table[hash(new_node->word)] = new_node;
                printf("%i %s\n", hash(new_node->word), new_node->word);
            }
            else
            {
                new_node->next = table[hash(new_node->word)];
                table[hash(new_node->word)] = new_node;
                printf("%i %s\n", hash(new_node->word), new_node->word);
            }
        }
        free(new_node);
    }
    return true;
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
