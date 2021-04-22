#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <windows.h>

int mul;
int add;

int **new_matrix(int **matrix, int sizematrix)
{
	int i;
	int j;
	int element;

	matrix = (int **)malloc(2 * sizematrix * sizeof(int *));

	for (i = 0; i < sizematrix; i++)
	{
		matrix[i] = (int *)malloc(2 * sizematrix * sizeof(int));
	}

	for (j = 0; j < sizematrix; j++)
	{
		for (i = 0; i < sizematrix; i++)
		{
			element = rand();
			element = element % 10;
			matrix[i][j] = element;
		}
	}

	return matrix;
}

void print_matrix(int **matrix, int sizematrix)
{
	int i;
	int j;

	for (j = 0; j < sizematrix; j++)
	{
		for (i = 0; i < sizematrix; i++)
		{
			if (matrix[i][j] < 10)
				printf("%d   ", matrix[i][j]);
			else if (matrix[i][j] < 100 && matrix[i][j] >= 10)
				printf("%d  ", matrix[i][j]);
			else
				printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int **add_matrix(int **matrix1, int **matrix2, int sizematrix)
{
	int i;
	int j;
	int **matrixhasil;

	matrixhasil = new_matrix(matrixhasil, sizematrix);
	for (j = 0; j < sizematrix; j++)
	{
		for (i = 0; i < sizematrix; i++)
		{
			matrixhasil[i][j] = matrix1[i][j] + matrix2[i][j];
			add++;
		}
	}
	return matrixhasil;
}

int **sub_matrix(int **matrix1, int **matrix2, int sizematrix)
{
	int i;
	int j;
	int **matrixhasil;

	matrixhasil = new_matrix(matrixhasil, sizematrix);
	for (j = 0; j < sizematrix; j++)
	{
		for (i = 0; i < sizematrix; i++)
		{
			matrixhasil[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	return matrixhasil;
}

int **multiplication(int **matrix1, int **matrix2, int sizematrix)
{
	int i;
	int j;
	int iterator;
	int **matrixhasil;

	matrixhasil = new_matrix(matrixhasil, sizematrix);
	for (i = 0; i < sizematrix; i++)
	{
		for (j = 0; j < sizematrix; j++)
		{
			matrixhasil[i][j] = 0;
			for (iterator = 0; iterator < sizematrix; iterator++)
			{
				matrixhasil[i][j] = matrixhasil[i][j] + (matrix1[iterator][j] * matrix2[i][iterator]);
				add++;
				mul++;
			}
		}
	}

	return matrixhasil;
}

int **multiplication2(int **matrix1, int **matrix2, int sizematrix)
{
	int i;
	int j;
	int odd = 0;
	int newsize;
	int **matrixhasil;
	int **tempmatrix1;
	int **tempmatrix2;
	int **matrix111, **matrix112, **matrix121, **matrix122;
	int **matrix211, **matrix212, **matrix221, **matrix222;
	int **matrixhasil11, **matrixhasil12, **matrixhasil21, **matrixhasil22;
	int **m1, **m2, **m3, **m4, **m5, **m6, **m7;
	int **matrixfix;

	if (sizematrix % 2 == 1)
		odd = 1;
	if (sizematrix == 1)
		return multiplication(matrix1, matrix2, sizematrix);
	else
	{
		if (odd == 1)
			newsize = sizematrix + 1;
		else
			newsize = sizematrix;

		matrix111 = new_matrix(matrix111, newsize / 2);
		matrix112 = new_matrix(matrix112, newsize / 2);
		matrix121 = new_matrix(matrix121, newsize / 2);
		matrix122 = new_matrix(matrix122, newsize / 2);
		matrix211 = new_matrix(matrix211, newsize / 2);
		matrix212 = new_matrix(matrix212, newsize / 2);
		matrix221 = new_matrix(matrix221, newsize / 2);
		matrix222 = new_matrix(matrix222, newsize / 2);
		matrixhasil11 = new_matrix(matrixhasil11, newsize / 2);
		matrixhasil12 = new_matrix(matrixhasil12, newsize / 2);
		matrixhasil21 = new_matrix(matrixhasil21, newsize / 2);
		matrixhasil22 = new_matrix(matrixhasil22, newsize / 2);
		tempmatrix1 = new_matrix(tempmatrix1, newsize);
		tempmatrix2 = new_matrix(tempmatrix2, newsize);
		m1 = new_matrix(m1, newsize / 2);
		m2 = new_matrix(m2, newsize / 2);
		m3 = new_matrix(m3, newsize / 2);
		m4 = new_matrix(m4, newsize / 2);
		m5 = new_matrix(m5, newsize / 2);
		m6 = new_matrix(m6, newsize / 2);
		m7 = new_matrix(m7, newsize / 2);
		matrixhasil = new_matrix(matrixhasil, newsize);

		if (odd == 1)
		{
			for (j = 0; j < newsize; j++)
			{
				for (i = 0; i < newsize; i++)
				{
					if (i != sizematrix && j != sizematrix)
					{
						tempmatrix1[i][j] = matrix1[i][j];
						tempmatrix2[i][j] = matrix2[i][j];
					}
					else
					{
						tempmatrix1[i][j] = 0;
						tempmatrix2[i][j] = 0;
					}
				}
			}
		}
		else
		{
			tempmatrix1 = matrix1;
			tempmatrix2 = matrix2;
		}

		for (j = 0; j < newsize; j++)
		{
			for (i = 0; i < newsize; i++)
			{
				if (i >= 0 && i < newsize / 2 && j >= 0 && j < newsize / 2)
				{
					matrix111[i][j] = tempmatrix1[i][j];
					matrix211[i][j] = tempmatrix2[i][j];
				}
				if (i >= newsize / 2 && i < newsize && j >= 0 && j < newsize / 2)
				{
					matrix112[i - newsize / 2][j] = tempmatrix1[i][j];
					matrix212[i - newsize / 2][j] = tempmatrix2[i][j];
				}
				if (i >= 0 && i < newsize / 2 && j >= newsize / 2 && j < newsize)
				{
					matrix121[i][j - newsize / 2] = tempmatrix1[i][j];
					matrix221[i][j - newsize / 2] = tempmatrix2[i][j];
				}
				if (i >= newsize / 2 && i < newsize && j >= newsize / 2 && j < newsize)
				{
					matrix122[i - newsize / 2][j - newsize / 2] = tempmatrix1[i][j];
					matrix222[i - newsize / 2][j - newsize / 2] = tempmatrix2[i][j];
				}
			}
		}

		m1 = multiplication2(sub_matrix(matrix112, matrix122, newsize / 2), add_matrix(matrix221, matrix222, newsize / 2), newsize / 2);
		m2 = multiplication2(add_matrix(matrix111, matrix122, newsize / 2), add_matrix(matrix211, matrix222, newsize / 2), newsize / 2);
		m3 = multiplication2(sub_matrix(matrix111, matrix121, newsize / 2), add_matrix(matrix211, matrix212, newsize / 2), newsize / 2);
		m4 = multiplication2(add_matrix(matrix111, matrix112, newsize / 2), matrix222, newsize / 2);
		m5 = multiplication2(matrix111, sub_matrix(matrix212, matrix222, newsize / 2), newsize / 2);
		m6 = multiplication2(matrix122, sub_matrix(matrix221, matrix211, newsize / 2), newsize / 2);
		m7 = multiplication2(add_matrix(matrix121, matrix122, newsize / 2), matrix211, newsize / 2);

		matrixhasil11 = add_matrix(sub_matrix(add_matrix(m1, m2, newsize / 2), m4, newsize / 2), m6, newsize / 2);
		matrixhasil12 = add_matrix(m4, m5, newsize / 2);
		matrixhasil21 = add_matrix(m6, m7, newsize / 2);
		matrixhasil22 = sub_matrix(add_matrix(sub_matrix(m2, m3, newsize / 2), m5, newsize / 2), m7, newsize / 2);

		for (j = 0; j < newsize / 2; j++)
		{
			for (i = 0; i < newsize / 2; i++)
			{
				matrixhasil[i][j] = matrixhasil11[i][j];
				matrixhasil[i + newsize / 2][j] = matrixhasil12[i][j];
				matrixhasil[i][j + newsize / 2] = matrixhasil21[i][j];
				matrixhasil[i + newsize / 2][j + newsize / 2] = matrixhasil22[i][j];
			}
		}

		matrixfix = new_matrix(matrixfix, sizematrix);
		for (j = 0; j < sizematrix; j++)
		{
			for (i = 0; i < sizematrix; i++)
			{
				matrixfix[i][j] = matrixhasil[i][j];
			}
		}

		return matrixfix;
	}
}

void print_time(SYSTEMTIME begin, SYSTEMTIME end)
{
	begin.wHour = (begin.wHour + 7) % 24;
	end.wHour = (end.wHour + 7) % 24;
	int dur = (end.wHour - begin.wHour) * 3600 + (end.wMinute - begin.wMinute) * 60 + (end.wSecond - begin.wSecond);
	int ms = (end.wMilliseconds - begin.wMilliseconds);
	printf("Operasi perkalian matrix dimulai pada %d:%d:%d.%d WIB\n", begin.wHour, begin.wMinute, begin.wSecond, begin.wMilliseconds);
	printf("Operasi perkalian matrix selesai pada %d:%d:%d.%d WIB\n", end.wHour, end.wMinute, end.wSecond, end.wMilliseconds);

	if (ms >= 0)
	{
		printf("Operasi selesai dalam %d sekon dan %d milisekon\n", dur, ms);
	}
	else
	{
		printf("Operasi selesai dalam %d sekon dan %d milisekon\n", dur - 1, 1000 + ms);
	}
}

int main()
{
	int **matrix1;
	int **matrix2;
	int **matrixhasil;
	int sizematrix;
	int waktu;
	int hour, minute, second;
	int sekarang;
	SYSTEMTIME begin, end, b, e;

	add = 0;
	mul = 0;

	printf("masukin aja ukuran matriksnya: ");
	scanf("%d", &sizematrix);
	matrix1 = new_matrix(matrix1, sizematrix);
	matrix2 = new_matrix(matrix2, sizematrix);
	matrixhasil = new_matrix(matrixhasil, sizematrix);

	GetSystemTime(&begin);
	matrixhasil = multiplication(matrix1, matrix2, sizematrix);
	GetSystemTime(&end);

	printf("kalo ini pake algoritma bruteforce lho\n");
	if (sizematrix <= 25)
	{
		printf("ini matrix1 lho\n\n");
		print_matrix(matrix1, sizematrix);
		printf("\n");
		printf("ini matrix2 lho\n\n");
		print_matrix(matrix2, sizematrix);
		printf("\n");
		printf("ini hasil perkaliannya lho\n\n");
		print_matrix(matrixhasil, sizematrix);
		printf("\n");
	}
	printf("jumlah operasi penjumlahan pada bruteforce = %d\n", add);
	printf("jumlah operasi perkalian pada bruteforce = %d\n", mul);
	print_time(begin, end);
	printf("\n");
	mul = 0;
	add = 0;

	GetSystemTime(&b);
	matrixhasil = multiplication2(matrix1, matrix2, sizematrix);
	GetSystemTime(&e);

	printf("kalo ini pake algoritma strussen lho\n");
	if (sizematrix <= 25)
	{
		printf("ini matrix1 lho\n\n");
		print_matrix(matrix1, sizematrix);
		printf("\n");
		printf("ini matrix2 lho\n\n");
		print_matrix(matrix2, sizematrix);
		printf("\n");
		printf("ini hasil perkaliannya lho\n\n");
		print_matrix(matrixhasil, sizematrix);
		printf("\n");
	}

	printf("jumlah operasi penjumlahan pada strassen = %d\n", add);
	printf("jumlah operasi perkalian pada strassen = %d\n", mul);
	print_time(b, e);
	system("pause");
	return 0;
}
