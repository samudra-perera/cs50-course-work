#include <cs50.h>
#include <stdio.h>

int main(void){
    int points = get_int("How many points did you lose? ");

    if(points < 2)
    {
        printf("You lost else points than me. \n");
    }
    else if (points > 2)
    {
        printf("You lost more point than me. \n");
    }
    else
    {
        printf("We lost the same amount of points.\n");
    }
}