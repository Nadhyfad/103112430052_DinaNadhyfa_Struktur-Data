#include "queue.h"
#include <iostream>

using namespace std; // menggunakanan namespace std agar tidak perlu menulis std:: setiap kali

// definisi prosedur dan fungsi untuk membuat queue kosong
void createQueue(Queue &Q) {
    Q.head = 0; // set kepala ke indeks 0
    Q.tail = 0; // set ekor ke indeks 0
    Q.count = 0; // set jumlah elemen ke 0
}

// definisi fungsi untuk mengecek apakah queue kosong
bool isEmpty(Queue Q) {
    return Q.count == 0; // kembalikan true jika jumlah elemen 0
}

// definisi fungsi untuk mengecek apakah queue penuh
bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // kembalikan true jika jumlah elemen sama dengan
}

// definisi prosedur untuk menambahkan elemen ke dalam queue (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { // jika queue tidak penuh
        Q.info[Q.tail] = x; // masukkan data (x) ke posisi ekor (tail)
        // pindahkan ekor secara memutar
        Q.tail = (Q.tail + 1) % MAX_QUEUE; // update posisi ekor secara melingkar
        Q.count++; // tambah jumlah elemen
    } else { //jika queue penuh
        cout << "Antrean penuh!" << endl; // tampilkan pesan jika queue penuh
    }
}

// definisi fungsi untuk menghapus elemen dari queue (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { // jika queue tidak kosong
        int x = Q.info[Q.head]; // ambil data dari posisi kepala (head)
        // pindahkan kepala secara memutar
        Q.head = (Q.head + 1) % MAX_QUEUE; // update posisi kepala secara melingkar
        Q.count--; // kurangi jumlah elemen
        return x; // kembalikan data yang dihapus
    } else { // jika queue kosong
        cout << "Antrean kosong!" << endl; // tampilkan pesan jika queue kosong
        return -1; // kembalikan nilai -1 sebagai indikasi queue kosong
    }
}

// definisi prosedur untuk menampilkan isi queue
void printInfo(Queue Q) {
    cout << "Isi queue: [ "; // tampilkan judul
    if (!isEmpty(Q)) {
        int i = Q.head;
        int n = 0;
        while (n < Q.count) {
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_QUEUE;
            n++;
        }
    }
    cout << "]" << endl; // akhiri tampilan isi queue
}