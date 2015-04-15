/*
 * main.cpp
 * 
 * Copyright 2015 Scotty Vance <svance@rogue>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
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
#include <time.h>
#include "bmp.h"

void prntMatInt(int a[YDIM][XDIM]);
void prntMatDbl(double a[YDIM][XDIM]);
double avgMatVal(int value, double avg);
double matrixAvgDbl(int matrix[YDIM][XDIM]);
double matrixAvgDblIn(double matrix[YDIM][XDIM]);
double avgDeviation(double avg);
int readImagePixel(int currentX, int currentY);
int populatePixel(int currentX, int currentY);

int main(int argc, char **argv)
{
	srand(time(NULL));  //generates a seed for the random values to be based off of
	const int N = XDIM;  //reads the width of the image from bmp.h const int XDIM
	const int M = YDIM;  //reads the height of the image from bmp.h const int YDIM
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
	printf("Average of Matrix A is: %0.3f\n\n", avgMatA); //guess what, it prints the average to 3 decimal places
	
	double matrixB [N][M]; //defines a NxM matrix with values of type double
	
	//the following block populates matrixB with the distance between the corresponding matrixA value and the average of matrixA
	for(a=0;a<N;a++) //pretty sure that this one does the rows
	{
		for(b=0;b<M;b++)  //and this one the columns 
		{
			matrixB[a][b] = avgMatVal(matrixA[a][b], avgMatA);
		}
	}
	
	prntMatDbl(matrixB);  //print matrixB using prntMatDbl(double matrix[YDIM][XDIM])
	
	double avgMatB;
	avgMatB = matrixAvgDblIn(matrixB);
	printf("Average of Matrix B is: %0.5f\n", avgMatB); //prints out the average of matrixB
	printf("The average of Matrix B is %0.5f off of the overall average\n", avgDeviation(avgMatB)); //prints out how far the average of matrixB is from the observed average deviancy
	
	return 0;
}

void prntMatInt(int a[YDIM][XDIM])
{
   int i, j;
   for (i = 0; i < YDIM; i++) {
      for (j = 0; j < XDIM; j++)
         printf("%6i ", a[i][j]);  
      printf("\n");
   }
   printf("\n");
}

//these two functions differ in how the i,jth value in the matrix "a" is printed
//the above uses "%6i", because a[i][j] is an int, the below uses "%6.2f", because a[i][j] is a float

void prntMatDbl(double a[YDIM][XDIM])
{
   int i, j;
   for (i = 0; i < YDIM; i++) {
      for (j = 0; j < XDIM; j++)
         printf("%6.2f  ", a[i][j]);  //the "%6.2f" formats a[i][j] as a 6 digit float with 2 decimal places
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
	int m,n;
	for ( m = 0; m < YDIM; m++ )
	{
      for ( n = 0; n < XDIM; n++ )
      {
        matAvg = matAvg + matrix[m][n];
      }
	}
	matAvg = matAvg / (XDIM * YDIM);
	return matAvg;
}

double matrixAvgDblIn(double matrix[YDIM][XDIM])
{
	double matAvg;
	matAvg = 0.0;
	int m,n;
	for ( m = 0; m < YDIM; m++ )
	{
      for ( n = 0; n < XDIM; n++ )
      {
        matAvg = matAvg + matrix[m][n];
      }
	}
	matAvg = matAvg / (XDIM * YDIM);
	return matAvg;
}

double avgDeviation(double avg)
{
	double stdAvg;
	stdAvg = 63.75;  //observed as the approximate deviation of the average of the modified matrices (matrixB above)
	return fabs(stdAvg - avg);
}

int readImagePixel(int currentX, int currentY) //literally just returns a random int from 0..255 inclusive
{
	int j;
	j = rand() % 255;
	return j;
}
//the above is currently a placeholder for the future implementation of actually using images

int populatePixel(int currentX, int currentY)  //reads the pixel (currentX, currentY) from the image
{
	int i;
	i = readImagePixel(currentX, currentY);
	return i;
}
