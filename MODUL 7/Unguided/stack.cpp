// 103112430052_Dina Nadhyfa

#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX_SIZE - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -1; // Nilai default jika stack kosong
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    
    // Pindahkan semua elemen dari S ke temp
    while (S.top >= 0) {
        push(temp, pop(S));
    }
    
    // Salin kembali dari temp ke S (sudah terbalik)
    S = temp;
}

// menambahkan prosedur pushAscending sesuai latihan soal nomor 2
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    
    // Pindahkan elemen dari S ke temp sampai menemukan posisi yang tepat
    while (S.top >= 0 && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    
    // Push elemen baru
    push(S, x);
    
    // Kembalikan elemen dari temp ke S
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

// menambahkan prosedur getInputStream sesuai latihan soal nomor 3
void getInputStream(Stack &S) {
    char ch;
    
    // Baca karakter satu per satu hingga enter
    while (true) {
        ch = cin.get();
        
        // Jika tombol enter ditekan, keluar dari loop
        if (ch == '\n') {
            break;
        }
        
        // Jika karakter adalah digit, konversi ke integer dan push ke stack
        if (isdigit(ch)) {
            int digit = ch - '0'; // Konversi char ke int
            push(S, digit);
        }
    }
}