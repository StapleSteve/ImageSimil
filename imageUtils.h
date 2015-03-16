#ifndef _IMAGE_UTILS_
#define _IMAGE_UTILS_

typedef struct __attribute__((__packed__)) {
    unsigned char fileMarker1;
    unsigned char fileMarker2;
    unsigned short unused1;
    unsigned short unused2;
    unsigned int   bfSize;
    unsigned int   imageDataOffset;
} FILEHEADER;

typedef struct __attribute__((__packed__)) {
    unsigned int   biSize;
    int            width;
    int            height;
    unsigned int planes;
    unsigned int bitPix;
    unsigned int   biCompression;
    unsigned int   biSizeImage;
    int            biXPelsPerMeter;
    int            biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
} INFOHEADER;

typedef struct __attribute__((__packed__)) {
    unsigned char  b;
    unsigned char  g;
    unsigned char  r;
} IMAGE;

const int XDIM = 10;
const int YDIM = 10;


#endif
