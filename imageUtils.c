#include "imageUtils.h"
#include <stdio.h>
#include <stdlib.h>

const int XDIM = 512;
const int YDIM = 512;

int width(int image)
{
	return image;
}

int height(int image)
{
	return image;
}

void printToCSV(int image)
{
	printf("Boop %d\n", image);
}

void renderFromCSV(int csv)
{
	printf("Beep %d\n", csv);
}
