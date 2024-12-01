#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char prodName[20];
    float prodPrice;
} Product;

Product newProduct(char *product, float price);
void displayProduct(Product P);

int main()
{
    Product prod;

    FILE *fp;
    fp = fopen("my_product.file", "rb");

    if(fp != NULL)
    {
      while( fread(&prod, sizeof(Product), 1, fp) )
       {
           displayProduct(prod);
           printf("\n");
       }
    }
    fclose(fp);

    return 0;
}


Product newProduct(char *product, float price)
{
    Product P;
    strcpy(P.prodName, product);

    P.prodPrice = price;

    return P;
}

void displayProduct(Product P)
{
    printf("%15s - Php %.2f" , P.prodName, P.prodPrice);
}



