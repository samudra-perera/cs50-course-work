#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    //Check Usage
    if (argc != 2)
    {
        printf("Usage: ./recover Image\n");
        return 1;
    }

    //Open the file
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file)
    {
        printf("Could not open the file\n");
        return 1;
    }

    //Set outfile to NULL
    FILE* output_file = NULL;

    // Creating the buffer amount for 512bytes
    BYTE bytes[512];

    //Jpg file name for strings to be printed to sprintf will use this
    char filename[8];

    //To count the amount of images
    int counter = 0;

    //Read the memory until the end of the file
    while(fread(bytes, sizeof(bytes), 1, input_file) == 1)
    {
        //Check if the file is a JPEG
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            //If the current outptr has an existing file open, close the existing file
            if (output_file != NULL)
            {
                fclose(output_file);
            }
            //Make name for the iamge file and set filename string as the image name
            sprintf(filename, "%03d.jpg", counter++);

            //Open a file called ###.jpg and open it for writing
            output_file = fopen(filename, "w");
            if (!output_file)
            {
                printf("Could not create an image\n");
                return 0;
            }
        }

        //If the outptr is a valid file .jpg write into the file
        if (output_file != NULL)
        {
            //Write into image file with the input file bytes
            fwrite(bytes, sizeof(bytes), 1, output_file);
        }
    }
        //Close input image
        fclose(input_file);
        //Close Output image for the last image when the while loop ends
        fclose(output_file);
    return 0;
}

//Passed 7/7 tests and got a styling score of 90%