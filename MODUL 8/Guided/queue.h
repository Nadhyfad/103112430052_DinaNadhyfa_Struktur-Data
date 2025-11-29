#ifndef QUEUE_H // Jika QUEUE_H belum didefinisikan
#define QUEUE_H // maka definisikan QUEUE_H untuk mencegah multiple inclusion

#define MAX_QUEUE 5 // menentukan ukuran maksimum queue

//mendefinisikan tipe data Queue
struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q); // prosedur untuk membuat queue kosong
bool isEmpty(Queue Q); // fungsi untuk mengecek apakah queue kosong
bool isFull(Queue Q); // fungsi untuk mengecek apakah queue penuh
void enqueue(Queue &Q, int x); // prosedur untuk menambahkan elemen ke dalam queue
int dequeue(Queue &Q); // fungsi untuk menghapus elemen dari queue
void printInfo(Queue Q); // prosedur untuk menampilkan isi queue

#endif // akhir dari definisi QUEUE_H
