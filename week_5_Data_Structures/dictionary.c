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
    // Copy the word
    char temp[strlen(word) + 1];
    strcpy(temp, word);

    // Get the key
    int key = hash(word);

    // Create a cursor
    node *cursor = table[key];

    // Verify if word extist in linked list with hash(key)
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, temp) == 0)
        {
            return true;
        }
        cursor = cursor->next;

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    // Count two char
    for (int i = 0; i < 2; i++)
    {
        hash = hash + tolower(word[i]) - 'a' * 2 ^ i;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize the hashtable
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Initialize the word counter
    word_count = 0;

    // Open the Dictionary file
    FILE *dictionaryFile = fopen(dictionary, "r");

    if (dictionaryFile == NULL)
    {
        return false;
    }

    // Word Buffer
    char wordBuffer[LENGTH + 1];

    // Repeat util the end of file
    while (fscanf(dictionaryFile, "%s", wordBuffer) != EOF)
    {
        // get index of hashtable to put word in
        int key = hash(wordBuffer);

        // Create a new node for each word
        node *new_node = malloc(sizeof(node));

        // Copy the word into new_node->word
        strcpy(new_node->word, wordBuffer);

        // The hash table not pointing
        if (table[key] == NULL)
        {
            // insert the word into the hash table
            table[key] = new_node;
            // Point the first node to NULL
            new_node->next = NULL;
        }
        else
        {
            new_node->next = table[key];
            table[key] = new_node;
        }
        word_count++;
    }

    // Close dictionary
    fclose(dictionaryFile);

    return true;
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
    // Check each element of table array
    for (int i = 0; i < N;)
    {
        while (table[i])
        {
            // Create a temp pointer
            node *cursor = table[i];
            // Point to the next node
            table[i] = cursor->next;
            free(cursor);
        }
        i++;
    }
    return true;
}
