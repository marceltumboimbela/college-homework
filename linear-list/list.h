/*Nama : Shieny Aprilia*/
/*NIM : 13505089*/

/*File:list.h*/
/*Deklarasi list linier berkait dengan pointer*/
/*InfoType adalah integer*/

#ifndef list_H
#define list_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist
{
	infotype info;
	address next;
} Elmtlist;

/*Definisi list : */
/*List kosong : First (L)=Nil*/
/*Setiap elemen dengan address P dapat diacu info(P), next(P)*/
/*Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil*/

typedef struct
{
	address First;
} List;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) ((L).First)

/****Pembuatan List Kosong****/

void CreateList(List *L);
/*I.S. sembarang*/
/*F.S. Terbentuk list kosong*/

/****Test list kosong****/

boolean ListEmpty(List L);
/*Mengirim true jika list kosong*/

/****Manajemen memori****/

address Alokasi(infotype X);
/*Mengirimkan address hasil alokasi sebuah elemen*/
/*Jika alokasi berhasil, maka address tidak nil, dan misalnya*/
/*menghasilkan P, maka info(P)=X, Next(P)=Nil*/
/*Jika alokasi gagal, mengirimkan Nil*/

void Dealokasi(address P);
/*I.S. P terdefinisi*/
/*F.S. P dikembalikan ke sistem*/
/*Melakukan dealokasi/pengembalian address P*/

/****Primitif berdasarkan alamat****/
/****Penambahan elemen****/

void InsertFirst(List *L, address P);
/*I.S. sembarang, P sudah dialokasi*/
/*F.S. menambahkan elemen beraddress P sebagai elemen pertama*/

void InsertAfter(List *L, address P, address Prec);
/*I.S. Prec pastilah elemen list dan bukan elemen terakhir*/
/*	 P sudah dialokasi*/
/*Insert P sebagai elemen sesudah elemen beralamat Prec*/

void InsertLast(List *L, address P);
/*I.S. sembarang, P sudah dialokasi*/
/*F.S. P ditambahkan sebagai elemen terakhir yang baru*/

/****Penghapusan sebuah elemen****/

void DelFirst(List *L, address *P);
/*I.S. List tidak kosong*/
/*F.S. P adalah alamat elemen pertama list sebelum penghapusan*/
/*	 Elemen list berkurang satu (mungkin menjadi kosong)*/
/*First elemen yang baru adalah suksesor elemen pertama yang lama*/

void DelP(List *L, infotype X);
/*I.S. sembarang*/
/*F.S. Jika ada elemen list beraddress P, dengan info(P)=X*/
/*	 Maka P dihapus dari list dan didealokasi*/
/*	 Jika tidak ada elemen list dengan info(P)=X, maka list tetap*/
/*	 List mungkin menjadi kosong karena penghapusan*/

void DelLast(List *L, address *P);
/*I.S. List tidak kosong*/
/*F.S. P adalah alamat elemen terakhir list sebelum penghapusan*/
/*	 Elemen list berkurang satu (mungkin menjadi kosong)*/
/*	 Last elemen baru adalah predesesor last elemen yang lama jika ada*/

void DelAfter(List *L, address *Pdel, address Prec);
/*I.S. List tidak kosong, Prec adalah anggota list*/
/*F.S. Menghapus next(Prec)*/
/*	 Pdel adalah alamat elemen list yang dihapus*/

/****Primitif berdasarkan nilai****/
/****Penambahan elemen****/

void InsVFirst(List *L, infotype X);
/*I.S. L mungkin kosong*/
/*F.S. melakukan alokasi sebuah elemen*/
/*	 dan menambahkan elemen pertama dengan nilai X jika alokasi berhasil*/

void InsVLast(List *L, infotype X);
/*I.S. L mungkin kosong*/
/*F.S. melakukan alokasi sebuah elemen dan*/
/*	 menambahkan elemen list di akhir: elemen terakhir yang baru*/
/*	 bernilai X jika alokasi berhasil. Jika alokasi gagal:I.S.=F.S.*/

/****Penghapusan elemen****/

void DelVFirst(List *L, infotype *X);
/*I.S. list tidak kosong*/
/*F.S. Elemen pertama list dihapus : nilai info disimpan pada X*/
/*	 dan alamat elemen pertama di-dealokasi*/

void DelVLast(List *L, infotype *X);
/*I.S. list tidak kosong*/
/*F.S. Elemen terakhir list dihapus : nilai info disimpan pada X*/
/*	 dan alamat elemen terakhir di-dealokasi*/

