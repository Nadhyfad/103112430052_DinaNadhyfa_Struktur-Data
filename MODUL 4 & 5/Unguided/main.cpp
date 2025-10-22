//103112430052_Dina Nadhyfa

#include <iostream>
#include "Playlist.h"
using namespace std;

int main() {
    List L;
    createList(L);

    // Tambah lagu di awal
    address P1 = alokasi("Joyride", "CORTIS", 2.52);
    insertFirst(L, P1);

    address P2 = alokasi("Same Dream, Same Mind, Same Night", "Seventeen", 4.08);
    insertFirst(L, P2);

    // Tambah lagu di akhir
    address P3 = alokasi("Fall In Love Again", "P1Harmony", 3.29);
    insertLast(L, P3);

    // Tambah lagu setelah lagu ke-3
    address P4 = alokasi("Blue Valentine", "NMIXX", 3.06);
    address Prec = L.first;
    for (int i = 1; i < 3 && Prec != NULL; i++) {
        Prec = Prec->next;
    }
    if (Prec != NULL) {
        insertAfter(L, P4, Prec);
    }

    // Tampilkan playlist
    cout << "Playlist Awal:" << endl;
    printInfo(L);
    cout << endl;

    // Hapus lagu berdasarkan judul
    deleteLagu(L, "Same Dream, Same Mind, Same Night");
    cout << endl;

    // Tampilkan playlist setelah penghapusan
    cout << "Playlist Setelah Penghapusan:" << endl;
    printInfo(L);

    return 0;
}