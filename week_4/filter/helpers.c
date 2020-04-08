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
    // Create a image to work with
    RGBTRIPLE blurImage[height][width];

    float blue, red, green;
    float count;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Inistialize values
            blue = red = green = count = 0;

            // Value existe in image[height] [width]
            if (i >= 0 && j >= 0)
            {
                blue += image[i][j].rgbtBlue;
                green += image[i][j].rgbtGreen;
                red += image[i][j].rgbtRed;
                count++;
            }

            // Previous value in same row if exist
            if (i >= 0 && j - 1 >= 0)
            {
                blue += image[i][j-1].rgbtBlue;
                green += image[i][j-1].rgbtGreen;
                red += image[i][j-1].rgbtRed;
                count++;
            }

            // Next value in same row if exist
            if (i >= 0 && j + 1 < width)
            {
                blue += image[i][j+1].rgbtBlue;
                green += image[i][j+1].rgbtGreen;
                red += image[i][j+1].rgbtRed;
                count++;
            }

            // Same couloumn and previous row if exist
            if (i - 1 >= 0 && j >= 0)
            {
                blue += image[i-1][j].rgbtBlue;
                green += image[i-1][j].rgbtGreen;
                red += image[i-1][j].rgbtRed;
                count++;
            }

            //..
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                blue += image[i-1][j-1].rgbtBlue;
                green += image[i-1][j-1].rgbtGreen;
                red += image[i-1][j-1].rgbtRed;
                count++;
            }

            //..
            if (i - 1 >= 0 && j + 1 < width)
            {
                blue += image[i-1][j+1].rgbtBlue;
                green += image[i-1][j+1].rgbtGreen;
                red += image[i-1][j+1].rgbtRed;
                count++;
            }

            //..
            if (i + 1 < height && j >= 0)
            {
                blue += image[i+1][j].rgbtBlue;
                green += image[i+1][j].rgbtGreen;
                red += image[i+1][j].rgbtRed;
                count++;
            }

            //..
            if (i + 1 < height && j - 1 >= 0)
            {
                blue += image[i+1][j-1].rgbtBlue;
                green += image[i+1][j-1].rgbtGreen;
                red += image[i+1][j-1].rgbtRed;
                count++;
            }

            //..
            if (i + 1 < height && j + 1 < width)
            {
                blue += image[i+1][j+1].rgbtBlue;
                green += image[i+1][j+1].rgbtGreen;
                red += image[i+1][j+1].rgbtRed;
                count++;
            }

            // Calculate the averge value of each color
            blurImage[i][j].rgbtBlue = round(blue / count);
            blurImage[i][j].rgbtGreen = round(green / count);
            blurImage[i][j].rgbtRed = round(red / count);
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
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
