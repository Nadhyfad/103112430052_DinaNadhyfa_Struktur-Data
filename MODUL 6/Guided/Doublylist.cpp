#include "Doublylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

// Mengalokasikan memori untuk elemen baru
address alokasi(infotype X) {
    address P = new ElmList;
    P->info = X;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

// Dealokasi memori
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Menampilkan semua informasi dalam list
void printInfo(List L) {
    if (L.First == NULL) {
        cout << "List kosong" << endl;
        return;
    }
    
    address P = L.First;
    while (P != NULL) {
        cout << "nopol    : " << P->info.nopol << endl;
        cout << "warna    : " << P->info.warna << endl;
        cout << "tahun    : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }
}

// Menyisipkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.First == NULL) {
        // List kosong
        L.First = P;
        L.Last = P;
    } else {
        // List tidak kosong
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

// Fungsi baru soal nomor 2: Mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL; // Tidak ditemukan
}

// Fungsi tambahan soal nomor 2: Mengecek apakah nomor polisi sudah ada
bool isNopolExist(List L, string nopol) {
    return findElm(L, nopol) != NULL;
}

// fungsi baru soal nomor 3: Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL;
        return;
    }
    
    P = L.First;
    if (L.First == L.Last) { // Hanya satu elemen
        L.First = NULL;
        L.Last = NULL;
    } else { // Lebih dari satu elemen
        L.First = L.First->next;
        L.First->prev = NULL;
        P->next = NULL;
    }
}

// fungsi baru soal nomor 3: Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.Last == NULL) {
        P = NULL;
        return;
    }
    
    P = L.Last;
    if (L.First == L.Last) { // Hanya satu elemen
        L.First = NULL;
        L.Last = NULL;
    } else { // Lebih dari satu elemen
        L.Last = L.Last->prev;
        L.Last->next = NULL;
        P->prev = NULL;
    }
}

//fungsi baru soal nomor 3: Menghapus elemen setelah Prec
void deleteAfter(address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
        return;
    }
    
    P = Prec->next;
    Prec->next = P->next;
    
    if (P->next != NULL) {
        P->next->prev = Prec;
    }
    
    P->next = NULL;
    P->prev = NULL;
}

// Fungsi utama untuk menghapus berdasarkan nomor polisi
bool deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    
    if (P == NULL) {
        return false; // Data tidak ditemukan
    }
    
    address deletedNode;
    
    if (P == L.First) {
        // Hapus elemen pertama
        deleteFirst(L, deletedNode);
        dealokasi(deletedNode);
    } else if (P == L.Last) {
        // Hapus elemen terakhir
        deleteLast(L, deletedNode);
        dealokasi(deletedNode);
    } else {
        // Hapus elemen di tengah
        deleteAfter(P->prev, deletedNode);
        dealokasi(deletedNode);
    }
    
    return true;
}