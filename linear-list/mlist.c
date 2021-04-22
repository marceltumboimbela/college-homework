/*Nama : Shieny Aprilia*/
/*NIM : 13505089*/

/*File : mlist.c*/
/*driver ADT list linier dengan representasi berkait dengan pointer*/

#include "list.c"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*KAMUS*/
	List L, Li, Lc, Lcf, Lcp, Lk, Lkk, Lp1, Lp2;
	infotype Y, Xdel;
	address P1, P2, P3, P4, Pt, Pdel;
	/*PROGRAM*/
	CreateList(&L);
	CreateList(&Li);
	CreateList(&Lc);
	CreateList(&Lcf);
	CreateList(&Lcp);
	CreateList(&Lk);
	CreateList(&Lp1);
	CreateList(&Lp2);
	printf("List sudah dibuat kosong \n");
	ListEmpty(L) ? printf("List kosong \n") : printf("List tidak kosong \n");
	printf("Hasil alokasi dengan infotype = 5 : %d \n", info(Alokasi(5)));
	Dealokasi(Alokasi(5));
	printf("Sudah dealokasi \n");
	printf("Pengisian list (harus ada 2 dan 3). \n");
	printf("Input : ");
	scanf("%d", &Y);
	while (Y != -99)
	{
		P1 = (Alokasi(Y));
		InsertFirst(&L, P1);
		printf("Input : ");
		scanf("%d", &Y);
	}
	printf("Pengisian elemen list L dengan InsertFirst berhasil \n");
	printf("List : ");
	PrintList(L);
	FSearch(L, P1) ? printf("Found \n") : printf("Not Found \n");
	P2 = Search(L, 3);
	if (P2 != Nil)
	{
		printf("Info yang disearch (3) : %d \n", info(P2));
	}
	else /*3 tidak ditemukan di dalam list L*/
	{
		printf("Info yang disearch (3) tidak ditemukan \n");
	}
	printf("Driver InsVFirst (insert 3).\n");
	InsVFirst(&L, 3);
	printf("List : ");
	PrintList(L);
	printf("Driver InsVLast (insert 3).\n");
	InsVLast(&L, 3);
	printf("List : ");
	PrintList(L);
	printf("Driver InsertAfter (insert 11 after 3).\n");
	Pt = Alokasi(11);
	InsertAfter(&L, Pt, P2);
	printf("List : ");
	PrintList(L);
	printf("Driver InsertLast (insert 12).\n");
	Pt = Alokasi(12);
	InsertLast(&L, Pt);
	printf("List : ");
	PrintList(L);
	P3 = SearchPrec(L, 3);
	if (P3 != Nil)
	{
		printf("Info Prec (sebelum 3) : %d \n", info(P3));
	}
	else /*P3==Nil (Prec tidak ditemukan)*/
	{
		printf("Prec (sebelum 3) = Nil \n");
	}
	printf("Driver DelVFirst.\n");
	DelVFirst(&L, &Xdel);
	printf("List : ");
	PrintList(L);
	printf("Driver DelVLast.\n");
	DelVLast(&L, &Xdel);
	printf("List : ");
	PrintList(L);
	printf("Driver DelFirst.\n");
	DelFirst(&L, &Pdel);
	printf("List : ");
	PrintList(L);
	printf("Driver DelP (delete 2).\n");
	DelP(&L, 2);
	printf("List : ");
	PrintList(L);
	printf("Driver DelLast.\n");
	DelLast(&L, &Pdel);
	printf("List : ");
	PrintList(L);
	printf("Driver DelAfter. (after 3)\n");
	P4 = Search(L, 3);
	DelAfter(&L, &Pdel, P4);
	printf("List : ");
	PrintList(L);
	printf("Driver FInversList.\n");
	Li = FInversList(L);
	printf("List : ");
	PrintList(L);
	printf("List hasil invers : ");
	PrintList(Li);
	printf("Driver InversList. \n");
	InversList(&L);
	printf("List : ");
	PrintList(L);
	printf("Driver CopyList.\n");
	CopyList(&L, &Lc);
	printf("List : ");
	PrintList(L);
	printf("List hasil copy : ");
	PrintList(Lc);
	printf("Driver FCopyList.\n");
	Lcf = FCopyList(L);
	printf("List : ");
	PrintList(L);
	printf("List hasil copy : ");
	PrintList(Lcf);
	printf("Driver CpAlokList.\n");
	CpAlokList(L, &Lcp);
	printf("List : ");
	PrintList(L);
	printf("List hasil copy : ");
	PrintList(Lcp);
	printf("Driver konkat.\n");
	konkat(L, Lcp, &Lk);
	printf("List 1 : ");
	PrintList(L);
	printf("List 2 : ");
	PrintList(Lcp);
	printf("List hasil konkat : ");
	PrintList(Lk);
	printf("Driver konkat1 (Konkat list hasil CpAlokList dan list hasil konkat).\n");
	konkat1(&Lcp, &Lk, &Lkk);
	printf("List 1 : ");
	PrintList(Lcp);
	printf("List 2 : ");
	PrintList(Lk);
	printf("List hasil konkat1 : ");
	PrintList(Lkk);
	printf("Driver PecahList.\n");
	PecahList(&Lp1, &Lp2, L);
	printf("List : ");
	PrintList(L);
	printf("List 1 : ");
	PrintList(Lp1);
	printf("List 2 : ");
	PrintList(Lp2);
	printf("Banyaknya elemen list : %d. \n", NbElmt(L));
	printf("Nilai maksimum dalam list : %d. \n", Max(L));
	printf("Info alamat yang infonya maksimum : %d. \n", info(AdrMax(L)));
	printf("Nilai minimum dalam list : %d. \n", Min(L));
	printf("Info alamat yang infonya minimum : %d. \n", info(AdrMin(L)));
	printf("Rata-rata elemen dalam list (dalam integer) : %d. \n", Average(L));
	printf("Driver DelAll.\n");
	DelAll(&L);
	printf("List : ");
	PrintList(L);
	return 0;
}
