/**
 * Insertion in heap
 * 1.) Insert at the end of heap
 * 2.) Check if the element has less priority
 *  than its parent or if it is the top-most in the
 * heap.
 * 3.) If yes, exit
 * 4.) If no, swap the element with the parent node
 * and go back to step 2
 */


/**
 * HEAP OPERATIONS FOR FINDING PARENT & CHILD NODES
 * 1.) arr[ (i - 1) / 2] = returns the parent node
 * 2.) arr[ (2 * i) + 1] = returns the left child node
 * 3.) arr[ (2 * i) + 2] = returns the right child node
 */