#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#include "MaxEl.h"
#include "prn_matr.h"

double DET(double *a, int n){
	
	int i, j, l, sgn = 1;;
	double del, kof, det = 1;
	
	for (i = 0; i < n; i++)
	{		
		if (i < n - 1) sgn *= MaxEl_In_Collon(a, n, i);
		if (n == 5) prn_matr(a, n);
		if (a[i * n + i] < 0 || a[i * n + i] > 0)
		{
			
			del = a[i * n  + i];
		
			for (j = i + 1; j < n; j++)
			{
				kof = a[j * n + i] / del;
			
				for (l = 0; l < n ; l++)
				{
					a[j * n + l] -= kof * a[i * n + l];		
				}
			}
		}
		det *= a[i * n + i];
		if (n == 5) prn_matr(a, n);
	}
	return det * sgn;
}
void Find_Matr_Dopolneni(double *a, double *MINORS, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			MINORS[i*n + j] = pow(-1, i+j)*DET_MINOR(a, i, j, n);
		}
	}
}

double DET_MINOR(double *a, int I, int J, int n)
{
	int i, j;
	double *buf, Det_Minor; 
	buf = (double*) malloc (n*n*sizeof(double));
	for (i = 0; i < I; i++)
	{
		for (j = 0; j < J; j++)
		{
			buf[i * (n - 1) + j] = a[i * n + j];
		}
		for (j = J+1; j < n; j++)
		{
			buf[i * (n - 1) + j - 1] = a[i * n + j];
		}
	}
	for (i = I+1; i < n; i++)
	{
		for (j = 0; j < J; j++)
		{
			buf[(i-1) * (n - 1) + j] = a[i * n + j];
		}
		for (j = J+1; j < n; j++)
		{
			buf[(i-1) * (n - 1) + j - 1] = a[i * n + j];
		}
	}
	//printf("Matr without %d %d\n", I, J);
	//prn_matr(buf, n-1);
	Det_Minor = DET(buf, n-1);
	free(buf);
	return Det_Minor;
}

void TRANS(double *MINORS, int n)
{
	int i, j;
	double buf;
	for (i=0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			buf = MINORS[i * n + j];
            MINORS[i * n + j] = MINORS[j * n +i];
            MINORS[j * n + i] = buf;
		}
	}
}