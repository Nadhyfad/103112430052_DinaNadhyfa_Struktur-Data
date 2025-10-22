#include "Singlylist.h"

void createList(List &L){
    L.first = Nil;
}

address alokasi(infotype x){
    address P = new Elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P){
    delete P;
}

void insertFirst(List &L, address P){
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, address P){
    if (L.first == Nil) {
        // jika list kosong, insertlast sama dengan insertfirst
        insertFirst(L, P);
    } else {
        // jika list tidak kosong, cari elemen terakhir
        address Last = L.first;
        while (Last->next != Nil) {
            Last = Last->next;
        }
        // sambungkan elemen terakhir ke elemen baru (P)
        Last->next = P;
    }
}

void printInfo(List L){
    address P = L.first;
   if (P == Nil) {
        std::cout << "List kosong" << std::endl;
    } else {
        while (P != Nil) {
            std::cout << P->info << " ";
            P = P->next;
        }
        std::cout << std::endl;
    }
}