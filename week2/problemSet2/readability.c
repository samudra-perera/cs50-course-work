#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string words = get_string("Please enter the text you want to analyze: ");
    float letters = count_letters(words);
    float num_words = count_words(words);
    float sentences = count_sentences(words);
    float L = (letters/num_words) * 100;
    float S = (sentences/num_words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // printf("%f\n", letters);
    // printf("%f\n", num_words);
    // printf("%f\n", sentences);
    // printf("%f\n", L);
    // printf("%f\n", S);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int character, count = 0;
    //I want to count all letters (only), no punctuation or spaces
    for (int i = 0; i < strlen(text); i++)
    {
        character = (int) tolower(text[i]) - 97;
        if(character <= 25 && character >= 0)
        {
            count++;
        }
    }
    return count;
}

//This will return the number of words
int count_words(string text)
{
    int character, count = 0;
    //Counting only spaces
    for (int i = 0; i < strlen(text); i++)
    {
        character = (int) text[i];
        if (character == 32)
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(string text)
{
    int character, count = 0;
    //Counting only periods, exclamation marks or questions
    for (int i = 0; i < strlen(text); i++)
    {
        character = (int) text[i];
        if (character == 46 || character == 33 || character == 63)
        {
            count++;
        }
    }
    return count;
}

//Passed 11/11 tests and style score of 96%