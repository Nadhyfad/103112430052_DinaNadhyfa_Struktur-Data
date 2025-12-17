#include <iostream>
#include "unguided-queue.h"
using namespace std;

// Membuat queue kosong
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

// Mengecek apakah queue kosong
bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

// Mengecek apakah queue penuh (Alternatif 2)
bool isFullQueue(Queue Q) {
    // Queue penuh jika tail sudah mencapai index maksimal (4)
    return (Q.tail == 4);
}

// Menambahkan elemen ke queue (Alternatif 2)
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            // Queue kosong, inisialisasi head dan tail
            Q.head = 0;
            Q.tail = 0;
        } else {
            // Tail bergerak maju
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

// Menghapus elemen dari queue (Alternatif 2)
infotype dequeue(Queue &Q) {
    infotype x = 0;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        x = Q.info[Q.head];
        
        // ALTERNATIF 2: head bergerak, tail diam (tanpa pergeseran)
        if (Q.head == Q.tail) {
            // Queue hanya memiliki 1 elemen
            Q.head = -1;
            Q.tail = -1;
        } else {
            // Head bergerak maju tanpa menggeser elemen
            Q.head++;
        }
    }
    return x;
}

// Menampilkan isi queue (Alternatif 2)
void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        // ALTERNATIF 2: tampilkan dari head sampai tail secara linear
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) cout << " ";
        }
    }
    cout << endl;
}
