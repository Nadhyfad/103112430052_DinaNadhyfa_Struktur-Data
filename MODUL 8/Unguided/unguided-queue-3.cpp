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

// Mengecek apakah queue penuh (Alternatif 3 - Circular)
bool isFullQueue(Queue Q) {
    // Queue penuh jika posisi berikutnya dari tail adalah head
    return ((Q.tail + 1) % 5 == Q.head);
}

// Menambahkan elemen ke queue (Alternatif 3 - Circular)
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            // Queue kosong, inisialisasi head dan tail
            Q.head = 0;
            Q.tail = 0;
        } else {
            // Tail berputar (circular) menggunakan modulo
            Q.tail = (Q.tail + 1) % 5;
        }
        Q.info[Q.tail] = x;
    }
}

// Menghapus elemen dari queue (Alternatif 3 - Circular)
infotype dequeue(Queue &Q) {
    infotype x = 0;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        x = Q.info[Q.head];
        
        // ALTERNATIF 3: head dan tail berputar (circular)
        if (Q.head == Q.tail) {
            // Queue hanya memiliki 1 elemen
            Q.head = -1;
            Q.tail = -1;
        } else {
            // Head berputar (circular) menggunakan modulo
            Q.head = (Q.head + 1) % 5;
        }
    }
    return x;
}

// Menampilkan isi queue (Alternatif 3 - Circular)
void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        // ALTERNATIF 3: tampilkan dengan cara berputar (circular)
        int i = Q.head;
        while (true) {
            cout << Q.info[i];
            if (i == Q.tail) break;
            cout << " ";
            i = (i + 1) % 5; // Berputar menggunakan modulo
        }
    }
    cout << endl;
}
