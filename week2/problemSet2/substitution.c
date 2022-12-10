#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int input_validation(string key);
int main(int argc, string argv[])
{
    if (argc != 2 || input_validation(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Set the cipher
    string cipher = argv[1];
    //Grab the text to substitute
    string text = get_string("Enter text to encrypt: ");
    printf("plaintext: %s\n", text);
    printf("ciphertext: ");
    //Iterate through the text and replace with the cipher
    int index;
    char character;
    for (int i = 0; i < strlen(text); i++)
    {
        index = (int) tolower(text[i]) - 97;
        character = text[i];
        //Deals with lowercase
        if (islower(character))
        {
            character = tolower(cipher[index]);
            printf("%c", character);
        }
        //Deals with uppercase
        else if (isupper(character))
        {
            character = toupper(cipher[index]);
            printf("%c", character);
        }
        else
        {
            printf("%c", character);
        }
    }
    printf("\n");
}

int input_validation(string key)
{
    int count = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        //if the character is not a alpha return 1
        if (!isalpha(key[i]))
        {
            return 1;
        }
        //for loop to check if a duplicate letter exists in the string already
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                return 1;
            }
        }
        count++;
    }

    //Ensures that the key is exactly 26 letters
    if (count != 26)
    {
        return 1;
    }
    return 0;

}

//Passed 18/18 tests and 100% on the styling