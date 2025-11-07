// 103112430052_Dina Nadhyfa

#ifndef STACK_H
#define STACK_H

const int MAX_SIZE = 20;

typedef int infotype;

struct Stack {
    infotype info[MAX_SIZE];
    int top;
};

// Prototype fungsi
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
// menambahkan prosedur baru, seperti di latihan soal nomor 2
void pushAscending(Stack &S, infotype x);
// menambahkan prosedur baru, seperti di latihan soal nomor 3
void getInputStream(Stack &S);

#endif
