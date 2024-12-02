#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 8

//ver2
typedef struct {
    int set[MAX];
    int size;
} SET;

typedef enum{TRUE, FALSE} Boolean;

/**
 * SET OPERATIONS
 * - UID(Union, Intersection, Difference) & UTIL Functions
 */
SET init();
SET *dynamicInit();
Boolean deleteFromSet(SET *S, int x);
Boolean isEmpty(SET *S);
bool isMember(SET S, int x);
void insert(SET *set, int element);
void printSet(SET S);

// UID
SET UNION(SET A, SET B);
SET INTERSECTION(SET A, SET B);
SET DIFFERENCE(SET A, SET B);

//SUBSET
Boolean isSubset(SET A, SET B);
Boolean setEquality(SET A, SET B);

/**
 * @MAIN_FUNCTION
 */
int main()
{
     



    return 0;
}

SET init()
{
    SET temp;
    int i;
    for(i = 0; i < MAX; i++)
    {
        temp.set[i] = -1;
    }
    temp.size = 0;

    return temp;
}

SET *dynamicInit()
{
    SET *temp = malloc(sizeof(SET));
    temp->size = 0;
    
    int i;
    for(i = 0; i < MAX; i++)
    {
        temp->set[i] = -1;
    }

    return temp;
}

Boolean deleteFromSet(SET *S, int x)
{
    Boolean truth;
    int i;
    for(i = 0; i < MAX; i++)
    {
        if (S->set[i] == x)
        {
            S->set[i] = 0;
            S->size--;
            truth = TRUE; //returns 0;
        }
        else
        {
            printf("Element not found.\n");
            truth = FALSE; //returns 1
            break;
        }
    }

    return truth;
}

Boolean isEmpty(SET *S)
{
    return (S->size == 0)? TRUE : FALSE;
}

void insert(SET *S, int element)
{
    bool inSet = false;
    int i;
    for(i = 0; i < S->size; i++)
    {
        if(S->set[i] == element) inSet = true;

        if(!inSet)
        {
            S->size = S->size + 1;
            S->set[S->size] = element;
        }
    }
}

void printSet(SET S)
{
    int i;
    for(i = 0; i < S.size; i++)
    {
        printf("%d ", S.set[i]);
    }
    printf("\n");
}

SET UNION(SET A, SET B)
{
    SET newSet = init();
    int i;
    for(i = 0; i < A.size; i++)
        insert(&newSet, A.set[i]); // Pass newSet by reference

    for(i = 0; i < B.size; i++)
        insert(&newSet, B.set[i]); // Pass newSet by reference

    return newSet;
}

SET INTERSECTION(SET A, SET B)
{
    SET newSet = init();
    int i, j;

    for(i=0; i < A.size; i++)
        for(j=0; j < B.size; j++)
            if(A.set[i] == B.set[j])
                insert(&newSet, A.set[i]);

    return newSet;                
}


SET DIFFERENCE(SET A, SET B)
{
    SET newSet = init();

    int i, j;
    for(i= 0 ; i < A.size; i++)
    {
        bool isElem_B = false;

        for(j = 0; j < B.size; j++)
        {
            if(A.set[i] == B.set[j])
                isElem_B = true;

            if(!isElem_B)
                insert(&newSet, A.set[i]);
        } 

    }

    return newSet;
}

// The original code is wrong because it returns false as soon as it finds a single element
// in A that is not in B. This is incorrect because the definition of subset is that every element
// in A must be in B, not just at least one element.

// The correct code should return false only if no element in A is found in B, and true otherwise
bool isSubset(SET A, SET B)
{
    int i, j;
    for (i = 0; i < A.size; i++)
    {
        bool isElem_B = false;
        for (j = 0; j < B.size; j++)
        {
            if (A.set[i] == B.set[j])
            {
                isElem_B = true;
                break;
            }
        }

        if (!isElem_B)
            return false;
    }

    return true;
}


// returns true if setA is equal to setB
bool set_equality(Set *setA, Set *setB)
{
  // if the sets do not have the same length, it is not possible for them to
  // be equal and we return false
  if (setA->length != setB->length) return false;
  
  // if the sets are equal length, and all the elements of setA are in setB,
  // then they MUST be equal and so we let is_subset() determine this
  return is_subset(setA, setB);
}

bool isMember(SET S, int x)
{
    int i;
    for (i = 0; i < S.size; i++)
    {
        if (S.set[i] == value)
            return true;
    }

    return false;
}


// Set Basics
//
// A set is a collection of items.
//
// Example set: {4, 9, 2}
//
//
// We can have an empty set with no elements.
//
// Empty set: {}
//
//
// The order of the elements in the set doesn't matter.
//
// So {4, 9, 2} is equal to {9, 2, 4}.
//
//
// The number of occurrences of an element in the set
// doesn't matter.
//
// So {4, 4, 4, 9, 2} is equal to {4, 9, 2}
//
// So we will only need to store unique elements of a set.
//
//
// We can insert elements into a set:
//
// insert 4 int {2, 9} gives us the set {4, 2, 9}
//
//
// Set Union
//
// {1, 2, 3} union {2, 3, 4} = {1, 2, 3, 4}
//
// the union of sets includes all elements from BOTH sets.
//
//
// Set Intersection
//
// {1, 2, 3} intersection {2, 3, 4} = {2, 3}
//
// the intersection of sets contains all the elements of
// one set that are also in the other set.
//
//
// Set Difference:
//
// {1, 2, 3} - {2, 3, 4} = {1}
//
// the difference of the sets contains all the elements
// of the first set that are not also in the second set.
//
//
// Subset
//
// {1, 2} is a subset of {1, 2, 3}
//
// a set A is a subset of set B if all the elements of A
// are also elements of B.
//
//
// Membership
//
// 2 is a member of the set {1, 2, 3}
//
// 4 is NOT a member of the set {1, 2, 3}
//