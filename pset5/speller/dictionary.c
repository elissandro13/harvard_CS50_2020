// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include <strings.h>
#include <string.h>
// #define LENGTH 100

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

long int numberWords = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int key = hash(word);

    for (node *tmp = table[key]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        value += tolower(word[i]);
    }

    return value % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char tempWord[LENGTH];

    while (fscanf(file, "%s", tempWord) != EOF)
    {

        node *tempNode = malloc(sizeof(node));

        numberWords++;

        strcpy(tempNode->word, tempWord);

        int key = hash(tempNode->word);

        if (table[key] == NULL)
        {
            tempNode->next = NULL;
            table[key] = tempNode;
        }
        else
        {
            tempNode->next = table[key];
            table[key] = tempNode;
        }

    }



    fclose(file);
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    return numberWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            for (node *tmp = table[i]; tmp != NULL;)
            {
                node *cursor = tmp->next;
                free(tmp);
                tmp = cursor;
            }
        }
    }
    return true;
}
