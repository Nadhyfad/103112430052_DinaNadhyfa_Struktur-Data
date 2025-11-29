#include "queue.h"
#include "queue.cpp"
#include <iostream>

using namespace std; // menggunakanan namespace std agar tidak perlu menulis std:: setiap kali

// fungsi utama program
int main() {
    Queue Q; // deklarasi variabel Q bertipe Queue
    
    createQueue(Q); // membuat queue kosong
    printInfo(Q); // menampilkan isi queue (harusnya kosong)

    cout << "\nEnqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    
    cout << "\nDequeue 1 elemen" << endl;
    // hapus 1 elemen dari queue dan menampilkannya
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q); // menampilkan isi queue setelah dequeue

    cout << "\nEnqueue 1 elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\nDequeue 2 elemen" << endl;
    // hapus 1 elemen dan tampilkannya
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    // hapus 1 elemen dan tampilkannya
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q); // menampilkan isi queue setelah dequeue

    return 0; // mengembalikan nilai 0 menandakan program selesai dengan sukses
}