#include "helpers.h"
#include <stdio.h>
#include <math.h>
// Convert image to grayscale
typedef uint8_t BYTE;
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            uint8_t averageValue = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = averageValue;
            image[i][j].rgbtRed = averageValue;
            image[i][j].rgbtGreen = averageValue;
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
            BYTE originalRed = image[i][j].rgbtRed;
            BYTE originalGreen = image[i][j].rgbtGreen;
            BYTE originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;

            image[i][j].rgbtRed = (BYTE) (sepiaRed);
            image[i][j].rgbtGreen = (BYTE) (sepiaGreen);
            image[i][j].rgbtBlue = (BYTE) (sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //width = 3
    // height = 2
    int middleIndex;
    if (width%2 ==0 )
    {
        middleIndex = (width /2) -1;
    }
    else
    {
        middleIndex = width / 2; // -> 1
    }

    for (int i = 0; i < height; i++) //2
    {
        for (int j = 0; j <= middleIndex; j++) //3 -> 03, 12
        {
            BYTE tempRed = image[i][width - 1 - j].rgbtRed; //
            BYTE tempGreen = image[i][width - 1 - j].rgbtGreen; // [0][2-0]
            BYTE tempBlue = image[i][width - 1 - j].rgbtBlue; //

            image[i][width - 1 - j].rgbtRed = image[i][j].rgbtRed; // [0][2] = [0][0]
            image[i][width - 1 - j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - 1 - j].rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = tempRed; //[0][0] = [0][2]
            image[i][j].rgbtGreen = tempGreen;
            image[i][j].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE clone[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int left = i - 1 < 0 ? 0 : i-1;
            int right = i + 1 == width ? width - 1 : i + 1;
            int bottom = j - 1 < 0 ? 0 : j-1;
            int top = j + 1 == height ? height - 1 : j + 1;
            int tempRed = 0;
            int tempGreen = 0;
            int tempBlue = 0;
            for (int k = left; k <= right; k++)
            {
                for (int t = bottom; t <= top; t++)
                {
                    tempRed += image[k][t].rgbtRed;
                    tempGreen += image[k][t].rgbtGreen;
                    tempBlue += image[k][t].rgbtBlue;
                }
            }
            tempRed = round(   (tempRed) / ((right - left + 1) * (top - bottom + 1)) > 255 ? 255 : (tempRed) / ((right - left + 1) * (top - bottom + 1))  );
            tempGreen = round((tempGreen) / ((right - left + 1) * (top - bottom + 1))> 255 ? 255 :  (tempGreen) / ((right - left + 1) * (top - bottom + 1))  );
            tempBlue = round((tempBlue) / ((right - left + 1) * (top - bottom + 1))> 255 ? 255 : (tempBlue) / ((right - left + 1) * (top - bottom + 1))  );
            clone[i][j].rgbtRed = (BYTE) tempRed;
            clone[i][j].rgbtGreen =(BYTE)  tempGreen;
            clone[i][j].rgbtBlue =(BYTE)  tempBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = clone[i][j];
        }
    }
    return;
}
