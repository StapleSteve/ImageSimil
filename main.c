/*
 * main.c
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
#include "pixelMatrix.h"

void prntMatInt(int a[YDIM][XDIM]);
void prntMatDbl(double a[YDIM][XDIM]);
double avgMatVal(int value, double avg);
double matrixAvgFlt(int matrix[YDIM][XDIM]);
double matrixAvgFltIn(double matrix[YDIM][XDIM]);
double avgDeviation(double avg);


int main(int argc, char **argv)
{
	srand(time(NULL));
	
	const int N = YDIM;
	const int M = XDIM;
	int a,b;
	
	int matrixA [N][M];
	for(a=0;a<N;a++)
	{
		for(b=0;b<M;b++)
		{
			matrixA[a][b] = rand() % 255;
		}
	}
	//print matrixA using prntMatInt(int matrix[YDIM][XDIM])
	prntMatInt(matrixA);
	
	double avgMatA;
	avgMatA = matrixAvgFlt(matrixA);
	printf("Average of Matrix A is: %0.3f\n\n", avgMatA);
	
	double matrixB [N][M];
	for(a=0;a<N;a++)
	{
		for(b=0;b<M;b++)
		{
			matrixB[a][b] = avgMatVal(matrixA[a][b], avgMatA);
		}
	}
	
	
	//print matrixB using prntMatDbl(double matrix[YDIM][XDIM])
	prntMatDbl(matrixB);
	
	double avgMatB;
	avgMatB = matrixAvgFltIn(matrixB);
	printf("Average of Matrix B is: %0.5f\n", avgMatB);
	
	printf("The average of Matrix B is %0.5f off of the overall average", avgDeviation(avgMatB));
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

void prntMatDbl(double a[YDIM][XDIM])
{
   int i, j;
   for (i = 0; i < YDIM; i++) {
      for (j = 0; j < XDIM; j++)
         printf("%6.2f  ", a[i][j]);
      printf("\n");
   }
   printf("\n");
}

double avgMatVal(int value, double avg)
{
	double toRet = fabs(value - avg);
	return toRet;
}

double matrixAvgFlt(int matrix[YDIM][XDIM])
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

double matrixAvgFltIn(double matrix[YDIM][XDIM])
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
	stdAvg = 60.0;  //this is preliminary, but all signs point to 60 beind the average average value of matrixB
	return fabs(stdAvg - avg);
}
	
