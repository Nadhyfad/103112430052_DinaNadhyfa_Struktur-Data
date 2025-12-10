#include "circularlist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    if (L.First == Nil) {
        // List kosong, buat circular
        L.First = P;
        P->next = P;
    } else {
        address Last = L.First;
        while (Last->next != L.First) {
            Last = Last->next;
        }
        P->next = L.First;
        Last->next = P;
        L.First = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        P->next = P;
    } else {
        address Last = L.First;
        while (Last->next != L.First) {
            Last = Last->next;
        }
        P->next = L.First;
        Last->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        if (L.First->next == L.First) {
            L.First = Nil;
        } else {
            address Last = L.First;
            while (Last->next != L.First) {
                Last = Last->next;
            }
            L.First = L.First->next;
            Last->next = L.First;
        }
        P->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != L.First) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != Nil) {
        if (L.First->next == L.First) {
            P = L.First;
            L.First = Nil;
        } else {
            address Prec = L.First;
            while (Prec->next->next != L.First) {
                Prec = Prec->next;
            }
            P = Prec->next;
            Prec->next = L.First;
        }
        P->next = Nil;
    }
}

address findElm(List L, infotype x) {
    if (L.First == Nil) {
        return Nil;
    }
    
    address P = L.First;
    do {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    } while (P != L.First);
    
    return Nil;
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong" << endl;
        return;
    }
    
    cout << "coba insert first, last, dan after" << endl;
    address P = L.First;
    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "JK   : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl;
        cout << endl;
        P = P->next;
    } while (P != L.First);
}