/****Pencarian sebuah elemen list****/

address Search(List L, infotype X);
/*Mencari apakah ada elemen list dengan info(P)=X*/
/*Jika ada, mengirimkan address elemen tsb*/
/*Jika tidak ada, mengirimkan Nil*/

boolean FSearch(List L, address P);
/*Mencari apakah ada elemen list yang beralamat P*/
/*Mengirimkan true jika ada, false jika tidak ada*/

address SearchPrec(List L, infotype X);
/*mengirimkan address elemen sebelum elemen yang nilainya=X*/
/*mencari apakah ada elemen list dengan info(P)=X*/
/*jika ada, mengirimkan address Prec, dengan next(Prec)=P dan info(P)=X*/
/*jika tidak, mengirimkan Nil*/
/*Jika P adalah elemen pertama, maka Prec=Nil*/

address SearchLast(List L);
/*mengirimkan address elemen terakhir list*/

/****Proses semua elemen list****/

void PrintList(List L);
/*I.S. L mungkin kosong*/
/*F.S. info tiap elemen L sudah tertulis dengan First(L) ditulis lebih dulu*/

int NbElmt(List L);
/*Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong*/

infotype Max(List L);
/*Mengirimkan nilai info(P) yang maksimum*/
/*Prekondisi : list L tidak kosong*/

address AdrMax(List L);
/*Mengirimkan address P, dengan info(P) yang bernilai maksimum*/
/*Prekondisi : list L tidak kosong*/

infotype Min(List L);
/*Mengirimkan nilai info(P) yang minimum*/
/*Prekondisi : list L tidak kosong*/

address AdrMin(List L);
/*Mengirimkan address P, dengan info(P) yang bernilai minimum*/
/*Prekondisi : list L tidak kosong*/

infotype Average(List L);
/*Mengirimkan nilai rata-rata infotype dalam list*/
/*Prekondisi : list L tidak kosong*/

/**** Proses terhadap list****/

void DelAll(List *L);
/*I.S. List mungkin kosong*/
/*F.S. List kosong, semua alamat elemen di-dealokasi*/

void InversList(List *L);
/*I.S. sembarang*/
/*F.S. elemen list dibalik : */
/*elemen terakhir menjadi elemen pertama, dst*/
/*Membalik elemen list, tanpa melakukan alokasi/dealokasi*/

List FInversList(List L);
/*Mengirimkan list baru, hasil invers dari L*/
/*dengan menyalin semua elemen list, alokasi mungkin gagal*/
/*jika alokasi gagal, hasilnya list kosong*/
/*dan semua elemen yang terlanjur di-alokasi harus didealokasi*/

void CopyList(List *L1, List *L2);
/*I.S. L1 sembarang*/
/*F.S. L2=L1*/
/*L1 dan L2 "menunjuk kepada list yang sama"*/
/*Tidak ada alokasi / dealokasi elemen*/

List FCopyList(List L);
/*Mengirimkan list yang merupakan salinan L*/
/*dengan melakukan alokasi*/
/*jika ada alokasi gagal, hasilnya list kosong dan*/
/*semua elemen yang terlanjur di-alokasi, harus didealokasi*/

void CpAlokList(List Lin, List *Lout);
/*I.S. Lin sembarang*/
/*F.S. Jika semua alokasi berhasil, maka Lout berisi hasil copy Lin*/
/*Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi*/
/*dengan melakukan alokasi elemen*/
/*Lout adalah list kosong jika ada alokasi elemen yang gagal*/

void konkat(List L1, List L2, List *L3);
/*I.S. L1 dan L2 sembarang*/
/*F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2*/
/*Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/*Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi harus didealokasi dan L3=Nil*/
/*Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang "baru"*/
/*Elemen L3 adalah hasil alokasi elemen yang "baru"*/
/*Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/*dan semua elemen yang pernah dialokasi didealokasi*/

void konkat1(List *L1, List *L2, List *L3);
/*I.S. L1 dan L2 sembarang*/
/*F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2*/
/*Konkatenasi dua buah list : L1 dan L2*/
/*menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/*dan L1 serta L2 menjadi list kosong*/
/*Tidak ada alokasi/dealokasi pada prosedur ini*/

void PecahList(List *L1, List *L2, List L);
/*I.S. L mungkin kosong*/
/*F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2*/
/*L tidak berubah : untuk membentuk L1 dan L2 harus alokasi*/
/*L1 berisi separuh elemen L dan L2 berisi sisa elemen L*/
/*Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2*/

#endif
