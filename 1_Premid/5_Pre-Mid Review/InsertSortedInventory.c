# InsertSorted Premid Function for Sorting Products based off of Expiry Date

bool addProductBaseOnExpiry(Inventory *i, Product p) {
    if(i->currQty + p.prodQty > 100){
        return false;
    }

        if(isEmpty(*i)){
            push(i, p);
            i->currQty += p.prodQty;
        } else {
            
            Inventory temp;
            initInventory(&temp);
            int flag = 0;
            
            while(!isEmpty(*i)){
                if(dateDifference(p.expiry, peek(*i).expiry) > 0 && flag == 0){
                    push(&temp, p);
                    flag = 1;
                }
                push(&temp, peek(*i));
                pop(i);
            }
            
            if(flag == 0){
                push(&temp, p);
            }
            
            while(!isEmpty(temp)){
                push(i, peek(temp));
                pop(&temp);
            }
            
            i->currQty += p.prodQty;
        }
    
        return true;
}

/**
 * @walter's_code
 */
bool addProductBaseOnExpiry(Inventory *i, Product p) {
    
    if(i->currQty + p.prodQty > 100){
        return false;
    }
    
    if(isEmpty(*i)){
        push(i, p);
    } else {
        Inventory temp;
        initInventory(&temp);
        
        while(!isEmpty(*i) && dateDifference(p.expiry, peek(*i).expiry) < 0){
            push(&temp, peek(*i));
            pop(i);
        }
        push(i, p);
        
        while(!isEmpty(temp)){
            push(i, peek(temp));
            pop(&temp);
        }
        
    }
    
    return true;
}