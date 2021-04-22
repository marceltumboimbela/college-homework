#include "Stackt.h"
#include "Stackt.c"

int main()
{
    /*Kamus*/
    Stack S1;
    Stack S2;
    int i;
    int X = 99;
    int Size = 10;
    /*Algoritma*/
    CreateEmpty(&S1, &Size);
    printf("%d\n", Top(S1));
    if (IsEmpty(S1))
    {
        printf("tabel kosong\n");
    }
    else
    {
        printf("tabel tidak kosong\n");
    }
    CreateEmpty(&S2, &Size);
    for (i = 1; i <= Size(S2); i++)
    {
        Top(S2) = i;
        InfoTop(S2) = i;
    }
    if (IsFull(S1))
    {
        printf("tabel penuh\n");
    }
    else
    {
        printf("tabel belum penuh\n");
    }
    printf("%d\n", Top(S1));
    Push(&S1, X);
    printf("%d\n", Top(S1));
    printf("%d\n", InfoTop(S1));
    if (IsFull(S1))
    {
        printf("Stack penuh\n");
    }
    else
    {
        Push(&S1, X);
    }
    printf("%d\n", Top(S1));
    printf("%d\n", InfoTop(S1));

    if (IsFull(S2))
    {
        printf("Stack penuh\n");
    }
    else
    {
        Push(&S2, X);
    }
    printf("%d\n", Top(S2));
    printf("%d\n", InfoTop(S2));

    CreateEmpty(&S1, &Size);

    if (IsEmpty(S1))
    {
        printf("Stack kosong\n");
    }
    else
    {
        Pop(&S1, &X);
    }
    printf("%d\n", Top(S1));
    printf("%d\n", InfoTop(S1));
    printf("%d\n", X);

    if (IsEmpty(S2))
    {
        printf("Stack kosong\n");
    }
    else
    {
        Pop(&S2, &X);
    }
    printf("%d\n", Top(S2));
    printf("%d\n", InfoTop(S2));
    printf("%d\n", X);

    Destruct(&S1);

    Destruct(&S2);

    scanf("%d");
}
