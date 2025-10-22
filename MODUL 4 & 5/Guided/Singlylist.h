#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>

#define Nil NULL

typedef int infotype;
typedef struct Elmlist *address;

struct Elmlist{
    infotype info;
    address next;
};

struct List{
    address first;
};

// deklarasi prosedur dan fungsi primitif
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void PrintInfo(List L);

#endif // SINGLYLIST_H_INCLUDED