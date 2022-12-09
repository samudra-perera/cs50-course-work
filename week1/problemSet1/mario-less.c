#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt the user for the height, height must be between 1 and 8
    int height;
    do
    {
        height = get_int("Please enter the height: ");
    } while (height < 1 || height > 8);
    for(int i = 0; i < height; i++)
    {
        //Printing the spaces, which is related as the height subtracted by the level
        for(int k = height - i; k > 1; k--)
        {
            printf(" ");
        }
        //The bricks are equal to the level printed
        for(int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//Passed 10/10 checks and 83% for styling..can improve the spacing of the for loops