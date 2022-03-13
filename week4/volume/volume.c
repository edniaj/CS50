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
    FILE *input = fopen(argv[1], "r"); // input is a pointer, Dereference it with *
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    FILE *output = fopen(argv[2], "w"); // this pointer will be used to write,
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *append = fopen(argv[2], "a"); // this pointer will be used to write,
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    float factor = atof(argv[3]); // We will use this value to multiply

    // TODO: Copy header from input file to output file
    uint8_t *headerData = malloc(44);
    fread(headerData, 1, 44, input);
    fwrite(headerData, 1, 44, output);
    free(headerData);
    //Unsure how much data to allocate
    int16_t placeHolder;

    // while(fread(&placeHolder, 2, 1, input))
    // {
    //     printf()
    // }

    while(fread(&placeHolder, 2, 1, input))
    {
        placeHolder = placeHolder * factor;
        fwrite(&placeHolder, 2, 1, output);
    }


    // Close files
    fclose(input);
    fclose(append);
    fclose(output);
}

// uint16_t -> Represents 2 byte

// 1. WAV files begin with a 44-byte “header” that contains information about the file itself, including the size of the file, the number of samples per second, and the size of each sample.
// 2. After header WAV file contains a sequence of samples, each a single 2-byte (16-bit) integer representing the audio signal at a particular point in time.
//

// uint8_t is a type that stores an 8-bit unsigned integer. ->  each byte of a WAV file’s header as a uint8_t value.
//  int16_t is a type that stores a 16-bit signed integer. ->  each sample of audio in a WAV file as an int16_t value.