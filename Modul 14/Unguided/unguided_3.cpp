void printBFS(Graph &G, adrNode N) {
    if (N == NULL) {
        return;
    }
    
    queue<adrNode> Q;
    
    Q.push(N);
    
    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        
        if (curr->visited == 0) {
            curr->visited = 1;
            
            cout << curr->info << " ";
            
            adrEdge E = curr->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    Q.push(E->node);
                }
                E = E->next;
            }
        }
    }
}
