Tree bfs(Graph G, Vertex start) {
    Queue Q;
    Marktype mark;
    Tree T;
    Vertex x, y;

    // Initialization of the variables
    initQueue(&Q);                        // Blank_01
    memset(mark, 0, sizeof(mark));        // Blank_02
    T.count = 0;                          // Blank_03

    mark[start] = 1;                      // Blank_04
    enqueue(&Q, start);                   // Blank_05

    while (!emptyQueue(Q)) {              // Blank_06
        x = front(Q);                     // Blank_07
        dequeue(&Q);                      // Blank_08
        for (y = 0; y < GRAPH_SIZE; y++) {// Blank_09
            if (G[x][y] == 1) {           // Blank_10
                if (mark[y] == 0) {       // Blank_11
                    mark[y] = 1;          // Blank_12
                    enqueue(&Q, y);       // Blank_13
                    treeArc arc = {x, y}; // Blank_14
                    T.arcs[T.count++] = arc; // Blank_15
                }
            }
        }
    }
    return T;
}
