#include "helpers.h"
#include "math.h"
#include <stdbool.h>
#include  <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int  num = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = num;
            image[i][j].rgbtBlue = num;
            image[i][j].rgbtGreen = num;
        }
    }
    return;
}

int cap(int value)
{
    return value > 255 ? 255 : value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int originalRed = pixel.rgbtRed;
            int originalBlue = pixel.rgbtBlue;
            int originalGreen = pixel.rgbtGreen;

            image[i][j].rgbtRed = cap(round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue));
            image[i][j].rgbtGreen = cap(round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue));
            image[i][j].rgbtBlue = cap(round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;

        }
    }
}
bool isInside(i, j, height, width)
{
    return 0 <= i && i < height && 0 <= j && j < width;
}

RGBTRIPLE foundAvarage(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE avarage;
    int red, green, blue;
    red = green = blue = 0;
    avarage.rgbtRed = 0;
    avarage.rgbtGreen = 0;
    avarage.rgbtBlue = 0;


    int count = 0;
    for (int k = -1; k < 2; k++)
    {
        for (int l = -1; l < 2; l++)
        {
            if (isInside(i + k, j + l, height, width))
            {
                count++;
                RGBTRIPLE pixel = image[i + k][j + l];
                red += pixel.rgbtRed;
                green += pixel.rgbtGreen;
                blue += pixel.rgbtBlue;
                // printf("%d \n", red);
            }
        }

    }
    // printf("Avarege %lf\n", round( (float) red/count));
    avarage.rgbtRed = round((float) red / count);
    avarage.rgbtGreen = round((float) green / count);
    avarage.rgbtBlue = round((float) blue / count);

    return avarage;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageCopy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imageCopy[i][j] = foundAvarage(i, j, height, width, image);

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imageCopy[i][j];
        }
    }
    return;
}
