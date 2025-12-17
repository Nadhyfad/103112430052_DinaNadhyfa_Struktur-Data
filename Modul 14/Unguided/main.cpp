#include "graph.h"
#include "graph.cpp"

int main() {
    Graph G;
    createGraph(G);
    
    // Tambah node sesuai gambar ilustrasi (A, B, C, D, E, F, G, H)
    insertNode(G, 'H');
    insertNode(G, 'G');
    insertNode(G, 'F');
    insertNode(G, 'E');
    insertNode(G, 'D');
    insertNode(G, 'C');
    insertNode(G, 'B');
    insertNode(G, 'A');

    // Hubungkan node sesuai dengan gambar ilustrasi di modul
    // Dari gambar: A terhubung dengan B dan C
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    
    // B terhubung dengan D dan E
    connectNode(G, 'B', 'D');
    connectNode(G, 'B', 'E');
    
    // C terhubung dengan F dan G
    connectNode(G, 'C', 'F');
    connectNode(G, 'C', 'G');
    
    // D, E, F, G semuanya terhubung ke H
    connectNode(G, 'D', 'H');
    connectNode(G, 'E', 'H');
    connectNode(G, 'F', 'H');
    connectNode(G, 'G', 'H');

    cout << "\n=== Struktur Graph ===" << endl;
    printInfoGraph(G);

    /* UNTUK UNGUIDED 1
    cout << "\n=== Traversal DFS dari node A ===" << endl;
    resetVisited(G);
    printDFS(G, findNode(G, 'A'));

    cout << "\n\n=== Traversal BFS dari node A ===" << endl;
    resetVisited(G);
    printBFS(G, findNode(G, 'A'));
    */

    /* UNTUK UNGUIDED NOMOR 2
    cout << "\n=== DFS Traversal dari node A ===" << endl;
    resetVisited(G);
    printDFS(G, findNode(G, 'A'));
    cout << endl;
    */

    /* UNTUK UNGUIDED 3  
    cout << "\n=== BFS Traversal dari node A ===" << endl;
    resetVisited(G);
    printBFS(G, findNode(G, 'A'));
    */

    cout << endl;
    return 0;
}
