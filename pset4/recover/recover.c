#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;

    if (argc != 2)
    {
        printf("Usage ./recover image");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("file doesn't found\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    bool isFirstJpeg = true;
    bool foundJpeg = false;
    char filename[100];
    FILE *img;

    size_t  bytes_read;
    int nameCount = 0;
    while (true)
    {
        bytes_read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file);
        if (bytes_read == 0)
        {
            break;
        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            foundJpeg = true;
            if (isFirstJpeg)
            {
                isFirstJpeg = false;
            }
            else
            {
                fclose(img);

            }

            sprintf(filename, "%03i.jpg", nameCount);
            img = fopen(filename, "w");
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
            nameCount++;

        }
        else
        {
            if (foundJpeg)
            {
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
            }
        }


    }

    fclose(img);
    fclose(file);

    return 0;
}
