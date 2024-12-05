#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX 32 //max num of products

typedef char String[20];
typedef int Boolean;



typedef struct {
    int year;
    int month;
    int date;
    int hour;
    int min;
    int sec;
} MyDate;

typedef struct {
    int prodID;
    String prodName;
    MyDate mfg; //date of Manufacture
    int shelflife;
    int prodQty;
} Product;

typedef struct node {
    Product item;
    struct node *left;
    struct node *right;
} NodeType, *BST;

typedef struct {
    Product prods[MAX];
    int lstIdx;
} Heap;


// Function prototypes
int timeStamp(void);
int timeStampDate(MyDate d);
MyDate moveDate(MyDate d, int days);
Boolean isEmptyQ(Heap q);
Boolean isFullQ(Heap q);
Heap newHeap(void);
void enqueue(Heap* q, Product p);
Product dequeue(Heap* q);
MyDate newDate(int year, int month, int date, int hour, int min, int sec);
Product newProduct(int prodID, String prodName, MyDate mfg, int shelflife, int prodQty);


/**
 * @main_function
 */
int main()
{
    


    return 0;
}


// Function to get the current timestamp
int timeStamp() {
    time_t t = time(NULL);
    return (int)t;
}

// Function to get the timestamp of a given date
int timeStampDate(MyDate d) {
    struct tm time = {0};
    time.tm_year = d.year - 1900;
    time.tm_mon = d.month - 1;
    time.tm_mday = d.date;
    time.tm_hour = d.hour;
    time.tm_min = d.min;
    time.tm_sec = d.sec;
    time_t t = mktime(&time);
    return (int)t;
}

// Function to shift a date by a given number of days
MyDate moveDate(MyDate d, int days) {
    struct tm time = {0};
    time.tm_year = d.year - 1900;
    time.tm_mon = d.month - 1;
    time.tm_mday = d.date;
    time.tm_hour = d.hour;
    time.tm_min = d.min;
    time.tm_sec = d.sec;
    time_t t = mktime(&time);
    t += days * 24 * 60 * 60;
    struct tm* newTime = localtime(&t);
    MyDate newDate;
    newDate.year = newTime->tm_year + 1900;
    newDate.month = newTime->tm_mon + 1;
    newDate.date = newTime->tm_mday;
    newDate.hour = newTime->tm_hour;
    newDate.min = newTime->tm_min;
    newDate.sec = newTime->tm_sec;
    return newDate;
}

// Function to check if a queue is empty
Boolean isEmptyQ(Heap q) {
    return q.lstIdx == -1;
}

// Function to check if a queue is full
Boolean isFullQ(Heap q) {
    return q.lstIdx == MAX - 1;
}

// Function to create a new heap
Heap newHeap() {
    Heap h;
    h.lstIdx = -1;
    return h;
}

// Function to create a new queue
// Note: In your data structure definition, there is no queue structure.
// I assume you want to use the Heap structure as a queue.
// If you want to use a different queue structure, please define it.

// Function to enqueue an element into a queue
void enqueue(Heap* q, Product p) {
    if (isFullQ(*q)) {
        printf("Queue is full\n");
        return;
    }
    q->prods[++q->lstIdx] = p;
}

// Function to dequeue an element from a queue
Product dequeue(Heap* q) {
    if (isEmptyQ(*q)) {
        printf("Queue is empty\n");
        Product empty;
        empty.prodID = -1;
        return empty;
    }
    Product p = q->prods[q->lstIdx--];
    return p;
}

// Function to create a new date
MyDate newDate(int year, int month, int date, int hour, int min, int sec) {
    MyDate d;
    d.year = year;
    d.month = month;
    d.date = date;
    d.hour = hour;
    d.min = min;
    d.sec = sec;
    return d;
}

// Function to create a new product
Product newProduct(int prodID, String prodName, MyDate mfg, int shelflife, int prodQty) {
    Product p;
    p.prodID = prodID;
    strcpy(p.prodName, prodName);
    p.mfg = mfg;
    p.shelflife = shelflife;
    p.prodQty = prodQty;
    return p;
}


BST *findProductAddress(BST *b, int prodID) {
    if(*b == NULL) {
        return NULL;
    } else if((*b)->item.prodID == prodID) {
        return 
    } else if((*b)->item.prodID > prodID) {
        return
    } else {
        return
    }
}

Product checkOutProduct(BST *b, int prodID) {
    Product p = newProduct(0,"",newDate(0,0,0,0,0,0),0,0);
    BST temp, *trav, *trav2;

    
    if ((*trav)->item.prodQty == 0) {
    if ((*trav)->left == NULL) {
        temp = *trav;
        *trav = temp->right;
    } else if ((*trav)->right == NULL) {
        temp = *trav;
        *trav = temp->left;
    } else {
        trav2 = (*trav)->right;
        temp = *trav2;
        *trav2 = temp->right;
        (*trav)->item = temp->item;
    }
    free(temp);
}

    return p;
}

BST *findMin(BST *b) {
    BST *trav;
    for (trav = b; trav != NULL && trav->left != NULL; trav = trav->left) {}
    return trav;
}

BST *findMax(BST *b) {
    BST *trav;
    for (trav = b; trav != NULL && trav->right != NULL; trav = trav->right) {}
    return trav;
}


Heap buildProductExp(BST b) {
    Heap pQ = newHeap();
    Queue q = newQueue();
    Product p;
    NodeType node;
    int ndx, pIdx;

    enqueue(&q, b);
    while(!isEmptyQ(q)) {
        node = dequeue(&q);
        p = node.item;

        if (b->left) enqueue(&q, b->left);
        if(b->right) enqueue(&q, b->right);

        if(timeStampDate(p.mfg) + p.shelflife > timeStamp()) {
            ndx = ++pQ.lstIdx;
            pIdx = (ndx-1) / 2;

            while(ndx > 0 && pQ.prods[pIdx].prodID > p.prodID) {
                pQ.prods[ndx] = pQ.prods[pIdx];
                ndx = pIdx;
                pIdx = (ndx-1) / 2;
            }
            pQ.prods[ndx] = p;
        }

    }
    return pQ;
}


