#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    string name = get_string("What is your name?: ");
    printf("hello, %s\n", name);
}

//Passed all tests (4/4) + 100% on styling