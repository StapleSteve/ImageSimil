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

int matrixAvg(int matrix[3][3])
{
	int matAvg;
	matAvg = 0;
	int m,n;
	for ( m = 0; m < 3; m++ )
	{
      for ( n = 0; n < 3; n++ )
      {
        matAvg = matAvg + matrix[m][n];
      }
	}
	matAvg = matAvg / 9;
	return matAvg;
}

int main(int argc, char **argv)
{
	
	int matrixA [3][3] = {
		{1, 0, 64} ,
		{54, 65, 121} ,
		{1, 6, 211}
	};
	int avgMatA;
	avgMatA = 0;

	avgMatA = matrixAvg(matrixA);
	printf("Average of Matrix A is: %d\n", avgMatA);
	
	int avgMatB;
	avgMatB = 0;
	int matrixB [3][3] = {
		{abs(matrixA[0][0] - avgMatA), abs(matrixA[1][0] - avgMatA), abs(matrixA[2][0] - avgMatA)} ,
		{abs(matrixA[0][1] - avgMatA), abs(matrixA[1][1] - avgMatA), abs(matrixA[2][1] - avgMatA)} ,
		{abs(matrixA[0][2] - avgMatA), abs(matrixA[1][2] - avgMatA), abs(matrixA[2][2] - avgMatA)}
	};

	avgMatB = matrixAvg(matrixB);
	printf("Average of Matrix B is: %d", avgMatB);
	return 0;
}
