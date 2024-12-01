#include <stdio.h>

int main()
{
    FILE *pF = fopen("C:\\Users\\Russel\\OneDrive\\Desktop\\DSA GRAPHS.txt", "r"); // 'r' here stands for read
    char buffer[255];

    while(fgets(buffer, 255, pF) != NULL) 
    {
        printf("%s", buffer);
    }

    fclose(pF);


    return 0;
}