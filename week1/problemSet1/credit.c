#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Card no: ");
    }
    while (card < 0);

    long workingCC = card;
    int sum1 = 0;
    int sum2 = 0;

    //All the digits not being multiplied by two ...
    while (workingCC > 0)
    {
        int lastDigit = workingCC % 10;
        sum1 += lastDigit;
        workingCC = workingCC / 100;
    }
    // All the digits that are multiplied by two ...

    workingCC = card/10;    //Divide by 10 to start to get every other number starting from the second last
    while (workingCC > 0)
    {
        int lastDigit = workingCC % 10;
        int timesTwo = lastDigit * 2;
        // The last (timeTwo % 10 will give the last digit of any 2 digit product and (timesTwo/10) will resturn the first digit of any integer (due to truncating the decimal))
        sum2 = sum2 + (timesTwo % 10) + (timesTwo/10);
        workingCC = workingCC / 100;
    }
    //Checks to see if the total of the two above sums = 0 as per Luhn algorithim
    int isZero = (sum1 + sum2) % 10;
    //Re init workingCC to be the card number and determine the length of the card
    workingCC = card;
    int counter = 0;
    while (workingCC != 0) {
        workingCC = workingCC / 10;
        counter++;
    }
    long divisor = 10;
    for(int i = 0; i < counter - 2; i++)
    {
        divisor*=10;
    }
    int firstDigit = card / divisor;
    int firstTwoDigits = card / (divisor / 10);

    if (isZero != 0)
    {
        printf("INVALID\n");
    }
    else if ((counter == 13 || counter == 16) && firstDigit == 4)
    {
        printf("VISA\n");
    }
    else if (counter == 16 && (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (counter == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

//Passed 15/15 tests and got 90% on the styling of the code