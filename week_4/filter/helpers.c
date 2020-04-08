#include "helpers.h"
#include <math.h>

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

            // Set the averge value to all the pixels
            image[i][j].rgbtBlue = round(avergeRGB);
            image[i][j].rgbtGreen = round(avergeRGB);
            image[i][j].rgbtRed = round(avergeRGB);
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
            temp[i][j] = image[i][j + 0];
            image[i][j + 0] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp[i][j];
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
                blue += image[i][j - 1].rgbtBlue;
                green += image[i][j - 1].rgbtGreen;
                red += image[i][j - 1].rgbtRed;
                count++;
            }

            // Next value in same row if exist
            if (i >= 0 && j + 1 < width)
            {
                blue += image[i][j + 1].rgbtBlue;
                green += image[i][j + 1].rgbtGreen;
                red += image[i][j + 1].rgbtRed;
                count++;
            }

            // Same couloumn and previous row if exist
            if (i - 1 >= 0 && j >= 0)
            {
                blue += image[i - 1][j].rgbtBlue;
                green += image[i - 1][j].rgbtGreen;
                red += image[i - 1][j].rgbtRed;
                count++;
            }

            //..
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                blue += image[i - 1][j - 1].rgbtBlue;
                green += image[i - 1][j - 1].rgbtGreen;
                red += image[i - 1][j - 1].rgbtRed;
                count++;
            }

            //..
            if (i - 1 >= 0 && j + 1 < width)
            {
                blue += image[i - 1][j + 1].rgbtBlue;
                green += image[i - 1][j + 1].rgbtGreen;
                red += image[i - 1][j + 1].rgbtRed;
                count++;
            }

            //..
            if (i + 1 < height && j >= 0)
            {
                blue += image[i + 1][j].rgbtBlue;
                green += image[i + 1][j].rgbtGreen;
                red += image[i + 1][j].rgbtRed;
                count++;
            }

            //..
            if (i + 1 < height && j - 1 >= 0)
            {
                blue += image[i + 1][j - 1].rgbtBlue;
                green += image[i + 1][j - 1].rgbtGreen;
                red += image[i + 1][j - 1].rgbtRed;
                count++;
            }

            //..
            if (i + 1 < height && j + 1 < width)
            {
                blue += image[i + 1][j + 1].rgbtBlue;
                green += image[i + 1][j + 1].rgbtGreen;
                red += image[i + 1][j + 1].rgbtRed;
                count++;
            }

            // Calculate the averge value of each color
            blurImage[i][j].rgbtBlue = round(blue / count);
            blurImage[i][j].rgbtGreen = round(green / count);
            blurImage[i][j].rgbtRed = round(red / count);
        }
    }

    // Copying the pixels form blurImage to image
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
    // Create a copy image with extra border to work with
    RGBTRIPLE edgesImage[height + 2][width + 2];
    int i, j, m, n;
    float GxRed, GxBlue, GxGreen, GyRed, GyBlue, GyGreen;
    float resultBlue, resultGreen, resultRed;

    // Define Gx and Gy
    float Gx[3][3] = {{-1, 0, 1},
                      {-2, 0, 2},
                      {-1, 0, 1}};

    float Gy[3][3] = {{-1, -2, -1},
                      {0, 0, 0},
                      {1, 2, 1}};

    // Define maxValues for normalization
    float maxBlue = 0, maxRed = 0, maxGreen = 0;
    // Creating a copy of the image with an extra border of black layer
    for (i = 0; i < height + 2; i++)
    {
        for (j = 0; j < width + 2; j++)
        {
            if (i == 0 || j == 0 || i == height + 1 || j == width + 1)
            {
                edgesImage[i][j].rgbtBlue = 0;
                edgesImage[i][j].rgbtGreen = 0;
                edgesImage[i][j].rgbtRed = 0;
            }
            else
            {
                edgesImage[i][j] = image[i - 1][j - 1];
            }
        }
    }

    // Apply the sobel matrix to pixels
    for (i = 1; i < height + 1; i++)
    {
        for (j = 1; j < width + 1; j++)
        {
            GxRed = GxBlue = GxGreen = GyRed = GyBlue = GyGreen = 0;

            for (m = -1; m < 2; m++)
            {
                for (n = -1; n < 2; n++)
                {
                    // Image[][] * Gx[][]
                    GxBlue += edgesImage[i + m][j + n].rgbtBlue * Gx[m + 1][n + 1];
                    GxGreen += edgesImage[i + m][j + n].rgbtGreen * Gx[m + 1][n + 1];
                    GxRed += edgesImage[i + m][j + n].rgbtRed * Gx[m + 1][n + 1];

                    // Image[][] * Gy[][]
                    GyBlue += edgesImage[i + m][j + n].rgbtBlue * Gy[m + 1][n + 1];
                    GyGreen += edgesImage[i + m][j + n].rgbtGreen * Gy[m + 1][n + 1];
                    GyRed += edgesImage[i + m][j + n].rgbtRed * Gy[m + 1][n + 1];

                }
            }

            // Calculate square root of Gx² + Gy²
            resultBlue = round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue)));
            resultGreen = round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen)));
            resultRed = round(sqrt((GxRed * GxRed) + (GyRed * GyRed)));

            // Verify the value in 0 to 255
            if (resultBlue > 255)
            {
                resultBlue = 255;
            }
            if (resultGreen > 255)
            {
                resultGreen = 255;
            }
            if (resultRed > 255)
            {
                resultRed = 255;
            }
            // Set the new values to image[][]
            image[i - 1][j - 1].rgbtBlue = resultBlue;
            image[i - 1][j - 1].rgbtGreen = resultGreen;
            image[i - 1][j - 1].rgbtRed = resultRed;
        }
    }
    return;
}
