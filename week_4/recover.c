#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

// Create a type BYTE = 8 bits
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    // The name file is argv[1]
    char *inputfile = argv[1];
    if (inputfile == NULL)
    {
        printf("Cannot open the file\n");
    }

    // Open the filename entred in the prompt
    FILE *inptr = fopen(inputfile, "r");

    // outpt is where the buffer will save
    FILE *outpt = NULL;

    // Create a buffer of 512 byte
    BYTE buffer[512];

    //inisialize the image count for the name of images
    int image_count = 0;

    //inisialize array of caracters for the filenmae ###.jpg/0
    char filename[8];

    while (true)
    {
        // Start buffering with 512 byte
        size_t fileRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        // Exit if nothing to buffer
        if (fileRead == 0)
        {
            break;
        }

        // JPEG signature, if true it's a JPEG file
        bool JEPGheader = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0;

        // if find a new JPEG file while stock, close the current file
        if (JEPGheader && outpt != NULL)
        {
            fclose(outpt);
            image_count++;
        }

        // Create a new file if header JPEG is found
        if (JEPGheader)
        {
            sprintf(filename, "%03i.jpg", image_count);
            outpt = fopen(filename, "w");
        }

        // Write if outpt is open
        if (outpt != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outpt);
        }
    }

    // Close outpt file
    fclose(outpt);

    //close inptr file
    fclose(inptr);

    return 0;
}
