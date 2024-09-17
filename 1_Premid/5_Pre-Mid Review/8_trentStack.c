#include <stdio.h>
#include <string.h>

#include "stack.h"

void displayPerson(Person p){
    printf("%s, Age of %d, %c.", p.name, p.age, p.sex);
}

Person createPerson(char name[30], int age, char sex){
    Person p;
    strcpy(p.name, name);
    p.age = age;
    p.sex = sex;

    return p;
}


void initStack(Stack *s){
    *s = NULL;
}

bool isEmpty(Stack s){
    return s == NULL;
}
void displayStack(Stack s){
    Stack current = s;
    printf("{\n");
    while(current != NULL){
        displayPerson(current->data);
        printf("\n");
        current = current->link;
    }
    printf("}\n\n");
}

bool push(Stack *s, Person p){

    Stack new;
    new = malloc(sizeof(NodeType));
    new->data = p;

    if(isEmpty(*s)){
        new->link = NULL;
        *s = new;
    } else {
        new->link = *s;
        *s = new;
    }

    return true;
}

bool pop(Stack *s){
    if(isEmpty(*s)){
        printf("Empty List!\n");
        return false;
    }
    (*s) = (*s)->link;
    return true;
}
Person peek(Stack s){
    return s->data;
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

bool insertSorted1(Stack *s, Person p){
    if(isEmpty(*s)){
        push(s, p);
    } else {
        Stack temp;
        initStack(&temp);
        int flag = 0;

        while(!isEmpty(*s)){
            if(strcmp(p.name, peek(*s).name) < 0 && flag == 0){
                push(&temp, p);
                flag = 1;
            }
            push(&temp, peek(*s));
            pop(s);
            
        }

        if(flag == 0){ //places at very last
            push(&temp, p);
        }

        while(!isEmpty(temp)){ //returns temp contents to s
        push(s, peek(temp));
        pop(&temp);
        }

    }

    return true;
}

//gave up for now

// bool insertSorted2(Stack *s, Person p){ 
//     if(isEmpty(*s)){
//         push(s, p);
//     } else {
//         Stack temp;
//         initStack(&temp);
//         int flag = 0;

//         while(!isEmpty(*s)){
//             if(strcmp(p.name, peek(*s).name) < 0 && flag == 0){
//                 push(&temp, p);
//                 flag = 1;
//             }
//             push(&temp, peek(*s));
//             pop(s);
            
//         }

//         if(flag == 0){ //places at very last
//             push(&temp, p);
//         }

//         while(!isEmpty(temp)){ //returns temp contents to s
//         push(s, peek(temp));
//         pop(&temp);
//         }

//     }

//     return true;
// }