//103112430052_Dina Nadhyfa

#include "Playlist.h"
#include <iostream>

void createList(List &L) {
    L.first = NULL;
}

address alokasi(string judul, string penyanyi, float durasi) {
    address P = new elmlist;
    P->info.judul = judul;
    P->info.penyanyi = penyanyi;
    P->info.durasi = durasi;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteLagu(List &L, string judul) {
    address P = findElm(L, judul);
    if (P == NULL) {
        cout << "Lagu tidak ditemukan." << endl;
        return;
    }

    if (P == L.first) {
        L.first = P->next;
        dealokasi(P);
    } else {
        address prev = L.first;
        while (prev->next != P) {
            prev = prev->next;
        }
        prev->next = P->next;
        dealokasi(P);
    }
    cout << "Lagu \"" << judul << "\" berhasil dihapus." << endl;
}

void printInfo(List L) {
    address P = L.first;
    int i = 1;
    if (P == NULL) {
        cout << "Playlist kosong." << endl;
    } else {
        while (P != NULL) {
            cout << i << ". " << P->info.judul << " - " << P->info.penyanyi 
                 << " (" << P->info.durasi << " menit)" << endl;
            P = P->next;
            i++;
        }
    }
}

address findElm(List L, string judul) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.judul == judul) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}