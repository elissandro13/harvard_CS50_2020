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
    return;
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
            if (isInside i + k, j + l, height, width))
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

RGBTRIPLE defineEdges(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE results;
    int redY, greenY, blueY, redX, greenX, blueX;
    redX = greenX = blueX = redY = greenY = blueY = 0;
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };


    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };


    for (int k = -1; k < 2; k++)
    {
        for (int l = -1; l < 2; l++)
        {
            if (isInside(i + k, j + l, height, width))
            {
                RGBTRIPLE pixel = image[i + k][j + l];
                int row = k + 1;
                int col = l + 1;
                redY += Gy[row][col] * pixel.rgbtRed;
                greenY += Gy[row][col] * pixel.rgbtGreen;
                blueY += Gy[row][col] * pixel.rgbtBlue;

                redX += Gx[row][col] * pixel.rgbtRed;
                greenX += Gx[row][col] * pixel.rgbtGreen;
                blueX += Gx[row][col] * pixel.rgbtBlue;
            }
        }

    }
    results.rgbtRed = cap(round(sqrt(redX * redX + redY * redY)));
    results.rgbtGreen = cap(round(sqrt(greenX * greenX + greenY * greenY)));
    results.rgbtBlue = cap(round(sqrt(blueX * blueX + blueY * blueY)));

    return results;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageCopy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imageCopy[i][j] = defineEdges(i, j, height, width, image);

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
