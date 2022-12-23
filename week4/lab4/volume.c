// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);   //atof converts string to a floating point number

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];    //unsigned int (only positive values)
    // fread(header, HEADER_SIZE, 1, input);
    // fwrite(header, HEADER_SIZE, 1, output);
    //Above can also be written like
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);


    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer; //Signed int (positive and negative values) the size of buffer is 2 bytes aka 16bits
    while(fread(&buffer, sizeof(int16_t), 1, input))
    {
        //Update Volume
        buffer *= factor;   //The buffer contains the bytes we want to modify
        fwrite(&buffer, sizeof(int16_t), 1, output)
    }



    // Close files
    fclose(input);
    fclose(output);
}
