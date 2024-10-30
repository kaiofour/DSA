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
    Product list[5];

    list[0] = newProduct("Binangkal", 15);
    list[1] = newProduct("Ramen", 250);
    list[2] = newProduct("Champorado", 22.5);
    list[3] = newProduct("Lansiao", 75);
    list[4] = newProduct("Menudo", 25);

    FILE *fp;
    fp = fopen("my_product.file", "wb");

    if(fp != NULL)
    {
        fwrite(list, sizeof(Product), 1, fp);
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
