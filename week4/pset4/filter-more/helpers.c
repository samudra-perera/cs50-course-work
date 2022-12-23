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
                    if (i + c < 0 || i + c > height - 1 || j + r > width - 1 || j + r < 0 )
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

// Detect edges
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

//Passed 23/23 test cases and got 95% on the styling