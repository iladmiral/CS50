#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avergeRGB;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the averge value of (RED, GREEN, BLUE) for each pixel
            avergeRGB = ((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3;
            if (avergeRGB - (int)avergeRGB >= 0.5)
            {
                avergeRGB++;
            }

            // Set the averge value to all the pixels
            image[i][j].rgbtBlue = (int)avergeRGB;
            image[i][j].rgbtGreen = (int)avergeRGB;
            image[i][j].rgbtRed = (int)avergeRGB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a RGBTRIPLE temp to hold the sweped pixels
    RGBTRIPLE temp[height][width];

    // Calculate the midel of height
    int mid = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            // swep the raw image[0] with image[height-1] and so on ..
            temp[i][j] = image[i][j+0];
            image[i][j+0] = image[i][width-1-j];
            image[i][width-1-j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avergeBlue = 0;
    int avergeGreen = 0;
    int avergeRed = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ( i > 0 && i < height - 1 && j > 0 && j < width - 1)
            {
                for (int m = -1; m < 2; m++)
                {
                    for (int n = -1; n < 2; n++)
                    {
                       avergeBlue += image[i+m][j+n].rgbtBlue / 9;
                       avergeGreen += image[i+m][j+n].rgbtGreen / 9;
                       avergeRed += image[i+m][j+n].rgbtRed / 9;
                    }
                }
            }

            image[i][j].rgbtBlue = avergeBlue;
            image[i][j].rgbtGreen = avergeGreen;
            image[i][j].rgbtRed = avergeRed;

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
