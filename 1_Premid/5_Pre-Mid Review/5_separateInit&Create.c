/**
 * @linked list(Queue):
 */
void initQueue(Queue* q){
    q->head = NULL;
    q->tail = NULL;
}

Queue createQueue(){
    Queue q;

    q.head = NULL;
    q.tail = NULL;

return q;
}

void initQueue(Queue* q){
q->head = NULL;
q->tail = NULL;
}

Queue createQueue(){
    Queue q;

    q.head = NULL;
    q.tail = NULL;


    return q;
}

/**
 * @Dynamic Array(Stack) *not linkedlist:
 */
Stack createStack(){
    Stack s;
    s.count = 0;

    return s;
    }


void initStack(Stack *s){
    s->count = 0;
}