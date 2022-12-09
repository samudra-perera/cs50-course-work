#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt the user for the height, height must be between 1 and 8
    int height;
    do
    {
        height = get_int("Please enter the height: ");
    }
    while (height < 1 || height > 8);

    for(int i = 0; i < height; i++)
    {
        //Printing the spaces, which is related as the height subtracted by the level
        for (int k = height - i; k > 1; k--)
        {
            printf(" ");
        }
        //The bricks are equal to the level printed
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //The space is constant, so print a constant two spaces every iteration
        for (int s = 0; s < 2; s++)
        {
            printf(" ");
        }
        //The final set of bricks is a repeart of the j loop
        for (int f = 0; f < i + 1; f++) {
            printf("#");
        }
        printf("\n");
    }
}

//10/10 tests passed and 93% on the styling portion...lost points for not having the final for loop braces on a different line