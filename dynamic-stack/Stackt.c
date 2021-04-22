#include "Stackt.h"
#include <stdlib.h>
#include "stdio.h"

/*Konstruktor*/
void CreateEmpty(Stack *S, int Size)
/*I.S. sembarang*/
/*F.S. membuat stack yang kosong dengan kapasitas MaxEl*/
/*indexnya 1..MaxEl 0 tidak dipakai*/
/*Ciri stack kosong : TOP bernilai Nil*/
{
    /*Kamus*/
    /*Algoritma*/
    (*S).T = (infotype *)malloc((Size + 1) * sizeof(infotype));
    if ((*S).T == NULL) /*alokasi gagal*/
    {
        Top(*S) = Nil;
        Size(*S) = 0;
    }
    else
    {
        Top(*S) = Nil;
    }
    Size(*S) = Size;
}

boolean IsEmpty(Stack S)
/*Mengirim true bila stack kosong*/
{
    /*Kamus*/
    /*Algoritma*/
    return (Top(S) == Nil);
}

boolean IsFull(Stack S)
/*Mengirin true jika tabel penampung nilai element stack penuh*/
{
    /*Kamus*/
    /*Algoritma*/
    return (Top(S) == Size(S));
}

void Push(Stack *S, infotype X)
/*I.S. S mungkin kosong,tabel penampung element tidak penuh*/
/*F.S. X menjadi TOP yang baru,TOP bertambah 1*/
{
    /*Kamus*/
    /*Algoritma*/
    Top(*S) += 1;
    InfoTop(*S) = X;
}

void Pop(Stack *S, infotype *X)
/*I.S. S tidak mungkin kosong*/
/*F.S. X adalah nilai element TOP yang lama,TOP berkurang 1*/
{
    /*Kamus*/
    /*Algoritma*/
    *X = InfoTop(*S);
    Top(*S) -= 1;
}

void Destruct(Stack *S)
/*destruktor:dealokasi seluruh tabel memori sekaligus*/
{
    /*Kamus*/
    /*Algoritma*/
    free((*S).T);
    Top(*S) = Nil;
    Size(*S) = 0;
}
