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

int matrixAvg(unsigned char matrix[3][3])
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
	
	unsigned char matrixA [3][3] = {
		{255, 0, 64} ,
		{3, 73, 121} ,
		{12, 56, 211}
	};
	int avgMatA;
	avgMatA = 0;
	int i,j;

	/*
	for ( i = 0; i < 3; i++ )
	{
      for ( j = 0; j < 3; j++ )
      {
        avgMatA = avgMatA + matrixA[i][j];
      }
	}

	avgMatA = avgMatA / 9;
	*/
	avgMatA = matrixAvg(matrixA);
	printf("%d\n", avgMatA);
	
	int avgMatB;
	avgMatB = 0;
	unsigned char matrixB [3][3] = {
		{abs(matrixA[0][0] - avgMatA), abs(matrixA[1][0] - avgMatA), abs(matrixA[2][0] - avgMatA)} ,
		{abs(matrixA[0][1] - avgMatA), abs(matrixA[1][1] - avgMatA), abs (matrixA[2][1] - avgMatA)} ,
		{abs(matrixA[0][2] - avgMatA), abs(matrixA[1][2] - avgMatA), abs (matrixA[2][2] - avgMatA)}
	};
	/*
	for ( i = 0; i < 3; i++ )
	{
      for ( j = 0; j < 3; j++ )
      {
         printf("matrixB[%d][%d] = %d\n", i,j, matrixB[i][j] );
         avgMatB = avgMatB + matrixB[i][j];
      }
      printf("\n");
	}
	avgMatB = avgMatB / 9;
	*/
	avgMatB = matrixAvg(matrixB);
	printf("%d\n", avgMatB);
	return 0;
}

