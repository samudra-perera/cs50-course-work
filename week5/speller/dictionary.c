// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

//Variables
unsigned int word_count;
unsigned int hash_value;

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
    //Get the hashed value of the word to enter the specified bucket
    hash_value = hash(word);

    //point the checkNode to the head of the hash_value
    node *checkNode = table[hash_value];

    //While the checkNode pointer does not equal to NULL (has not reached the end of the list), traverse the list and compare the value of checkNode with word
    while(checkNode != NULL) {
        if(strcasecmp(checkNode->word, word) == 0)
        {
            return true;
        };
        checkNode = checkNode->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //This hashfunction was taken from https://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-13.html,
    //and adds all the ASCCII values of each character of the word and finds the reminder of N division
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Open dictionary with file pointer and open it in a read format
    FILE *file = fopen(dictionary, "r");

    //Return false if file can't be opened
    if (file == NULL)
    {
        return false;
    }

    //Declare word variable with length of 45 (largest word in) as per dictionary.h + 1 for the string exit character
    char word[LENGTH+1];


    while(fscanf(file, "%s", word) != EOF)
    {
        //Make space in memory for the node
        node *n = malloc(sizeof(node));

        if(n == NULL)
        {
            return false;
        }

        //Copy words into node
        strcpy(n->word, word);
        hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if(word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //Iterate through each bucket in the hashTable
    for(int i = 0; i < N; i++)
    {
        //Set Currentnode to the start of the linked list
        node *currentNode = table[i];

        //If the cursor is not NULL, free memory
        while(currentNode != NULL)
        {
            //Create a temp pointer
            node *temp = currentNode;
            //Set currentNode to the nextNode
            currentNode = currentNode -> next;
            //Free Temp (which is the previous node)
            free(temp);
        }
    }
    return true;
}

//Passes 9/9 tesets ad 94% on the styling
