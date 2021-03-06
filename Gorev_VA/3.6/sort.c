#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

char **ar_of_words(FILE* input)
{
	char **A;
	char c;
	char *str;
	int i = 0, j = 0, I, J;
	A = (char**)malloc(NUM * sizeof(char*));
	A[0] = (char*)malloc(NUM * sizeof(char));
	A[0][0] = 0;

	while ((fscanf(input, "%c", &c) == 1) && (i < NUM) && (j < NUM))
	{
		if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9')))
		{
			A[i][j] = c;
			j++;
			A[i][j] = 0;
		}
		else
			if (j > 0)
			{
				i++;
				j = 0;
				A[i] = (char*)malloc(NUM * sizeof(char));
				A[i][0] = 0;
			}
	}

	if (j > 0)
	{
		i++;
		j = 0;
		A[i] = (char*)malloc(NUM * sizeof(char));
		A[i][0] = 0;
	}

	I = i - 1;
	while (I > 0)
	{
		J = 0;
		while (J < I)
		{
			if (strcmp(A[J], A[J + 1]) > 0)
			{
				str = A[J];
				A[J] = A[J + 1];
				A[J + 1] = str;
			}
			J++;
		}
		I--;
	}

	return A;
}
