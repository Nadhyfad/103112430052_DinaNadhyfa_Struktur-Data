#include <iostream>
#include "bstree.h"

using namespace std;

/* alokasi node */
address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

/* insert node ke BST */
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    /* jika sama, tidak dimasukkan */
}

/* mencari node */
address findNode(infotype x, address root) {
    if (root == Nil || root->info == x)
        return root;
    else if (x < root->info)
        return findNode(x, root->left);
    else
        return findNode(x, root->right);
}

/* traversal inorder */
void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

/* menghitung jumlah node */
int hitungNode(address root) {
    if (root == Nil)
        return 0;
    else
        return 1 + hitungNode(root->left) + hitungNode(root->right);
}

/* menghitung total seluruh info node */
int hitungTotal(address root) {
    if (root == Nil)
        return 0;
    else
        return root->info
             + hitungTotal(root->left)
             + hitungTotal(root->right);
}

/* menghitung kedalaman maksimum tree */
int hitungKedalaman(address root, int start) {
    if (root == Nil)
        return start;

    int kiri  = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan) ? kiri : kanan;
}

/* traversal PreOrder */
void PreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

/* traversal PostOrder */
void PostOrder(address root) {
    if (root != Nil) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->info << " - ";
    }
}