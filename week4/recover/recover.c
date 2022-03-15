#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int checkBuffer(BYTE*);

int main(int argc, char *argv[]) // But you should ultimately find that the image contains 50 JPEGs.
{
    if (argc != 2)
        return 1;

    FILE *pReadFile = fopen(argv[1], "r");

    int BLOCK_SIZE = 512;
    char fileName[8];
    BYTE *buffer = malloc(sizeof(BYTE) * 512);

    int fileCount =-1;
    FILE *pWriteFile = fopen(fileName, "w");
    while (fread(buffer, 512, 1,pReadFile) == 1)
    {
        if (checkBuffer(buffer) == 1)
        {
            fileCount++;
            sprintf(fileName, "%0.3i.jpg", fileCount);
            pWriteFile = fopen(fileName, "w");
            fwrite(buffer, 512, 1, pWriteFile);
        }
        else if (fileCount >= 0)
        {
            fwrite(buffer, 512, 1, pWriteFile);
        }
    }


    fclose(pWriteFile);

    //
    free(buffer);

    // Moreover, rather than read my memory card’s bytes one at a time, you can read 512 of them at a time into a buffer for efficiency’s sake

    // That is, you need only look for those signatures in a block’s first four bytes.

    // . But the last byte of a JPEG might not fall at the very end of a block.
}

int checkBuffer(BYTE *bufferData)
{
    if (bufferData[0] == 0xff && bufferData[1] == 0xd8 && bufferData[2] == 0xff && (bufferData[3] & 0xf0)==0xe0 )
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
