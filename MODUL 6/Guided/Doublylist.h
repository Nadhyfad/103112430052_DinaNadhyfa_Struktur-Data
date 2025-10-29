#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

struct infotype {
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// Prosedur dan fungsi yang harus diimplementasi
void CreateList(List &L);
address alokasi(infotype X);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, string nopol);  // Fungsi baru sesuai seperti yang ada di soal nomor 2

// Fungsi delete baru soal nomor 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
bool deleteByNopol(List &L, string nopol);

// Fungsi tambahan untuk membantu pengecekan nopol
bool isNopolExist(List L, string nopol);

#endif