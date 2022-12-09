#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    //1. Convert all letters into lowercase
    //2. Convert all letters into ASCII values then subtract 96 to normalize the 97 to get array index values
    //3. Add values of array into the sum of the total, return the total sum
    int character, index, sum = 0, value;
    for (int i = 0; i < strlen(word); i++)
    {
        character = (int) tolower(word[i]); //Converting into ASCII
        index = character - 97; //Reducing to 0-25 index
        value = POINTS[index];  //Getting the value from the points array
        if (index > 25 || index < 0) //If the ascii value index does not exist in the array set the addscore val to 0
        {
            value = 0;
        }
        sum+=value;
    }
    return sum;
}

//Passed 11/11 test and get 98% for the styling!