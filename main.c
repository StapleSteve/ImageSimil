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

int avgMatVal(int value, int avg)
{
	int toRet = abs(value - avg);
	return toRet;
}
 
int matrixAvgInt(int matrix[5][5])
{
	int matAvg;
	matAvg = 0;
	int m,n;
	for ( m = 0; m < 5; m++ )
	{
      for ( n = 0; n < 5; n++ )
      {
        matAvg = matAvg + matrix[m][n];
      }
	}
	matAvg = matAvg / 25;
	return matAvg;
}

float matrixAvgFlt(int matrix[5][5])
{
	float matAvg;
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

int main(int argc, char **argv)
{
	
	int matrixA [5][5] = {
		{1, 0, 64, 61, 5} ,
		{1, 0, 64, 61, 5} ,
		{1, 0, 64, 61, 5} ,
		{1, 0, 64, 61, 5} ,
		{1, 0, 64, 61, 5} ,

	};
	int avgMatA;
	avgMatA = 0;

	avgMatA = matrixAvgInt(matrixA);
	printf("Average of Matrix A is: %d\n", avgMatA);
	
	int avgMatB;
	avgMatB = 0;

	int matrixB[5][5] = {
		{avgMatVal(matrixA[0][0], avgMatA), avgMatVal(matrixA[1][0], avgMatA), avgMatVal(matrixA[2][0], avgMatA), avgMatVal(matrixA[3][0], avgMatA), avgMatVal(matrixA[4][0], avgMatA)} ,
		{avgMatVal(matrixA[0][1], avgMatA), avgMatVal(matrixA[1][1], avgMatA), avgMatVal(matrixA[2][1], avgMatA), avgMatVal(matrixA[3][1], avgMatA), avgMatVal(matrixA[4][1], avgMatA)} ,
		{avgMatVal(matrixA[0][2], avgMatA), avgMatVal(matrixA[1][2], avgMatA), avgMatVal(matrixA[2][2], avgMatA), avgMatVal(matrixA[3][2], avgMatA), avgMatVal(matrixA[4][2], avgMatA)} ,
		{avgMatVal(matrixA[0][3], avgMatA), avgMatVal(matrixA[1][3], avgMatA), avgMatVal(matrixA[2][3], avgMatA), avgMatVal(matrixA[3][3], avgMatA), avgMatVal(matrixA[4][3], avgMatA)} ,
		{avgMatVal(matrixA[0][4], avgMatA), avgMatVal(matrixA[1][4], avgMatA), avgMatVal(matrixA[2][4], avgMatA), avgMatVal(matrixA[3][4], avgMatA), avgMatVal(matrixA[4][4], avgMatA)}
	};

	avgMatB = matrixAvgInt(matrixB);
	printf("Average of Matrix B is: %d\n", avgMatB);
	
	printf("Float avg of A is: %f\n", matrixAvgFlt(matrixA));
	printf("Float avg of B is: %f\n", matrixAvgFlt(matrixB));
	
	
	return 0;
}
