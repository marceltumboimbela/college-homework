#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int kali;
int tambah;

int **matriks(int **x, int n);
//alokasi memori dan isi matriks dengan bilangan random
void bebas_matriks(int **x, int n);
//dealokasi memori matriks
void cetak_matriks(int **x, int n);
//cetak isi matriks ke layar
int **tambah_matriks(int **x, int **y, int n);
//matriks x ditambah matriks y
int **kurang_matriks(int **x, int **y, int n);
//matriks x dikurang matriks y
int **kali_matriks1(int **x, int **y, int n);
//matriks x dikali matriks y dengan algoritma bruteforce
int **kali_matriks2(int **x, int **y, int n);
//matriks x dikali matriks y dengan algoritma strassen

int main()
{
	int menu;
	int n;
	int **A;
	int **B;
	int **C;
	int i, j, k;
	int waktu;
	int jam, menit, detik;

	kali = 0;
	tambah = 0;

	time_t sekarang;
	struct tm *T;

	printf("Menu :\n1. Perkalian Matriks dengan BruteForce\n2. Perkalian Matriks dengan Strassen\nPilih menu : ");
	scanf("%d", &menu);
	while (menu < 1 || menu > 2)
	{
		printf("Masukkan pilihan yang benar!\n");
		printf("Menu :\n1. Perkalian Matriks dengan BruteForce\n2. Perkalian Matriks dengan Strassen\nPilih menu : ");
		scanf("%d", &menu);
	}
	if (menu == 1)
	{
		system("cls");
		printf("-----------------------------------\n");
		printf("PERKALIAN MATRIKS DENGAN BRUTEFORCE\n");
		printf("-----------------------------------\n");
		printf("Masukkan n : ");
		scanf("%d", &n);

		A = matriks(A, n);
		B = matriks(B, n);
		C = matriks(C, n);

		sekarang = time(NULL);
		T = localtime(&sekarang);
		jam = T->tm_hour, menit = T->tm_min, detik = T->tm_sec;

		C = kali_matriks1(A, B, n);

		sekarang = time(NULL);
		T = localtime(&sekarang);
		waktu = (T->tm_hour - jam) * 3600 + (T->tm_min - menit) * 60 + (T->tm_sec - detik);
	}
	else if (menu == 2)
	{
		system("cls");
		printf("---------------------------------\n");
		printf("PERKALIAN MATRIKS DENGAN STRASSEN\n");
		printf("---------------------------------\n");
		printf("Masukkan n : ");
		scanf("%d", &n);

		A = matriks(A, n);
		B = matriks(B, n);
		C = matriks(C, n);

		sekarang = time(NULL);
		T = localtime(&sekarang);
		jam = T->tm_hour, menit = T->tm_min, detik = T->tm_sec;

		C = kali_matriks2(A, B, n);

		sekarang = time(NULL);
		T = localtime(&sekarang);
		waktu = (T->tm_hour - jam) * 3600 + (T->tm_min - menit) * 60 + (T->tm_sec - detik);
	}

	if (n <= 25)
	{
		printf("Matriks A:\n");
		cetak_matriks(A, n);
		printf("Matriks B:\n");
		cetak_matriks(B, n);
		printf("Hasil A*B:\n");
		cetak_matriks(C, n);
	}

	printf("Jumlah Operasi Perkalian : %d\n", kali);
	printf("Jumlah Operasi Penjumlahan : %d\n", tambah);
	printf("Jumlah Waktu Operasi Perkalian Matriks : %d\n", waktu);
	system("pause");
	return;
}

int **matriks(int **x, int n)
{
	int i, j;
	x = (int **)malloc(2 * n * sizeof(int *));
	for (i = 0; i < n; i++)
	{
		x[i] = (int *)malloc(2 * n * sizeof(int));
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			x[i][j] = (rand() % 3);
	}

	return x;
}

void bebas_matriks(int **x, int n)
{
	int i;
	x += n;
	for (i = 0; i < n; i++)
		free(x[i] + n);
	free(x);
}

void cetak_matriks(int **x, int n)
{
	int i, j;

	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
			printf("%d\t", x[i][j]);
		printf("\n");
	}
}

int **tambah_matriks(int **x, int **y, int n)
{
	int **z;
	int i, j;

	z = matriks(z, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			z[i][j] = x[i][j] + y[i][j];
			tambah++;
		}
	}
	return z;
}

int **kurang_matriks(int **x, int **y, int n)
{
	int **z;
	int i, j;

	z = matriks(z, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			z[i][j] = x[i][j] - y[i][j];
	}
	return z;
}

int **kali_matriks1(int **x, int **y, int n)
{
	int i, j, k;
	int **z;

	z = matriks(z, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			z[i][j] = 0;
			for (k = 0; k < n; k++)
			{
				z[i][j] = z[i][j] + (x[i][k] * y[k][j]);
				kali++;
				tambah++;
			}
		}
	}
	return z;
}

