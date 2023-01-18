# CS50 - Course Work

This repository is to demonstrate and showcase the work I completed during CS50 2022 and CS50 2023. The purpose of taking cs50 was to gain a foundational grasp of programming concepts, learn new languages, and bridge gaps in knowledge from my bootcamp experience.

## Week 1 - C (2022)

#### What Did I learn?
- Learned about C 
- Learned about C syntax
- Learned about C data types, operators, conditionals, loops, CLI programs, and magic numbers
- Completed all the problems, easy and hard sets. 

#### Selected Problem

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

#### Selected Problem

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

#### Selected Problem

***runoff.c***
Runoff is a ranked choice voting system. It has the benefit to provide a winner that better reflect the voters’ preference. To make that work, each voter rank the candidates in a preference list. If any candidate has a majority of the first vote preference, that candidate is declared the winner. If no candidate has more than 50% of the votes, a runoff takes place where the candidate that recieved the least amount of votes is eliminated off the ballot. Anyone that selected the eliminated candidate as their first choice now get their second choice considered as their first. This process repeats itself till there is a winnner.

To see how this code was implemented please visit here [runoff.c](https://github.com/samudra-perera/cs50-course-work/blob/main/week3/pset3/runoff.c)

## Week 4 - Memory in C (2022)

#### What Did I learn?
- Pointers in C
- Defining custom types using structs
- File pointers in C
- Completed the lab and all the problems (easy and hard sets)

#### Selected Problem

***filter.c***
Filter is a program that takes in a bitmap file (.bmp) and applies a filter based on Command line arguments inputted from the user. The specific filter I want to showcase is the the edge detector filter which uses a [Sobel Operator](https://en.wikipedia.org/wiki/Sobel_operator). This operator essentially calculates the pixel intensity of each RGB value for each pixel and compares it with the X and Y surrounding pixels. To see how this was implemented in code please see below. 

```C
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Temp array to store the pixel information of the edges loop
    RGBTRIPLE temp[height][width];
    //For every pixel apply a similar algo to blue and compute the gx/gy matrixes and check if there is a large difference in that pixel
//gx and gy matrixes (Sobel operators) convulotional matrix
    int gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Initialize the values as 0 each loop
            float gx_red = 0;
            float gx_green = 0;
            float gx_blue = 0;
            float gy_red = 0;
            float gy_green = 0;
            float gy_blue = 0;

            for (int c = -1; c < 2; c++)
            {
                for (int r = -1; r < 2; r++)
                {
                    //These are pixels that are beyond the border and to be treated as black pixels aka (o valued)
                    if (i + c < 0 || i + c > height - 1 || j + r < 0 || j + r > width - 1)
                    {
                        gx_red += 0;
                        gx_blue += 0;
                        gx_green += 0;
                        gy_red += 0;
                        gy_blue += 0;
                        gy_green += 0;

                    }
                    else
                    {

                //In order to get the new channel value we have to do an sqrt(gx^2 + gy^2)
                        gx_red += gx[c + 1][r + 1] * image[i + c][j + r].rgbtRed;
                        gx_blue += gx[c + 1][r + 1] * image[i + c][j + r].rgbtBlue;
                        gx_green += gx[c + 1][r + 1] * image[i + c][j + r].rgbtGreen;
                        gy_red += gy[c + 1][r + 1] * image[i + c][j + r].rgbtRed;
                        gy_blue += gy[c + 1][r + 1] * image[i + c][j + r].rgbtBlue;
                        gy_green += gy[c + 1][r + 1] * image[i + c][j + r].rgbtGreen;
                    }
                }
            }
            int new_red = round(sqrt((gx_red * gx_red) + (gy_red * gy_red)));
            int new_blue = round(sqrt((gx_blue * gx_blue) + (gy_blue * gy_blue)));
            int new_green = round(sqrt((gx_green * gx_green) + (gy_green * gy_green)));


            temp[i][j].rgbtRed = new_red > 255 ? 255 : new_red;
            temp[i][j].rgbtBlue = new_blue > 255 ? 255 : new_blue;
            temp[i][j].rgbtGreen = new_green > 255 ? 255 : new_green;

        }
    }

        //Iterate through the temp array and set the the pixesl of original array to temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
```

## Week 5 - Data Structures in C (2022)

#### What Did I learn?
- Data Structures
- Singly and Doubly Linked Lists
- Hash Tables
- Tries
- Queues and Stacks
- Completed the lab and all the problems

#### Selected Problem

***speller.c***
The purpose of speller is to take in text and parse the text for spelling errors. This is completed by using a dictionary of words and creating a hash table of the words. The text words are then compared with the the hashtable dictionary words. If the word from the text exists in the hash table then the word is spelt corrects and the function will move onto the next word. The function returns the amount of misspelled words and the words themselves. To see how this program was implement please click [here](https://github.com/samudra-perera/cs50-course-work/blob/main/week5/speller/dictionary.c)

## Week 6 - Python (2023)

#### What Did I learn?
- What is Python?
- Python Syntax
- Completed all python problems (including practice problems)

#### Selected Problem

***seven-day-average.py***
The purpose of seven-day-average.py is to track the live average of the COVID-19 virus. A request is sent to download covid-19 data from the NYTimes covid database. This data is then turned into a dictionary and then the data is parsed in order to compute the live 7-day average for all 52 states. For a detailed look on how this was accomplished please visit [here](https://github.com/samudra-perera/cs50-course-work/blob/main/week6/PracticeProblems/seven-day-average.py).
