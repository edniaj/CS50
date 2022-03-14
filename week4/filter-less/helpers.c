#include "helpers.h"
#include <stdio.h>
#include <math.h>
// Convert image to grayscale
typedef uint8_t  BYTE;
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
            BYTE sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            BYTE sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            BYTE sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            image[i][j].rgbtBlue = sepiaRed;
            image[i][j].rgbtRed = sepiaGreen;
            image[i][j].rgbtGreen = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
