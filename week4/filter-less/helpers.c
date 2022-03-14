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

            int sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            int sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            int sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;
            image[i][j].rgbtRed = (BYTE)sepiaRed;
            image[i][j].rgbtGreen = (BYTE)sepiaGreen;
            image[i][j].rgbtBlue = (BYTE)sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int middleIndex = width / 2; // 03 -> 03 , 12 | 04 -> 04, 13, 22
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= middleIndex; j++)
        {
            BYTE tempRed = image[i][width - 1 - j].rgbtRed;
            BYTE tempGreen = image[i][width - 1 - j].rgbtGreen;
            BYTE tempBlue = image[i][width - 1 - j].rgbtBlue;

            image[i][width - 1 - j].rgbtRed = image[i][j].rgbtRed;
            image[i][width - 1 - j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - 1 - j].rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = tempRed;
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
            int left = i - 1 < 0 ? 0 : i;
            int right = i + 1 == width ? width - 1 : i + 1;
            int bottom = j - 1 < 0 ? 0 : j;
            int top = j + 1 == height ? height - 1 : j + 1;
            int total = 0;
            for (int k = left; k <= right; k++)
            {
                for (int t = bottom; t <=top; t++)
                {
                    total += image[k][t].rgbtRed
                }
            }
            BYTE setValue = round(total/((left-right)*(top-bottom));
            clone[i][j] = setValue;
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
