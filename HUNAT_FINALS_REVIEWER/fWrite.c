#include <stdio.h>

int main()
{
    // w == write, r == read, a == append
    FILE *pF = fopen("test.c", "w"); 
    
    fprintf(pf, "Helloworld");

    fclose(pF);

    // if(remove("test.txt") == 0)
    // {
    //     printf("That file was deleted successfully!");
    // }
    // else
    // {
    //     printf("That file was NOT deleted!");
    // }

    return 0;
}