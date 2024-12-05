bool addProductBaseOnExpiry(Inventory *i, Product p) {
    // To do code logic here.
    if(i->currQty + p.prodQty > 100) {
        return false;
    }
        
    if (isEmpty(*i)) {
        push(i, p);
    } else {
        Inventory temp;
        initInventory(&temp);
        
        while(!isEmpty(*i) && dateDifference(p.expiry, peek(*i).expiry) < 0) {
                push(&temp, peek(*i));
                pop(i);
        }
        push(i, p);
            
        
        while(!isEmpty(temp)) {
            push(i, peek(temp));
            pop(&temp);
        }
        
    }
        
    return true;
}
