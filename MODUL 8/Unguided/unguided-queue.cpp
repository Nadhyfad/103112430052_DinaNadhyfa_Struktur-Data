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

// Mengecek apakah queue penuh
bool isFullQueue(Queue Q) {
    return (Q.tail == 4); // Index maksimal array adalah 4 (0-4)
}

// Menambahkan elemen ke queue
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

// Menghapus elemen dari queue
infotype dequeue(Queue &Q) {
    infotype x = 0;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    } else {
        x = Q.info[Q.head];
        
        /* ALTERNATIF 1: head diam, tail bergerak (dengan pergeseran)
        if (Q.head == Q.tail) {
            // Queue hanya memiliki 1 elemen
            Q.head = -1;
            Q.tail = -1;
        } else {
            // Geser semua elemen ke depan
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
        */
        
        /* ALTERNATIF 2: head bergerak, tail bergerak (tanpa pergeseran)
        if (Q.head == Q.tail) {
            // Queue hanya memiliki 1 elemen
            Q.head = -1;
            Q.tail = -1;
        } else {
            // Head maju
            Q.head++;
        }
        */
        
        /* ALTERNATIF 3: head dan tail berputar (circular)
        if (Q.head == Q.tail) {
            // Queue hanya memiliki 1 elemen
            Q.head = -1;
            Q.tail = -1;
        } else {
            // Head berputar (circular)
            Q.head = (Q.head + 1) % 5;
        }
        */
    
    }
    return x;
}

// Menampilkan isi queue
void printInfo(Queue Q) {
    cout << " " << Q.head << " - " << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        /* ALTERNATIF 1 & 2: tampilkan dari head sampai tail
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) cout << " ";
        }
        */
        
        /* ALTERNATIF 3: tampilkan dengan cara berputar (circular)
        int i = Q.head;
        while (true) {
            cout << Q.info[i];
            if (i == Q.tail) break;
            cout << " ";
            i = (i + 1) % 5; // Berputar
        }
        */
    }
    cout << endl;
}
