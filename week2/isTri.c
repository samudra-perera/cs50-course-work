#include <stdio.h>
#include <cs50.h>

bool isValid(float a, float b, float c);

int main(void)
{
    float a = get_float("Enter side a: \n");
    float b = get_float("Enter side b: \n");
    float c = get_float("Enter side c: \n");
    //Function call
    bool answer = isValid(a,b,c);
    printf(answer ? "true\n" : "false\n");
}

bool isValid(float a, float b, float c)
{
    // Check for all positive sides
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }

    // Check that sum of any two sides is greater than the third
    if((a + b <= c) || (b + c <= a) || (c + a <= b))
    {
        return false;
    }
    return true;
}


