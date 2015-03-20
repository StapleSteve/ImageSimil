#include "imageUtils.h"
#include <stdio.h>
#include <stdlib.h>


unsigned char* ReadBMP()
{
    FILE* f = fopen("Lenna.bmp", "rb");

    if(f == NULL)
        throw "Argument Exception";

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];


    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

    for(int i = 0; i < height; i++)
    {
        fread(data, sizeof(unsigned char), row_padded, f);
        for(int j = 0; j < width*3; j += 3)
        {
            // Convert (B, G, R) to (R, G, B)
            tmp = data[j];
            data[j] = data[j+2];
            data[j+2] = tmp;

        }
    }

    fclose(f);
    return data;
}

int getPixel(unsigned char* image, int x, int y)
{
	int toRet;
	toRet = image[(x*512)+y];
	return toRet;
}