int **kali_matriks2(int **x, int **y, int n)
{
	int i, j, k;
	int **z, **z1;
	int **tempx, **tempy;
	int **x11, **x12, **x21, **x22;
	int **y11, **y12, **y21, **y22;
	int **z11, **z12, **z21, **z22;
	int **m1, **m2, **m3, **m4, **m5, **m6, **m7;
	int ganjil = 0;
	int m;

	if ((n % 2) == 1)
		ganjil = 1;

	if (n == 1)
		return kali_matriks1(x, y, n);
	else
	{
		if (ganjil == 1)
			m = n + 1;
		else
			m = n;

		tempx = matriks(tempx, m);
		tempy = matriks(tempy, m);

		x11 = matriks(x11, (m / 2));
		x12 = matriks(x12, (m / 2));
		x21 = matriks(x21, (m / 2));
		x22 = matriks(x22, (m / 2));
		y11 = matriks(y11, (m / 2));
		y12 = matriks(y12, (m / 2));
		y21 = matriks(y21, (m / 2));
		y22 = matriks(y22, (m / 2));
		z11 = matriks(z11, (m / 2));
		z12 = matriks(z12, (m / 2));
		z21 = matriks(z21, (m / 2));
		z22 = matriks(z22, (m / 2));
		m1 = matriks(m1, (m / 2));
		m2 = matriks(m2, (m / 2));
		m3 = matriks(m3, (m / 2));
		m4 = matriks(m4, (m / 2));
		m5 = matriks(m5, (m / 2));
		m6 = matriks(m6, (m / 2));
		m7 = matriks(m7, (m / 2));
		z = matriks(z, m);

		if (ganjil == 1)
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (i != n && j != n)
					{
						tempx[i][j] = x[i][j];
						tempy[i][j] = y[i][j];
					}
					else
					{
						tempx[i][j] = 0;
						tempy[i][j] = 0;
					}
				}
			}
		}
		else
		{
			tempy = y;
			tempx = x;
		}

		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (i >= 0 && i < (m / 2) && j >= 0 && j < (m / 2))
				{
					x11[i][j] = tempx[i][j];
					y11[i][j] = tempy[i][j];
				}
				else if (i >= (m / 2) && i < m && j >= 0 && j < (m / 2))
				{
					x12[i - (m / 2)][j] = tempx[i][j];
					y12[i - (m / 2)][j] = tempy[i][j];
				}
				else if (i >= 0 && i < (m / 2) && j >= (m / 2) && j < m)
				{
					x21[i][j - (m / 2)] = tempx[i][j];
					y21[i][j - (m / 2)] = tempy[i][j];
				}
				else
				{
					x22[i - (m / 2)][j - (m / 2)] = tempx[i][j];
					y22[i - (m / 2)][j - (m / 2)] = tempy[i][j];
				}
			}
		}

		m1 = kali_matriks2(tambah_matriks(x11, x22, (m / 2)), tambah_matriks(y11, y22, (m / 2)), (m / 2));
		m2 = kali_matriks2(tambah_matriks(x21, x22, (m / 2)), y11, (m / 2));
		m3 = kali_matriks2(x11, kurang_matriks(y12, y22, (m / 2)), (m / 2));
		m4 = kali_matriks2(x22, kurang_matriks(y21, y11, (m / 2)), (m / 2));
		m5 = kali_matriks2(tambah_matriks(x11, x12, (m / 2)), y22, (m / 2));
		m6 = kali_matriks2(kurang_matriks(x21, x11, (m / 2)), tambah_matriks(y11, y12, (m / 2)), (m / 2));
		m7 = kali_matriks2(kurang_matriks(x12, x22, (m / 2)), tambah_matriks(y21, y22, (m / 2)), (m / 2));

		z11 = tambah_matriks(kurang_matriks(tambah_matriks(m1, m4, (m / 2)), m5, (m / 2)), m7, (m / 2));
		z12 = tambah_matriks(m3, m5, (m / 2));
		z21 = tambah_matriks(m2, m4, (m / 2));
		z22 = tambah_matriks(kurang_matriks(tambah_matriks(m1, m3, (m / 2)), m2, (m / 2)), m6, (m / 2));

		/*
		m1 = kali_matriks2(kurang_matriks(x12,x22,(m/2)),tambah_matriks(y21,y22,(m/2)),(m/2));
		m2 = kali_matriks2(tambah_matriks(x11,x22,(m/2)),tambah_matriks(y11,y22,(m/2)),(m/2));
		m3 = kali_matriks2(kurang_matriks(x11,x21,(m/2)),tambah_matriks(y11,y12,(m/2)),(m/2));
		m4 = kali_matriks2(tambah_matriks(x11,x12,(m/2)),y22,(m/2));
		m5 = kali_matriks2(x11,kurang_matriks(y12,y22,(m/2)),(m/2));
		m6 = kali_matriks2(x22,kurang_matriks(y21,y11,(m/2)),(m/2));
		m7 = kali_matriks2(tambah_matriks(x21,x22,(m/2)),y11,(m/2));

		z11 = kurang_matriks(tambah_matriks(m1,m2,(m/2)),tambah_matriks(m4,m6,(m/2)),(m/2));
		z12 = tambah_matriks(m4,m5,(m/2));
		z21 = tambah_matriks(m6,m7,(m/2));
		z22 = tambah_matriks(kurang_matriks(m2,m3,(m/2)),kurang_matriks(m5,m7,(m/2)),(m/2));
		*/
		//		z11 = tambah_matriks(kali_matriks2(x11,y11,(m/2)),kali_matriks2(x12,y21,(m/2)),(m/2));
		//		z12 = tambah_matriks(kali_matriks2(x11,y12,(m/2)),kali_matriks2(x12,y22,(m/2)),(m/2));
		//		z21 = tambah_matriks(kali_matriks2(x21,y11,(m/2)),kali_matriks2(x22,y21,(m/2)),(m/2));
		//		z22 = tambah_matriks(kali_matriks2(x21,y12,(m/2)),kali_matriks2(x22,y22,(m/2)),(m/2));

		for (i = 0; i < (m / 2); i++)
		{
			for (j = 0; j < (m / 2); j++)
			{
				z[i][j] = z11[i][j];
				z[i + (m / 2)][j] = z12[i][j];
				z[i][j + (m / 2)] = z21[i][j];
				z[i + (m / 2)][j + (m / 2)] = z22[i][j];
			}
		}

		z1 = matriks(z1, n);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				z1[i][j] = z[i][j];
		}
		return z1;
	}
}
