#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
void checkBuffer(BYTE bufferData);

int main(int argc, char *argv[]) // But you should ultimately find that the image contains 50 JPEGs.
{
    if (argc != 2)
        return 1;

    FILE *file = fopen(argv[1], "r");

    int BLOCK_SIZE = 512;
    char* fileName = malloc(20);
    BYTE *buffer = malloc(sizeof(BYTE) * 512);

    int fileCount =1;
    int writingData = 0;
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (checkBuffer(buffer) )
        {
            writingData =1;
        }


        //Lets check it its a jpeg
            //If it is a jpeg, lets continue writing it until there is slack at the back
            // Let's allow next loop to know we are still writing on a jpeg
        // New file. No header data but we know its a jpeg since previous data has header data

        if(buffer[511] == 0)
        {
            fileCount++;
            sprintf(fileName, "%0.3i.jpeg", fileCount);
        }

    }


    //
    free(buffer);
    free(filename)

    // Moreover, rather than read my memory card’s bytes one at a time, you can read 512 of them at a time into a buffer for efficiency’s sake

    // That is, you need only look for those signatures in a block’s first four bytes.

    // . But the last byte of a JPEG might not fall at the very end of a block.
}

void checkBuffer(BYTE bufferData)
{
    if (bufferData[0] == 0xff && bufferData[1] == 0xd8 && buffer[2] == 0xff && (bufferData[3] & 0xf0)==0xe0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// rm -f *.jpg to remove all the jpg

//check50 cs50/problems/2022/x/recover
