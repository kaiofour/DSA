SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    SinglyLinkedListNode *trav = malloc(sizeof(SinglyLinkedListNode));
    int i;
    for(trav = llist, i = 0; trav != NULL; trav = trav->next, i++) {
        //printf("%d\n", trav->data);
        if(i == position-1) {
            SinglyLinkedListNode *temp = trav->next;
            trav = trav->next->next;
            free(temp);
        }
    }
    
    return llist;
}

//copy the address of the node you want to delete and assign it to the 
//copy the next of the node you want to delete to the previous node