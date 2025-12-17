void printDFS(Graph &G, adrNode N) {
    if (N == NULL) {
        return;
    }
    
    N->visited = 1;
    
    cout << N->info << " ";
    
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->node->visited == 0) {
            printDFS(G, E->node);
        }
        E = E->next;
    }
}
