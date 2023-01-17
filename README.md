# CS50 - Course Work

This repository is to demonstrate and showcase the work I completed during CS50 2022 and CS50 2023. The purpose of taking cs50 was to gain a foundational grasp of programming concepts, learn new languages, and bridge gaps in knowledge from my bootcamp experience.

## Week 1 - C (2022)

#### What Did I learn?
- Learned about C 
- Learned about C syntax
- Learned about C data types, operators, conditionals, loops, CLI programs, and magic numbers
- Completed all the problems, easy and hard sets. 

#### Selected Problems

***Credit.c***
The purpose of this program was to act as a credit card validator. The program would take an input of a credit card # and would return whether it was VISA, MASTERCARD, AMEX or INVALID. The program utilized [Luhn algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm) as part of the determination method.  

```C
//All the digits not being multiplied by two ...
    while (workingCC > 0)
    {
        int lastDigit = workingCC % 10;
        sum1 += lastDigit;
        workingCC = workingCC / 100;
    }
    // All the digits that are multiplied by two ...

    workingCC = card/10;    //Divide by 10 to start to get every other number starting from the second to last
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
```

## Week 2 - Arrays in C (2022)

#### What Did I learn?
- Functions in C
- Variables and Scope
- Debugging in C. (Step Through and Step into techniques)
- Arrays (Static and Dynamic)
- Completed the lab and all the problems (easy and hard sets)

#### Selected Problems

***substitution.c***
The purpose of this program is be a user inputted cipher the same length as the alphabet. The cipher should on contain each letter of the alphabet once. An example input and output can be seen below.

```C
Cihper: JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
```

Below is how I completed the input validation for the cipher input. The function takes the key as a function parameter. We have a simple for loop iterating through every character of the cipher. If the character is not alpha char then return 1. To ensure that we have not seen the same character twice we use a nested for loop. The loop iterates from index i to the end of the string (at index j). If there is a duplicate, return and end the function. If there is a perfect cipher with count = 26 and no repeat letter return 0. 

```C
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
```

## Week 3 - Algorithms in C (2022)

#### What Did I learn?
- Search in C (Linear, Binary)
- Sort in C (Bubble, Selection, and Merge)
- Completed the lab and completed the easy problem (Tideman was too hard at the current moment)

#### Selected Problems

***runoff.c***
Runoff is a ranked choice voting system. It has the benefit to provide a winner that better reflect the voters’ preference. To make that work, each voter rank the candidates in a preference list. If any candidate has a majority of the first vote preference, that candidate is declared the winner. If no candidate has more than 50% of the votes, an instant runoff takes place where the candidate that recieved the least amount of votes is eliminated. 