#ifndef _IMAGE_UTILS_
#define _IMAGE_UTILS_



const int XDIM = 10;
const int YDIM = 10;

unsigned char* ReadBMP();
int getPixel(unsigned char* image, int x, int y);
#endif
