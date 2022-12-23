#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg_color = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = avg_color;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half = width / 2;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half; j++)
        {
            //temp variable to store the temp pixel
            RGBTRIPLE temp[height][width];
            //Store the pixel left of the half
            temp[i][j] = image[i][j];
            //Set the pixel left of the half to the left right
            image[i][j] = image[i][width - (j + 1)];
            //Set that pixel to temp
            image[i][width - (j + 1)] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create the a temp array of the size height by width
    RGBTRIPLE temp[height][width];
    //Go to each pixel then create an 3x3 grid around the pixel in the center
        //edge cases are the corner pixels and the edges of the image
    //Average the RGB values in and set them to the temp image array
    //After going through the entire image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //For every pixel we need the average
            float red_avg = 0;
            float green_avg = 0;
            float blue_avg = 0;
            float counter = 0;  //This is to keep track of how many pixels we have iterated over
            for (int c = -1; c < 2; c++)
            {
                for (int r = -1; r < 2; r++)
                {
                    //If the pixel exists in negative height it cannot be or it exits outside of the image height
                    if (i + c < 0 || i + c > height - 1)
                    {
                        continue;
                    }

                    //Same as above for width
                    if (j + r < 0 || j + r > width - 1)
                    {
                        continue;
                    }
                    red_avg += image[i + c][j + r].rgbtRed;
                    green_avg += image[i + c][j + r].rgbtGreen;
                    blue_avg += image[i + c][j + r].rgbtBlue;
                    counter++;
                }
            }
            //Get the average then set the temp array to that pixel
            temp[i][j].rgbtRed = round(red_avg / counter);
            temp[i][j].rgbtGreen = round(green_avg / counter);
            temp[i][j].rgbtBlue = round(blue_avg / counter);
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

//Passed all 22 Checks and got 94% on the styling