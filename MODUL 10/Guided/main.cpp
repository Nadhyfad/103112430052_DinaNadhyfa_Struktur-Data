#include "tree.h"
#include "tree.cpp"
#include <iostream>

using namespace std;

int main(){
    BinaryTree tree;

    cout << "=== INSERT DATA ===" << endl;
    tree.insert(10);
    tree.insert(15);
    tree.insert(20);
    tree.insert(30);
    tree.insert(35);
    tree.insert(40);
    tree.insert(50);

    cout << "Data yang diinsert: 10, 15, 20, 30, 35, 40, 50" << endl;

    cout << "\nTraversal setelah insert:" << endl;
    cout << "Inorder    : "; tree.inOrder();
    cout << "Preorder   : "; tree.preOrder();
    cout << "Postorder  : "; tree.postOrder();

    cout << "\n=== UPDATE DATA ===" << endl;
    cout << "Sebelum update (20 -> 25)" << endl;
    cout << "Inorder    : "; tree.inOrder();

    tree.update(20, 25);

    cout << "Setelah update (20 -> 25)" << endl;
    cout << "Inorder    : "; tree.inOrder();

    cout << "\n=== DELETE DATA ===" << endl;
    cout << "Sebelum delete (hapus subtree denga root = 30)" << endl;
    cout << "Inorder    : "; tree.inOrder();

    tree.deleteValue(30);

    cout << "Setelah delete (subtree root = 30 dihapus)" << endl;
    cout << "Inorder    : "; tree.inOrder();

    return 0;
}
