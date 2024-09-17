/**
 * @trent's insertSorted code & sortStack
 */
void insertSorted2(Queue *q, Data d){

    Data temp;

    while(d.studID > front(q).studID){
        temp = front(q);
        dequeue(q);
        enqueue(q, temp);
    }

    enqueue(q, d);

    while(front(q).studID > d.studID){
        temp = front(q);
        dequeue(q);
        enqueue(q, temp);
    }
}

void sortStack(Stack *s, bool flag){
    if(isEmpty(*s)){
        printf("Nothing to sort!\n");
        return;
    }
    Stack temp;
    initStack(&temp);

    while(!isEmpty(*s)){
        Person t = peek(*s);
        pop(s);
        if(isEmpty(temp)){
            push(&temp, t);
            
        } else {
            if(flag){ //ascending
                if(strcmp(t.name, peek(temp).name) > 0){
                push(&temp, t);
                
                } else {
                    while(!isEmpty(temp) && strcmp(t.name, peek(temp).name) < 0){
                        push(s, peek(temp));
                        pop(&temp);
                    }
                push(&temp, t);
                }
            } else { //descending
                if(strcmp(t.name, peek(temp).name) < 0){
                push(&temp, t);
                
                } else {
                    while(!isEmpty(temp) && strcmp(t.name, peek(temp).name) > 0){
                        push(s, peek(temp));
                        pop(&temp);
                    }
                push(&temp, t);
                }
            }
        }
        
    }

    while(!isEmpty(temp)){
        push(s, peek(temp));
        pop(&temp);
    }
    
}

/**
 * @walter's insertSorted, sortQueue, & filterQueue
 */
bool insertSorted(Queue *q, Data d){ // insert data in correct position
NodePtr curr = q->head;
Data temp;
if(curr == NULL){
enqueue(q, d);
return true;
}
while(d.studID > curr->elem.studID && !isEmpty(*q)){
temp = curr->elem;
dequeue(q);
if(isEmpty(*q)){

}
enqueue(q, temp);
greet();
}
enqueue(q, d);
return true;
}

// Name* getStudent(Queue q, String program, char sex);

void sortQueue(Queue* q){
Queue sq;
initQueue(&sq);
Data temp;
int largest_num;
int current;

while(!isEmpty(*q)){
largest_num = q->head->elem.studID;
current = q->head->elem.studID;
// printf("\nCurrent: %d", current);
do{
temp = q->head->elem;
dequeue(q);
enqueue(q, temp);
if(largest_num < q->head->elem.studID){
// printf("\nCurrent: %d", curr->elem.studID);
largest_num = q->head->elem.studID;
}
} while(q->head->elem.studID != current);
// printf("\nLargest: %d", largest_num);

// printf("\nFirst: %d", q->head->elem.studID);
while(q->head->elem.studID != largest_num){
temp = q->head->elem;
dequeue(q);
enqueue(q, temp);
}

temp = q->head->elem;
dequeue(q);
enqueue(&sq, temp);

// printf("\nFirst(sq): %d", sq.head->elem.studID);

}

q->head = sq.head;

}

Name* filterNames(NQueue *nq, char *filterString){
// printf("Wonderhoy!");
Name* fn = malloc(sizeof(Name) * MAX);
Name temp;
int j = 0;
int i = nq->front; // 0
int rear = nq->rear;
// printf("\nFront: %d", nq->front);
// printf("\nRear: %d", nq->rear);
while(i != rear){
if(strcmp(nq->elems[i].lname, filterString) == 0){
fn[j] = nq->elems[i];
dequeue(nq);
// printf("Name: %s", fn[j].lname);
j++;
} else {
temp = nq->elems[i];
dequeue(nq);
enqueue(nq, temp);
}
i = (i + 1) % MAX;
}

// printf("Wonderhoy!");
fn[j] = createName("", "");
// printf("Name: %s", fn[j].lname);
return fn;
}