/*Nama : Shieny Aprilia*/
/*NIM : 13505089*/

/*File : list.c*/
/*Body prototype ADT listlinier dengan representasi berkait dengan pointer*/

#include "list.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

void CreateList(List *L)
/*I.S. sembarang*/
/*F.S. Terbentuk list kosong*/
{
	/*KAMUS LOKAL*/
	/*ALGORITMA*/
	First(*L) = Nil;
}

boolean ListEmpty(List L)
/*Mengirim true jika list kosong*/
{
	/*KAMUS LOKAL*/
	/*ALGORITMA*/
	return (First(L) == Nil);
}

address Alokasi(infotype X)
/*Mengirimkan address hasil alokasi sebuah elemen*/
/*Jika alokasi berhasil, maka address tidak nil, dan misalnya*/
/*menghasilkan P, maka info(P)=X, Next(P)=Nil*/
/*Jika alokasi gagal, mengirimkan Nil*/
{
	/*KAMUS LOKAL*/
	address P;
	/*ALGORITMA*/
	P = (address)malloc(sizeof(Elmtlist));
	if ((P) != Nil)
	{
		info(P) = X;
		next(P) = Nil;
	}
	return (P);
}

void Dealokasi(address P)
/*I.S. P terdefinisi*/
/*F.S. P dikembalikan ke sistem*/
/*Melakukan dealokasi/pengembalian address P*/
{
	/*KAMUS LOKAL*/
	/*ALGORITMA*/
	free(P);
}

