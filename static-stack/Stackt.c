#include "Stackt.h"

/*Konstruktor*/
void CreateEmpty(Stack *S)
/*I.S. sembarang*/
/*F.S. membuat stack yang kosong dengan kapasitas MaxEl*/
/*indexnya 1..MaxEl 0 tidak dipakai*/
/*Ciri stack kosong : TOP bernilai Nil*/
{
  /*Kamus*/
  /*Algoritma*/
  TopPtr(S) = Nil;
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
  return (Top(S) == MaxEl);
}

void Push(Stack *S, infotype X)
/*I.S. S mungkin kosong,tabel penampung element tidak penuh*/
/*F.S. X menjadi TOP yang baru,TOP bertambah 1*/
{
  /*Kamus*/
  /*Algoritma*/
  TopPtr(S) += 1;
  InfoTopPtr(S) = X;
}

void Pop(Stack *S, infotype *X)
/*I.S. S tidak mungkin kosong*/
/*F.S. X adalah nilai element TOP yang lama,TOP berkurang 1*/
{
  /*Kamus*/
  /*Algoritma*/
  *X = InfoTopPtr(S);
  TopPtr(S) -= 1;
}
