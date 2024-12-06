#define SENTINEL 999   // for infinity ω
#define MAX_VERTEX 10  // vertices 0, 1, 2,..., 9
#define ARRAY_SIZE 0XF // 
/*** Data Structure Definition ****/
typedef int adjMatrix[MAX_VERTEX][MAX_VERTEX];

typedef struct {
    int u,v;          // vertices representing the edge 
    int weight;
}edgetype;
typedef struct {
    edgetype edges[ARRAY_SIZE];
    int count;        // actual # of edges in the array
}edgelist;

edgelist createEdgeList(adjMatrix M)
{
    int x, y, pos;
    edgelist  E = {0};           // Declares and initializes the edge list E to be empty 
                                                      // Note: for the array, just initialize one component

    for(x = 0; x < MAX_VERTEX; x++){
        for(y = x+1; y < MAX_VERTEX; y++){                  // Reminder: (u,v) == (v,u)
            if (M[x][y] != SENTINEL){                                                 // Edge is found
      
                /* finds the proper position of the edge in the list */ 
                for(pos = 0; pos < E.count && E.edges[pos].weight < M[x][y]; pos++){}                    
       
                /* Shifts succeeding elements to make room for the new edge */
                memcpy(&E.edges[pos+1], &E.edges[pos], (E.count-pos)*sizeof(edgetype));    

                /* Insertion Proper */
                edgelist edge = {x, y, M[x][y]};     // declares and initialize edge to contain
                                                    // the edge data to be inserted in the list

                E.edges[pos] = edge;          // inserts the edge in the list
                E.count++;          
            }
        }
    }
    return E;
}

edgelist createEdgeList(adjMatrix M) {
    int x, y, pos;
    edgelist E = {0};  // Declares and initializes the edge list E to be empty
                      // Note: for the array, just initialize one component

    for(x = 0; x < MAX_VERTEX; x++){
        for(y = x+1; y < MAX_VERTEX; y++){ // Reminder: (u,v) == (v,u)
            if (M[x][y] != SENTINEL){ // Edge is found
                /* finds the proper position of the edge in the list */
                for(pos = 0; pos < E.count && M[x][y] >= E.edges[pos].weight; pos++){}
                /* Shifts succeeding elements to make room for the new edge */
                memmove(&E.edges[pos+1], &E.edges[pos], (E.count - pos) * sizeof(edgetype));
                /* Insertion Proper */
                edgetype edge = {x, y, M[x][y]};  // declares and initialize edge to contain
                                                 // the edge data to be inserted in the list
                E.edges[pos] = edge;  // inserts the edge in the list
                E.count++;
            }
        }
    }
    return E;
}