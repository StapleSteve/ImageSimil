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


void prntMatInt(int a[5][5]);
void prntMatDbl(double a[5][5]);
double avgMatVal(int value, double avg);
double matrixAvgFlt(int matrix[5][5]);
double matrixAvgFltIn(double matrix[5][5]);


int main(int argc, char **argv)
{
	srand(time(NULL));
	int matrixA [5][5] = {
		{rand() % 255, rand() % 255, rand() % 255, rand() % 255, rand() % 255} ,
		{rand() % 255, rand() % 255, rand() % 255, rand() % 255, rand() % 255} ,
		{rand() % 255, rand() % 255, rand() % 255, rand() % 255, rand() % 255} ,
		{rand() % 255, rand() % 255, rand() % 255, rand() % 255, rand() % 255} ,
		{rand() % 255, rand() % 255, rand() % 255, rand() % 255, rand() % 255} ,

	};
	
	//print matrixA using prntMatInt(int matrix[5][5])
	prntMatInt(matrixA);
	
	double avgMatA;
	avgMatA = matrixAvgFlt(matrixA);
	printf("Average of Matrix A is: %0.3f\n\n", avgMatA);
	
	double matrixB[5][5] = {
		{avgMatVal(matrixA[0][0], avgMatA), avgMatVal(matrixA[0][1], avgMatA), avgMatVal(matrixA[0][2], avgMatA), avgMatVal(matrixA[0][3], avgMatA), avgMatVal(matrixA[0][4], avgMatA)} ,
		{avgMatVal(matrixA[1][0], avgMatA), avgMatVal(matrixA[1][1], avgMatA), avgMatVal(matrixA[1][2], avgMatA), avgMatVal(matrixA[1][3], avgMatA), avgMatVal(matrixA[1][4], avgMatA)} ,
		{avgMatVal(matrixA[2][0], avgMatA), avgMatVal(matrixA[2][1], avgMatA), avgMatVal(matrixA[2][2], avgMatA), avgMatVal(matrixA[2][3], avgMatA), avgMatVal(matrixA[2][4], avgMatA)} ,
		{avgMatVal(matrixA[3][0], avgMatA), avgMatVal(matrixA[3][1], avgMatA), avgMatVal(matrixA[3][2], avgMatA), avgMatVal(matrixA[3][3], avgMatA), avgMatVal(matrixA[3][4], avgMatA)} ,
		{avgMatVal(matrixA[4][0], avgMatA), avgMatVal(matrixA[4][1], avgMatA), avgMatVal(matrixA[4][2], avgMatA), avgMatVal(matrixA[4][3], avgMatA), avgMatVal(matrixA[4][4], avgMatA)}
	};
	
	//print matrixB using prntMatDbl(double matrix[5][5])
	prntMatDbl(matrixB);
	
	double avgMatB;
	avgMatB = matrixAvgFltIn(matrixB);
	printf("Average of Matrix B is: %0.5f\n", avgMatB);
	
	return 0;
}

void prntMatInt(int a[5][5])
{
   int i, j;
   for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++)
         printf("%6i ", a[i][j]);
      printf("\n");
   }
   printf("\n");
}

void prntMatDbl(double a[5][5])
{
   int i, j;
   for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++)
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

double matrixAvgFlt(int matrix[5][5])
{
	double matAvg;
	matAvg = 0.0;
	int m,n;
	for ( m = 0; m < 5; m++ )
	{
      for ( n = 0; n < 5; n++ )
      {
        matAvg = matAvg + matrix[m][n];
      }
	}
	matAvg = matAvg / 25.0;
	return matAvg;
}

double matrixAvgFltIn(double matrix[5][5])
{
	double matAvg;
	matAvg = 0.0;
	int m,n;
	for ( m = 0; m < 5; m++ )
	{
      for ( n = 0; n < 5; n++ )
      {
        matAvg = matAvg + matrix[m][n];
      }
	}
	matAvg = matAvg / 25.0;
	return matAvg;
}
