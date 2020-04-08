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
    RGBTRIPLE blurImage[height][width];
    int sumBlue;
    int sumGreen;
    int sumRed;
    float avergeBlue, avergeRed, avergeGreen;
    int m, n;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i != 0 && j != width - 1 && i != height - 1 && j != 0)
            {
                sumRed = 0; sumGreen = 0; sumBlue = 0;
                for (m = -1; m < 2; m++)
                {
                    for (n = -1; n < 2; n++)
                    {
                       sumBlue += image[i+m][j+n].rgbtBlue;
                       sumGreen += image[i+m][j+n].rgbtGreen;
                       sumRed += image[i+m][j+n].rgbtRed;
                    }
                }
            avergeBlue = (float)sumBlue/9;
            avergeRed = (float)sumRed/9;
            avergeGreen = (float)sumGreen/9;

            blurImage[i][j].rgbtBlue = round(avergeBlue);
            blurImage[i][j].rgbtGreen = round(avergeGreen);
            blurImage[i][j].rgbtRed = round(avergeRed);
            }

            if (i == 0 && j != 0 && j != width - 1)
            {
                sumRed = 0; sumGreen = 0; sumBlue = 0;
                for (m = 0; m < 2; m++)
                {
                    for (n = -1; n < 2; n++)
                    {
                       sumBlue += image[i+m][j+n].rgbtBlue;
                       sumGreen += image[i+m][j+n].rgbtGreen;
                       sumRed += image[i+m][j+n].rgbtRed;
                    }
                }
                avergeBlue = (float)sumBlue/6;
                avergeRed = (float)sumRed/6;
                avergeGreen = (float)sumGreen/6;

                blurImage[i][j].rgbtBlue = round(avergeBlue);
                blurImage[i][j].rgbtGreen = round(avergeGreen);
                blurImage[i][j].rgbtRed = round(avergeRed);
            }

            if (i == height - 1 && j != 0 && j != width - 1)
            {
                sumRed = 0; sumGreen = 0; sumBlue = 0;
                for (m = -1; m < 1; m++)
                {
                    for (n = -1; n < 2; n++)
                    {
                       sumBlue += image[i+m][j+n].rgbtBlue;
                       sumGreen += image[i+m][j+n].rgbtGreen;
                       sumRed += image[i+m][j+n].rgbtRed;
                    }
                }
                avergeBlue = (float)sumBlue/6;
                avergeRed = (float)sumRed/6;
                avergeGreen = (float)sumGreen/6;

                blurImage[i][j].rgbtBlue = round(avergeBlue);
                blurImage[i][j].rgbtGreen = round(avergeGreen);
                blurImage[i][j].rgbtRed = round(avergeRed);
            }

            if (j == 0 && i != 0 && i != height - 1)
            {
                sumRed = 0; sumGreen = 0; sumBlue = 0;
                for (m = -1; m < 2; m++)
                {
                    for (n = 0; n < 2; n++)
                    {
                       sumBlue += image[i+m][j+n].rgbtBlue;
                       sumGreen += image[i+m][j+n].rgbtGreen;
                       sumRed += image[i+m][j+n].rgbtRed;
                    }
                }
                avergeBlue = (float)sumBlue/6;
                avergeRed = (float)sumRed/6;
                avergeGreen = (float)sumGreen/6;

                blurImage[i][j].rgbtBlue = round(avergeBlue);
                blurImage[i][j].rgbtGreen = round(avergeGreen);
                blurImage[i][j].rgbtRed = round(avergeRed);
            }

            if (j == width - 1 && i != 0 && i != height - 1)
            {
                sumRed = 0; sumGreen = 0; sumBlue = 0;
                for (m = -1; m < 2; m++)
                {
                    for (n = -1; n < 1; n++)
                    {
                       sumBlue += image[i+m][j+n].rgbtBlue;
                       sumGreen += image[i+m][j+n].rgbtGreen;
                       sumRed += image[i+m][j+n].rgbtRed;
                    }
                }
                avergeBlue = (float)sumBlue/6;
                avergeRed = (float)sumRed/6;
                avergeGreen = (float)sumGreen/6;

                blurImage[i][j].rgbtBlue = round(avergeBlue);
                blurImage[i][j].rgbtGreen = round(avergeGreen);
                blurImage[i][j].rgbtRed = round(avergeRed);
            }
            if (i == 0 && j == 0)
            {
                sumRed = 0; sumGreen = 0; sumBlue = 0;
                for (m = 0; m < 2; m++)
                {
                    for (n = 0; n < 2; n++)
                    {
                       sumBlue += image[i+m][j+n].rgbtBlue;
                       sumGreen += image[i+m][j+n].rgbtGreen;
                       sumRed += image[i+m][j+n].rgbtRed;
                    }
                }
                avergeBlue = (float)sumBlue/4;
                avergeRed = (float)sumRed/4;
                avergeGreen = (float)sumGreen/4;

                blurImage[i][j].rgbtBlue = round(avergeBlue);
                blurImage[i][j].rgbtGreen = round(avergeGreen);
                blurImage[i][j].rgbtRed = round(avergeRed);
            }

            if (i == height - 1 && j == 0)
            {
                sumRed = 0; sumGreen = 0; sumBlue = 0;
                for (m = -1; m < 1; m++)
                {
                    for (n = 0; n < 2; n++)
                    {
                       sumBlue += image[i+m][j+n].rgbtBlue;
                       sumGreen += image[i+m][j+n].rgbtGreen;
                       sumRed += image[i+m][j+n].rgbtRed;
                    }
                }
                avergeBlue = (float)sumBlue/4;
                avergeRed = (float)sumRed/4;
                avergeGreen = (float)sumGreen/4;

                blurImage[i][j].rgbtBlue = round(avergeBlue);
                blurImage[i][j].rgbtGreen = round(avergeGreen);
                blurImage[i][j].rgbtRed = round(avergeRed);
            }

            if (j == width -1  && i == 0)
            {
                sumRed = 0; sumGreen = 0; sumBlue = 0;
                for (m = 0; m < 2; m++)
                {
                    for (n = -1; n < 1; n++)
                    {
                       sumBlue += image[i+m][j+n].rgbtBlue;
                       sumGreen += image[i+m][j+n].rgbtGreen;
                       sumRed += image[i+m][j+n].rgbtRed;
                    }
                }
                avergeBlue = (float)sumBlue/4;
                avergeRed = (float)sumRed/4;
                avergeGreen = (float)sumGreen/4;

                blurImage[i][j].rgbtBlue = round(avergeBlue);
                blurImage[i][j].rgbtGreen = round(avergeGreen);
                blurImage[i][j].rgbtRed = round(avergeRed);
            }
            if (j == width -1  && i == height - 1)
            {
                sumRed = 0; sumGreen = 0; sumBlue = 0;
                for (m = -1; m < 1; m++)
                {
                    for (n = -1; n < 1; n++)
                    {
                       sumBlue += image[i+m][j+n].rgbtBlue;
                       sumGreen += image[i+m][j+n].rgbtGreen;
                       sumRed += image[i+m][j+n].rgbtRed;
                    }
                }
                avergeBlue = (float)sumBlue/4;
                avergeRed = (float)sumRed/4;
                avergeGreen = (float)sumGreen/4;

                blurImage[i][j].rgbtBlue = round(avergeBlue);
                blurImage[i][j].rgbtGreen = round(avergeGreen);
                blurImage[i][j].rgbtRed = round(avergeRed);
            }
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int h = 0; h < width; h++)
        {
          image[k][h] = blurImage[k][h];
        }
    }
    return;
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
