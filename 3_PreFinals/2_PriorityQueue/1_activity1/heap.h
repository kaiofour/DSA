#ifndef HEAP_H
#define HEAP_H
#define MAX 10

typedef struct
{
    int elem[MAX];
    int count;
} ArrayHeap;

void initHeap(ArrayHeap *H);
void insertHeap(ArrayHeap *H, int elem);
void heapify(ArrayHeap *H, int position);
int parentPosition(int pos);




#endif