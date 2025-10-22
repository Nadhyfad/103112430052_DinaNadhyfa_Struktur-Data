//103112430052_Dina Nadhyfa

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    float durasi;
};

typedef struct elmlist *address;

struct elmlist {
    Lagu info;
    address next;
};

struct List {
    address first;
};

// Primitive functions
void createList(List &L);
address alokasi(string judul, string penyanyi, float durasi);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void deleteLagu(List &L, string judul);
void printInfo(List L);
address findElm(List L, string judul);

#endif