#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]) // But you should ultimately find that the image contains 50 JPEGs.
{
    if (argc != 2)
        return 1;

    FILE *file = fopen(argv[1], "r");

    // while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    // {
    // }
    char* filename = NULL;
    sprintf(filename, "%03i.jpg", 2);
    // 


    // Moreover, rather than read my memory card’s bytes one at a time, you can read 512 of them at a time into a buffer for efficiency’s sake

    // That is, you need only look for those signatures in a block’s first four bytes.

    // . But the last byte of a JPEG might not fall at the very end of a block.
}

// rm -f *.jpg to remove all the jpg

//check50 cs50/problems/2022/x/recover
