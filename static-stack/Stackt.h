/*File stackt.h*/
/*deklarasi satackt dengan tabel kontigue*/
/*dan ukuran sama*/
/*TOP adalah alamat element puncak*/
/*Implementasi dalam bahasa C dengan alokasi statik*/

#ifndef stackt_H
#define stackt_H
#include "boolean.h"
#define Nil 0
#define MaxEl 10

/*Nil adalh stackt dengan element kosong*/
/*Karena index dalam bahasa C dimulai dengan 0 maka tabel dengan index 0 tidak dipakai*/
typedef char infotype;
typedef int address;
/*Contoh deklarasi variable bertype stackt dengan ciri TOP:*/
/*Versi 1 : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
        infotype T[MaxEl + 1];
        address TOP;
} Stack;

/*definisi stack S kosong : S.TOP = Nil*/
/*element yang dipakai menyimpan nilai Stack T[1]..T[MaxEl]*/
/*Jika S adalah stack maka akses element:*/
/*S.TOP adalah alamat element TOP*/
/*S.T[(S.TOP)] untuk mengakses element TOP*/
/*definifi akses dengan selektor: Set dan Get*/
#define Top(S) (S).TOP
//#define TopPtr(S) (*S).TOP
#define InfoTop(S) (S).T[(S.TOP)]
//#define InfoTopPtr(S) (*S).T[((*S).TOP)]

/*------ProtoType-------*/

/*Konstruktor*/
void CreateEmpty(Stack *S);
/*I.S. sembarang*/
/*F.S. membuat stack yang kosong dengan kapasitas MaxEl*/
/*indexnya 1..MaxEl 0 tidak dipakai*/
/*Ciri stack kosong : TOP bernilai Nil*/

boolean IsEmpty(Stack S);
/*Mengirim true bila stack kosong*/

boolean IsFull(Stack S);
/*Mengirin true jika tabel penampung nilai element stack penuh*/

void Push(Stack *S, infotype X);
/*I.S. S mungkin kosong,tabel penampung element tidak penuh*/
/*F.S. X menjadi TOP yang baru,TOP bertambah 1*/

void Pop(Stack *S, infotype *X);
/*I.S. S tidak mungkin kosong*/
/*F.S. X adalah nilai element TOP yang lama,TOP berkurang 1*/

#endif
