/*
 * main.cpp
 * 
 * Part of the Open Source Project "ImageSimil"
 * 
 * Copyright 2015 Scotty Vance <vance.scotty@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include "holdTheThings.h"

void prntMatInt(int matrixI[YDIM][XDIM]);
void prntMatDbl(double matrixD[YDIM][XDIM]);
double avgMatVal(int value, double avg);
double matrixAvgDbl(int matrix[YDIM][XDIM]);
double matrixAvgDblIn(double matrix[YDIM][XDIM]);
double avgDeviation(double avg);
int readImagePixel(int currentX, int currentY);
int populatePixel(int currentX, int currentY);

//REMEMBER THAT THE Y VALUE IS BEFORE THE X

int main(int argc, char **argv)
{
	const int M = XDIM;  //reads the width of the image from holdTheThings.h const int XDIM
	const int N = YDIM;  //reads the height of the image from holdTheThings.h const int YDIM
	int a,b;  //these ints are used in the various for blocks
	
	int matrixA [N][M];  //define a NxM matrix, with values of type int
	
	for(a=0;a<N;a++)
	{
		for(b=0;b<M;b++)
		{
			matrixA[a][b] = populatePixel(b,a);  //using the function populatePixel(int currentX, int currentY), the a,bth value of matrixA is assigned
		}
	}
	
	prntMatInt(matrixA); //print matrixA using prntMatInt(int matrix[YDIM][XDIM])
	
	double avgMatA;
	avgMatA = matrixAvgDbl(matrixA);  //finds the average value of matrixA
	printf("Average of Matrix A is: %0.3f\n\n", avgMatA); //prints the above average to 3 decimal places
	
	double matrixB [N][M]; //defines a NxM matrix with values of type double
	
	//the following block populates matrixB with the distance between the corresponding matrixA value and the average of matrixA
	for(a=0;a<N;a++)  //columns
	{
		for(b=0;b<M;b++)  //rows
		{
			matrixB[a][b] = avgMatVal(matrixA[a][b], avgMatA);
		}
	}
	
	prntMatDbl(matrixB);  //print matrixB using prntMatDbl(double matrix[YDIM][XDIM])
	
	double avgMatB;
	avgMatB = matrixAvgDblIn(matrixB);  //finds the average value of matrixB
	printf("Average of Matrix B is: %0.5f\n", avgMatB); //prints out the average of matrixB
	printf("The average of Matrix B is %0.5f off of the overall average\n", avgDeviation(avgMatB)); //prints out how far the average of matrixB is from the observed average deviancy, details below
	
	return 0;
}

void prntMatInt(int matrixI[YDIM][XDIM])
{
   int i, j;
   for (i = 0; i < YDIM; i++) {
      for (j = 0; j < XDIM; j++)
         printf("%4i ", matrixI[i][j]);  
      printf("\n");
   }
   printf("\n");
}

//these two functions differ in how the i,jth value in the given matrix is printed
//the above uses "%4i", because matrixI[i][j] is an int, the below uses "%4.2f", because matrixD[i][j] is a double

void prntMatDbl(double matrixD[YDIM][XDIM])
{
   int i, j;
   for (i = 0; i < YDIM; i++) {
      for (j = 0; j < XDIM; j++)
         printf("%4.2f  ", matrixD[i][j]);  //the "%4.2f" formats matrixD[i][j] as a 4 digit double with 2 decimal places
      printf("\n");
   }
   printf("\n");
}

double avgMatVal(int value, double avg)
{
	double toRet = fabs(value - avg);
	return toRet;
}

double matrixAvgDbl(int matrix[YDIM][XDIM])
{
	double matAvg;
	matAvg = 0.0;
	int a,b;
	for ( a = 0; a < YDIM; a++ )
	{
      for ( b = 0; b < XDIM; b++ )
      {
        matAvg = matAvg + matrix[a][b];
      }
	}
	matAvg = matAvg / (XDIM * YDIM);
	return matAvg;
}

double matrixAvgDblIn(double matrix[YDIM][XDIM])
{
	double matAvg;
	matAvg = 0.0;
	int a,b;
	for ( a = 0; a < YDIM; a++ )
	{
      for ( b = 0; b < XDIM; b++ )
      {
        matAvg = matAvg + matrix[a][b];
      }
	}
	matAvg = matAvg / (XDIM * YDIM);
	return matAvg;
}

double avgDeviation(double avg)
{
	double stdAvg;
	stdAvg = 63.75;  //observed as the approximate deviation of the average of the modified matrices when MatrixA was filled with random values
	return fabs(stdAvg - avg);
}

int readImagePixel(int currentX, int currentY) //reads the (x,y) pixel from the image by averaging the RGB values, making a grayscale pixel value
{
	int i,j;
	i = 10;
	j = (white_bmp[LENGTH - (i*currentY + (12-currentY)) + 3 * currentX - 3 * currentY] + white_bmp[LENGTH - (i*currentY + (11-currentY)) + 3 * currentX - 3 * currentY] + white_bmp[LENGTH - (i*currentY + (10-currentY)) + 3 * currentX - 3 * currentY])/3;
	//honestly cannot remember how I made the above algorithm.  It works for 3x3, 4x4, and 5x5 images for certain
	
	//j = (white_bmp[LENGTH - (i*currentY + (12-currentY)) + 3 * currentX - 3 * currentY] + white_bmp[LENGTH - (i*currentY + (11-currentY)) + 3 * currentX - 3 * currentY] + white_bmp[LENGTH - (i*currentY + (10-currentY)) + 3 * currentX - 3 * currentY])/3;
	//preserve the above line as the orginal algorithm
	
	return j;
}

int populatePixel(int currentX, int currentY)  //reads the pixel (currentX, currentY) from the image
{
	int i;
	i = readImagePixel(currentX, currentY);
	return i;
}