void InsertFirst(List *L, address P)
/*I.S. sembarang, P sudah dialokasi*/
/*F.S. menambahkan elemen beraddress P sebagai elemen pertama*/
{
	/*KAMUS LOKAL*/
	/*ALGORITMA*/
	next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
/*I.S. Prec pastilah elemen list dan bukan elemen terakhir*/
/*	 P sudah dialokasi*/
/*Insert P sebagai elemen sesudah elemen beralamat Prec*/
{
	/*KAMUS LOKAL*/
	/*ALGORITMA*/
	next(P) = next(Prec);
	next(Prec) = P;
}

void InsertLast(List *L, address P)
/*I.S. sembarang, P sudah dialokasi*/
/*F.S. P ditambahkan sebagai elemen terakhir yang baru*/
{
	/*KAMUS LOKAL*/
	address Prec;
	/*ALGORITMA*/
	Prec = First(*L);
	if (Prec == Nil) /*List kosong*/
	{
		InsertFirst(L, P);
	}
	else /*List tidak kosong*/
	{
		while (next(Prec) != Nil)
		{
			Prec = next(Prec);
		}
		next(Prec) = P;
	}
}

void DelFirst(List *L, address *P)
/*I.S. List tidak kosong*/
/*F.S. P adalah alamat elemen pertama list sebelum penghapusan*/
/*	 Elemen list berkurang satu (mungkin menjadi kosong)*/
/*First elemen yang baru adalah suksesor elemen pertama yang lama*/
{
	/*KAMUS LOKAL*/
	/*ALGORITMA*/
	(*P) = First(*L);
	First(*L) = next(*P);
	next(*P) = Nil;
}

void DelP(List *L, infotype X)
/*I.S. sembarang*/
/*F.S. Jika ada elemen list beraddress P, dengan info(P)=X*/
/*	 Maka P dihapus dari list dan didealokasi*/
/*	 Jika tidak ada elemen list dengan info(P)=X, maka list tetap*/
/*	 List mungkin menjadi kosong karena penghapusan*/
{
	/*KAMUS LOKAL*/
	address P, Prec, Pdel, last;
	/*ALGORITMA*/
	P = First(*L);
	Prec = Nil;
	while (P != Nil)
	{
		if (info(P) == X)
		{
			Prec = SearchPrec((*L), X);
			Pdel = P;
			if (Prec != Nil) /*P bukan elemen pertama list*/
			{
				next(Prec) = next(Pdel);
			}
			else /*Prec==Nil*/
			{
				First(*L) = next(Pdel);
			}
		}
		P = next(P);
	}
	Dealokasi(Pdel);
}

void DelLast(List *L, address *P)
/*I.S. List tidak kosong*/
/*F.S. P adalah alamat elemen terakhir list sebelum penghapusan*/
/*	 Elemen list berkurang satu (mungkin menjadi kosong)*/
/*	 Last elemen baru adalah predesesor last elemen yang lama jika ada*/
{
	/*KAMUS LOKAL*/
	address Prec;
	/*ALGORITMA*/
	(*P) = First(*L);
	Prec = Nil;
	while (next(*P) != Nil)
	{
		Prec = (*P);
		(*P) = next(*P);
	}
	if (Prec == Nil) /*Last(L) adalah First(L) (elemen list hanya satu)*/
	{
		First(*L) = Nil;
	}
	else /*Prec!=Nil (Elemen list tidak hanya satu)*/
	{
		next(Prec) = Nil;
	}
}

void DelAfter(List *L, address *Pdel, address Prec)
/*I.S. List tidak kosong, Prec adalah anggota list*/
/*F.S. Menghapus next(Prec)*/
/*	 Pdel adalah alamat elemen list yang dihapus*/
{
	/*KAMUS LOKAL*/
	address P;
	/*ALGORITMA*/
	P = First(*L);
	while (P != Prec)
	{
		P = next(P);
	}
	if (next(P) != Nil) /*Prec bukan elemen terakhir list*/
	{
		(*Pdel) = next(P);
		(*Pdel) = Nil;
		next(P) = next(next(P));
	}
}

void InsVFirst(List *L, infotype X)
/*I.S. L mungkin kosong*/
/*F.S. melakukan alokasi sebuah elemen*/
/*	 dan menambahkan elemen pertama dengan nilai X jika alokasi berhasil*/
{
	/*KAMUS LOKAL*/
	address P;
	/*ALGORITMA*/
	P = Alokasi(X);
	if (P != Nil)
	{
		InsertFirst(L, P);
	}
}

void InsVLast(List *L, infotype X)
/*I.S. L mungkin kosong*/
/*F.S. melakukan alokasi sebuah elemen dan*/
/*	 menambahkan elemen list di akhir: elemen terakhir yang baru*/
/*	 bernilai X jika alokasi berhasil. Jika alokasi gagal:I.S.=F.S.*/
{
	/*KAMUS LOKAL*/
	address P;
	/*ALGORITMA*/
	P = Alokasi(X);
	if (P != Nil)
	{
		InsertLast(L, P);
	}
}

void DelVFirst(List *L, infotype *X)
/*I.S. list tidak kosong*/
/*F.S. Elemen pertama list dihapus : nilai info disimpan pada X*/
/*	 dan alamat elemen pertama di-dealokasi*/
{
	/*KAMUS LOKAL*/
	address Pdel;
	/*ALGORITMA*/
	DelFirst(L, &Pdel);
	(*X) = info(Pdel);
	Dealokasi(Pdel);
}

void DelVLast(List *L, infotype *X)
/*I.S. list tidak kosong*/
/*F.S. Elemen terakhir list dihapus : nilai info disimpan pada X*/
/*	 dan alamat elemen terakhir di-dealokasi*/
{
	/*KAMUS LOKAL*/
	address Pdel;
	/*ALGORITMA*/
	DelLast(L, &Pdel);
	(*X) = info(Pdel);
	Dealokasi(Pdel);
}

address Search(List L, infotype X)
/*Mencari apakah ada elemen list dengan info(P)=X*/
/*Jika ada, mengirimkan address elemen tsb*/
/*Jika tidak ada, mengirimkan Nil*/
{
	/*KAMUS LOKAL*/
	address P;
	boolean found;
	/*ALGORITMA*/
	P = First(L);
	found = false;
	while ((!found) && (P != Nil))
	{
		found = (info(P) == X);
		if (!found)
		{
			P = next(P);
		}
	}
	return (P);
}

boolean FSearch(List L, address P)
/*Mencari apakah ada elemen list yang beralamat P*/
/*Mengirimkan true jika ada, false jika tidak ada*/
{
	/*KAMUS LOKAL*/
	boolean found;
	address Prec;
	/*ALGORITMA*/
	found = false;
	Prec = First(L);
	while ((!found) && (Prec != Nil))
	{
		found = (P == Prec);
		Prec = next(Prec);
	}
	return (found);
}

address SearchPrec(List L, infotype X)
/*mengirimkan address elemen sebelum elemen yang nilainya=X*/
/*mencari apakah ada elemen list dengan info(P)=X*/
/*jika ada, mengirimkan address Prec, dengan next(Prec)=P dan info(P)=X*/
/*jika tidak, mengirimkan Nil*/
/*Jika P adalah elemen pertama, maka Prec=Nil*/
{
	/*KAMUS LOKAL*/
	address P, Prec;
	/*ALGORITMA*/
	if (Search(L, X) == Nil) /*Di list L tidak ada elemen yang bernilai X*/
	{
		return (Nil);
	}
	else /*Di list L ada elemen bernilai X*/
	{
		P = First(L);
		Prec = Nil;
		while ((info(P) != X) && (P != Nil))
		{
			Prec = P;
			P = next(P);
		}
		return (Prec);
	}
}

address SearchLast(List L)
/*mengirimkan address elemen terakhir list*/
{
	/*KAMUS LOKAL*/
	address P;
	/*ALGORITMA*/
	P = First(L);
	if (P != Nil)
	{
		while (next(P) != Nil)
		{
			P = next(P);
		}
	}
	return (P);
}

void PrintList(List L)
/*I.S. L mungkin kosong*/
/*F.S. info tiap elemen L sudah tertulis dengan First(L) ditulis lebih dulu*/
{
	/*KAMUS LOKAL*/
	address P;
	/*ALGORITMA*/
	P = First(L);
	while (P != Nil)
	{
		printf("%d ", info(P));
		P = next(P);
	}
	printf("\n");
}

int NbElmt(List L)
/*Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong*/
{
	/*KAMUS LOKAL*/
	int count = 0;
	address P;
	/*ALGORITMA*/
	P = First(L);
	while (P != Nil)
	{
		count++;
		P = next(P);
	}
	return (count);
}

infotype Max(List L)
/*Mengirimkan nilai info(P) yang maksimum*/
/*Prekondisi : list L tidak kosong*/
{
	/*KAMUS LOKAL*/
	address P;
	infotype counter;
	/*ALGORITMA*/
	counter = info(First(L));
	P = next(First(L));
	while (P != Nil)
	{
		if (counter < info(P))
		{
			counter = info(P);
		}
		P = next(P);
	}
	return (counter);
}

address AdrMax(List L)
/*Mengirimkan address P, dengan info(P) yang bernilai maksimum*/
/*Prekondisi : list L tidak kosong*/
{
	/*KAMUS LOKAL*/
	infotype nMax;
	address P;
	/*ALGORITMA*/
	nMax = Max(L);
	P = Search(L, nMax);
	return (P);
}

infotype Min(List L)
/*Mengirimkan nilai info(P) yang minimum*/
/*Prekondisi : list L tidak kosong*/
{
	/*KAMUS LOKAL*/
	infotype counter;
	address P;
	/*ALGORITMA*/
	counter = info(First(L));
	P = next(First(L));
	while (P != Nil)
	{
		if (counter > info(P))
		{
			counter = info(P);
		}
		P = next(P);
	}
	return (counter);
}

address AdrMin(List L)
/*Mengirimkan address P, dengan info(P) yang bernilai minimum*/
/*Prekondisi : list L tidak kosong*/
{
	/*KAMUS LOKAL*/
	infotype nMin;
	address P;
	/*ALGORITMA*/
	nMin = Min(L);
	P = Search(L, nMin);
	return (P);
}

infotype Average(List L)
/*Mengirimkan nilai rata-rata infotype dalam list*/
/*Prekondisi : list L tidak kosong*/
{
	/*KAMUS LOKAL*/
	infotype sum, avg;
	address P;
	/*ALGORITMA*/
	sum = info(First(L));
	P = next(First(L));
	while (P != Nil)
	{
		sum = sum + info(P);
		P = next(P);
	}
	avg = sum / NbElmt(L);
	return (avg);
}

void DelAll(List *L)
/*I.S. List mungkin kosong*/
/*F.S. List kosong, semua alamat elemen di-dealokasi*/
{
	/*KAMUS LOKAL*/
	address P;
	/*ALGORITMA*/
	while (First(*L) != Nil)
	{
		DelFirst(L, &P);
		Dealokasi(P);
	}
}

void InversList(List *L)
/*I.S. sembarang*/
/*F.S. elemen list dibalik : */
/*elemen terakhir menjadi elemen pertama, dst*/
/*Membalik elemen list, tanpa melakukan alokasi/dealokasi*/
{
	/*KAMUS LOKAL*/
	address P, Prec;
	int i, rip;
	/*ALGORITMA*/
	rip = NbElmt(*L) - 1;
	if ((rip != 0) && (rip != -1))
	{
		for (i = 1; i <= rip; i++)
		{
			if (i == 1)
			{
				DelLast(L, &P);
				InsertFirst(L, P);
				Prec = First(*L);
			}
			else
			{
				DelLast(L, &P);
				InsertAfter(L, P, Prec);
				Prec = next(Prec);
			}
		}
	}
}

List FInversList(List L)
/*Mengirimkan list baru, hasil invers dari L*/
/*dengan menyalin semua elemen list, alokasi mungkin gagal*/
/*jika alokasi gagal, hasilnya list kosong*/
/*dan semua elemen yang terlanjur di-alokasi harus didealokasi*/
{
	/*KAMUS LOKAL*/
	List L1;
	int count;
	address P, Pmove;
	boolean success;
	infotype X;
	/*ALGORITMA*/
	CreateList(&L1);
	P = First(L);
	success = true;
	while ((P != Nil) && (success))
	{
		X = info(P);
		Pmove = Alokasi(X);
		if (Pmove != Nil) /*Alokasi berhasil*/
		{
			InsertFirst(&L1, Pmove);
		}
		else /*Alokasi gagal Pmove==Nil*/
		{
			success = false;
			Dealokasi(Pmove);
			DelAll(&L1);
		}
		P = next(P);
	}
	return (L1);
}

void CopyList(List *L1, List *L2)
/*I.S. L1 sembarang*/
/*F.S. L2=L1*/
/*L1 dan L2 "menunjuk kepada list yang sama"*/
/*Tidak ada alokasi / dealokasi elemen*/
{
	/*KAMUS LOKAL*/
	/*ALGORITMA*/
	(*L2) = (*L1);
}

List FCopyList(List L)
/*Mengirimkan list yang merupakan salinan L*/
/*dengan melakukan alokasi*/
/*jika ada alokasi gagal, hasilnya list kosong dan*/
/*semua elemen yang terlanjur di-alokasi, harus didealokasi*/
{
	/*KAMUS LOKAL*/
	List L1;
	address P, Pcopy;
	boolean success;
	infotype X;
	/*ALGORITMA*/
	CreateList(&L1);
	P = First(L);
	success = true;
	while ((P != Nil) && (success))
	{
		X = info(P);
		Pcopy = Alokasi(X);
		if (Pcopy != Nil) /*Alokasi berhasil*/
		{
			InsertLast(&L1, Pcopy);
		}
		else /*Alokasi gagal Pcopy==Nil*/
		{
			success = false;
			Dealokasi(Pcopy);
			DelAll(&L1);
		}
		P = next(P);
	}
	return (L1);
}

void CpAlokList(List Lin, List *Lout)
/*I.S. Lin sembarang*/
/*F.S. Jika semua alokasi berhasil, maka Lout berisi hasil copy Lin*/
/*Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi*/
/*dengan melakukan alokasi elemen*/
/*Lout adalah list kosong jika ada alokasi elemen yang gagal*/
{
	/*KAMUS LOKAL*/
	address P, Pcopy;
	boolean success;
	infotype X;
	/*ALGORITMA*/
	P = First(Lin);
	success = true;
	while ((P != Nil) && (success))
	{
		X = info(P);
		Pcopy = Alokasi(X);
		if (Pcopy != Nil) /*Alokasi berhasil*/
		{
			InsertLast(Lout, Pcopy);
		}
		else /*Alokasi gagal Pcopy==Nil*/
		{
			success = false;
			Dealokasi(Pcopy);
			DelAll(Lout);
		}
		P = next(P);
	}
}

void konkat(List L1, List L2, List *L3)
/*I.S. L1 dan L2 sembarang*/
/*F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2*/
/*Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/*Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi harus didealokasi dan L3=Nil*/
/*Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang "baru"*/
/*Elemen L3 adalah hasil alokasi elemen yang "baru"*/
/*Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/*dan semua elemen yang pernah dialokasi didealokasi*/
{
	/*KAMUS LOKAL*/
	address P, P2, Pkon;
	boolean success;
	infotype X;
	/*ALGORITMA*/
	(*L3) = FCopyList(L1);
	if (((!ListEmpty(*L3)) || ((ListEmpty(L1)) && (ListEmpty(*L3)))) && (!ListEmpty(L2)))
	{
		P = First(*L3);
		while (next(P) != Nil)
		{
			P = next(P);
		}
		success = true;
		P2 = First(L2);
		while ((P2 != Nil) && (success))
		{
			X = info(P2);
			Pkon = Alokasi(X);
			if (Pkon != Nil) /*Alokasi berhasil*/
			{
				next(P) = Pkon;
				P = next(P);
			}
			else /*Alokasi gagal Pkon==Nil*/
			{
				success = false;
				Dealokasi(Pkon);
				DelAll(L3);
			}
			P2 = next(P2);
		}
	}
}

void konkat1(List *L1, List *L2, List *L3)
/*I.S. L1 dan L2 sembarang*/
/*F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2*/
/*Konkatenasi dua buah list : L1 dan L2*/
/*menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/*dan L1 serta L2 menjadi list kosong*/
/*Tidak ada alokasi/dealokasi pada prosedur ini*/
{
	/*KAMUS LOKAL*/
	address P, Prec;
	/*ALGORITMA*/
	(*L3) = (*L1);
	P = First(*L3);
	Prec = Nil;
	while (P != Nil)
	{
		Prec = P;
		P = next(P);
	}
	next(Prec) = First(*L2);
	First(*L1) = Nil;
	First(*L2) = Nil;
}

void PecahList(List *L1, List *L2, List L)
/*I.S. L mungkin kosong*/
/*F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2*/
/*L tidak berubah : untuk membentuk L1 dan L2 harus alokasi*/
/*L1 berisi separuh elemen L dan L2 berisi sisa elemen L*/
/*Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2*/
{
	/*KAMUS LOKAL*/
	int mid, i;
	address P, Psplit;
	infotype X;
	boolean success;
	/*ALGORITMA*/
	i = 1;
	mid = NbElmt(L) / 2;
	success = true;
	P = First(L);
	if (!ListEmpty(L))
	{
		if (NbElmt(L) == 1)
		{
			X = info(P);
			Psplit = Alokasi(X);
			if (Psplit != Nil) /*Alokasi berhasil*/
			{
				InsertFirst(L1, Psplit);
			}
		}
		else if (i <= mid)
		{
			while ((i <= mid) && (success))
			{
				X = info(P);
				Psplit = Alokasi(X);
				if (Psplit != Nil) /*Alokasi berhasil*/
				{
					InsertLast(L1, Psplit);
				}
				else /*Alokasi gagal*/
				{
					success = false;
					Dealokasi(Psplit);
					DelAll(L1);
				}
				i++;
				P = next(P);
			}
			while ((success) && (P != Nil))
			{
				X = info(P);
				Psplit = Alokasi(X);
				if (Psplit != Nil) /*Alokasi berhasil*/
				{
					InsertLast(L2, Psplit);
				}
				else /*Alokasi gagal*/
				{
					success = false;
					Dealokasi(Psplit);
					DelAll(L1);
					DelAll(L2);
				}
				P = next(P);
			}
		}
	}
}
