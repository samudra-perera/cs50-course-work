#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// int encryption(string text, string key);
int input_validation(string key);

int main(int argc, string argv[])
{
    if(argc != 2 || input_validation(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Grabbing the string
    string text = get_string("plaintext: ");
    //Turning the key into a integer value
    int intKey = atoi(argv[1]);
    //Initializing the ciphers and alpha ints
    int cipher, alpha_pos;
    printf("plaintext: %s\n", text);
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        //Deals with the lowercase
        if (islower(text[i]))
        {
            alpha_pos = (int) text[i] - 97;
            cipher = ((alpha_pos + intKey) % 26) + 97;  //is equal to the ascii value
            printf("%c", cipher);
        }
        //Deals with the uppercase
        else if (isupper(text[i]))
        {
            alpha_pos = (int) text[i] - 65;
            cipher = ((alpha_pos + intKey) % 26) + 65;
            printf("%c", cipher);
        }
        //Deals with all non letter characters
        else
        {
            alpha_pos = (int) text[i];
            printf("%c", alpha_pos);
        }
    }
    printf("\n");
}

//Iterate through the key and check if every character is a digit if not return true
int input_validation(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            return 1;
        }
    }
    return 0;
}

//Passed all tests and got 99% in the styling category