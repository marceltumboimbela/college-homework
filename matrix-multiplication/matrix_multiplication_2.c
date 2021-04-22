#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <windows.h>

typedef int **matrix;
int mul_amount_1;
int add_amount_1;
int mul_amount_2;
int add_amount_2;
int iter;

void allocate_matrix(matrix *A, int matsize)
{
	int i, j;
	(*A) = (int *)malloc(matsize * sizeof(int));
	for (i = 0; i < matsize; i++)
	{
		(*A)[i] = (int *)malloc(matsize * sizeof(int));
	}
	for (j = 0; j < matsize; j++)
	{
		for (i = 0; i < matsize; i++)
		{
			(*A)[i][j] = 0;
		}
	}
}

void randomize_element(matrix *source, int matrixsize)
{
	int rand_el;
	int i, j;

	for (j = 0; j < matrixsize; j++)
	{
		for (i = 0; i < matrixsize; i++)
		{
			rand_el = rand();
			rand_el %= matrixsize;
			(*source)[i][j] = rand_el;
		}
	}
}

void printmatrix(matrix A, int matsize)
{
	int i, j;
	for (j = 0; j < matsize; j++)
	{
		for (i = 0; i < matsize; i++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_time(SYSTEMTIME begin, SYSTEMTIME end)
{
	begin.wHour = (begin.wHour + 7) % 24;
	end.wHour = (end.wHour + 7) % 24;
	int dur = (end.wHour - begin.wHour) * 3600 + (end.wMinute - begin.wMinute) * 60 + (end.wSecond - begin.wSecond);
	int ms = (end.wMilliseconds - begin.wMilliseconds);
	printf("Perkalian matriks dimulai pada %d:%d:%d.%d WIB\n", begin.wHour, begin.wMinute, begin.wSecond, begin.wMilliseconds);
	printf("Perkalian matriks selesai pada %d:%d:%d.%d WIB\n", end.wHour, end.wMinute, end.wSecond, end.wMilliseconds);

	if (ms >= 0)
	{
		printf("Selesai dalam %d sekon dan %d milisekon\n", dur, ms);
	}
	else
	{
		printf("Selesai dalam %d sekon dan %d milisekon\n", dur - 1, 1000 + ms);
	}
}

matrix matrix_add(matrix A, matrix B, int matsize)
{
	int i, j;
	matrix C;
	C = (int *)malloc(matsize * sizeof(int));
	for (i = 0; i < matsize; i++)
	{
		C[i] = (int *)malloc(matsize * sizeof(int));
	}
	for (j = 0; j < matsize; j++)
	{
		for (i = 0; i < matsize; i++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	return C;
}

matrix matrix_sub(matrix A, matrix B, int matsize)
{
	int i, j;
	matrix C;
	C = (int *)malloc(matsize * sizeof(int));
	for (i = 0; i < matsize; i++)
	{
		C[i] = (int *)malloc(matsize * sizeof(int));
	}
	for (j = 0; j < matsize; j++)
	{
		for (i = 0; i < matsize; i++)
		{
			C[i][j] = A[i][j] - B[i][j];
		}
	}

	return C;
}

int two_power_by(int X)
{
	int i;
	int result = 1;
	for (i = 0; i < X; i++)
	{
		result = result * 2;
	}
	return result;
}

int power_of_two(int matsize)
{
	int pow = 0;
	int div = matsize / 2;
	while (div != 0)
	{
		div = div / 2;
		pow++;
	}
	if (two_power_by(pow) < matsize)
	{
		pow++;
	}
	return pow;
}

matrix div_matrix_four(matrix A, int x, int y, int matsize)
{
	matrix C;
	int i, j, ii, jj, newsize, beginx, endx, beginy, endy;
	newsize = matsize / 2;

	allocate_matrix(&C, newsize);

	if (x == 0)
	{
		beginx = 0;
		endx = newsize;
	}
	else
	{
		beginx = newsize;
		endx = matsize;
	}
	if (y == 0)
	{
		beginy = 0;
		endy = newsize;
	}
	else
	{
		beginy = newsize;
		endy = matsize;
	}

	jj = 0;
	for (j = beginy; j < endy; j++)
	{
		ii = 0;
		for (i = beginx; i < endx; i++)
		{
			C[ii][jj] = A[i][j];
			ii++;
		}
		jj++;
	}

	return C;
}

matrix combine(matrix C00, matrix C01, matrix C10, matrix C11, int ndiv)
{
	matrix result;
	int n = ndiv * 2;
	allocate_matrix(&result, n);

	int i, j, x, y;
	x = 0;
	y = 0;
	for (j = 0; j < ndiv; j++)
	{
		for (i = 0; i < ndiv; i++)
		{
			result[i][j] = C00[x][y];
			x++;
		}
		x = 0;
		for (i = ndiv; i < n; i++)
		{
			result[i][j] = C10[x][y];
			x++;
		}
		x = 0;
		y++;
	}

	x = 0;
	y = 0;
	for (j = ndiv; j < n; j++)
	{
		for (i = 0; i < ndiv; i++)
		{
			result[i][j] = C01[x][y];
			x++;
		}
		x = 0;
		for (i = ndiv; i < n; i++)
		{
			result[i][j] = C11[x][y];
			x++;
		}
		x = 0;
		y++;
	}

	return result;
}

void copy_back(matrix *R, matrix div, int x, int y, int Rsize)
{
	int beginx, beginy, endx, endy;
	int i, j;
	// printf("hei");
	if (x == 0)
	{
		beginx = 0;
		endx = Rsize / 2;
	}
	else
	{
		beginx = Rsize / 2;
		endx = Rsize;
	}
	// printf("ho");
	if (y == 0)
	{
		beginy = 0;
		endy = Rsize / 2;
	}
	else
	{
		beginy = Rsize / 2;
		endy = Rsize;
	}
	// printf("\nlet's go");

	for (j = 0; j < Rsize / 2; j++)
	{
		for (i = 0; i < Rsize / 2; i++)
		{
			(*R)[i + beginx][j + beginx] = div[i][j];
		}
	}

	// printf("\nyahaa\n");
}

matrix matrix_mul_reg(matrix source1, matrix source2, int matrixsize)
{
	matrix result;
	allocate_matrix(&result, matrixsize);
	int i, j, iter;
	for (j = 0; j < matrixsize; j++)
	{
		for (i = 0; i < matrixsize; i++)
		{
			iter = 0;
			result[i][j] = 0;
			while (iter < matrixsize)
			{
				result[i][j] = result[i][j] + source1[iter][j] * source2[i][iter];
				mul_amount_1++;
				add_amount_1++;
				iter++;
			}
		}
	}
	return result;
}

void matrix_mul_strassen(matrix A, matrix B, matrix *C, int matsize)
{
	matrix M1, M2, M3, M4, M5, M6, M7;
	matrix C00, C01, C10, C11;

	if (matsize == 1)
	{
		(*C)[0][0] = A[0][0] * B[0][0];
		mul_amount_2++;
	}
	else
	{
		allocate_matrix(&M1, matsize / 2);
		matrix_mul_strassen(matrix_sub(div_matrix_four(A, 1, 0, matsize), div_matrix_four(A, 1, 1, matsize), matsize / 2), matrix_add(div_matrix_four(B, 0, 1, matsize), div_matrix_four(B, 1, 1, matsize), matsize / 2), &M1, matsize / 2);
		add_amount_2 = add_amount_2 + 2;
		allocate_matrix(&M2, matsize / 2);
		matrix_mul_strassen(matrix_add(div_matrix_four(A, 0, 0, matsize), div_matrix_four(A, 1, 1, matsize), matsize / 2), matrix_add(div_matrix_four(B, 0, 0, matsize), div_matrix_four(B, 1, 1, matsize), matsize / 2), &M2, matsize / 2);
		add_amount_2 = add_amount_2 + 2;
		allocate_matrix(&M3, matsize / 2);
		matrix_mul_strassen(matrix_sub(div_matrix_four(A, 0, 0, matsize), div_matrix_four(A, 0, 1, matsize), matsize / 2), matrix_add(div_matrix_four(B, 0, 0, matsize), div_matrix_four(B, 1, 0, matsize), matsize / 2), &M3, matsize / 2);
		add_amount_2 = add_amount_2 + 2;
		allocate_matrix(&M4, matsize / 2);
		matrix_mul_strassen(matrix_add(div_matrix_four(A, 0, 0, matsize), div_matrix_four(A, 1, 0, matsize), matsize / 2), div_matrix_four(B, 1, 1, matsize), &M4, matsize / 2);
		add_amount_2 = add_amount_2 + 1;
		allocate_matrix(&M5, matsize / 2);
		matrix_mul_strassen(div_matrix_four(A, 0, 0, matsize), matrix_sub(div_matrix_four(B, 1, 0, matsize), div_matrix_four(B, 1, 1, matsize), matsize / 2), &M5, matsize / 2);
		add_amount_2 = add_amount_2 + 1;
		allocate_matrix(&M6, matsize / 2);
		matrix_mul_strassen(div_matrix_four(A, 1, 1, matsize), matrix_sub(div_matrix_four(B, 0, 1, matsize), div_matrix_four(B, 0, 0, matsize), matsize / 2), &M6, matsize / 2);
		add_amount_2 = add_amount_2 + 1;
		allocate_matrix(&M7, matsize / 2);
		matrix_mul_strassen(matrix_add(div_matrix_four(A, 0, 1, matsize), div_matrix_four(A, 1, 1, matsize), matsize / 2), div_matrix_four(B, 0, 0, matsize), &M7, matsize / 2);
		add_amount_2 = add_amount_2 + 1;

		C00 = matrix_add(matrix_sub(matrix_add(M1, M2, matsize / 2), M4, matsize / 2), M6, matsize / 2);
		add_amount_2 = add_amount_2 + 3;
		C10 = matrix_add(M4, M5, matsize / 2);
		add_amount_2 = add_amount_2 + 1;
		C01 = matrix_add(M6, M7, matsize / 2);
		add_amount_2 = add_amount_2 + 1;
		C11 = matrix_sub(matrix_add(matrix_sub(M2, M3, matsize / 2), M5, matsize / 2), M7, matsize / 2);
		add_amount_2 = add_amount_2 + 3;

		(*C) = combine(C00, C01, C10, C11, matsize / 2);
	}
}

int main()
{
	iter = 0;
	matrix source1, source2, result, r;
	int i, j, matrixsize, power, newsize;
	SYSTEMTIME begin, end, b, e;

	mul_amount_1 = 0;
	add_amount_1 = 0;
	mul_amount_2 = 0;
	add_amount_2 = 0;

	system("cls");
	printf("Masukkan ukuran matrix: ");
	scanf("%d", &matrixsize);

	power = power_of_two(matrixsize);
	newsize = two_power_by(power);
	allocate_matrix(&source1, newsize);
	allocate_matrix(&source2, newsize);
	allocate_matrix(&result, newsize);
	allocate_matrix(&r, newsize);

	srand((unsigned)time(NULL));
	randomize_element(&source1, matrixsize);
	randomize_element(&source2, matrixsize);

	printf("Mengkalikan matriks..\n");

	GetSystemTime(&begin);
	result = matrix_mul_reg(source1, source2, matrixsize);
	GetSystemTime(&end);

	GetSystemTime(&b);
	matrix_mul_strassen(source1, source2, &r, newsize);
	GetSystemTime(&e);

	system("cls");
	if (matrixsize <= 25)
	{
		printf("Source 1:\n");
		printmatrix(source1, matrixsize);
		printf("Source 2:\n");
		printmatrix(source2, matrixsize);
		printf("Result:\n");
		printmatrix(result, matrixsize);
		printf("R:\n");
		printmatrix(r, matrixsize);
	}

	print_time(begin, end);
	print_time(b, e);
	printf("Perkalian yang terjadi pada perkalian matriks dengan metode konvensional: %d\n", mul_amount_1);
	printf("Penjumlahan yang terjadi pada perkalian matriks dengan metode konvensional: %d\n", add_amount_1);
	printf("Perkalian yang terjadi pada perkalian matriks dengan algoritma Strassen: %d\n", mul_amount_2);
	printf("Penjumlahan yang terjadi pada perkalian matriks dengan algoritma Strassen: %d\n", add_amount_2);

	return 1;
}
