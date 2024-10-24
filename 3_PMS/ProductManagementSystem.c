#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants for product, queue, stack, and set sizes
#define MAX_PRODUCTS 100
#define QUEUE_SIZE 100
#define STACK_SIZE 100
#define MAX_CATEGORIES 50

// Structure to represent a product
typedef struct {
    int id;
    char name[50];
    char description[100];
    float price;
    int stock_quantity;
    char category[30];
} Product;

// Structure to represent an order
typedef struct {
    int order_id;
    int product_id;
    int quantity;
} Order;

// Product hash table structure
typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} ProductTable;

// Order queue structure
typedef struct {
    Order orders[QUEUE_SIZE];
    int front;
    int rear;
} OrderQueue;

// Stock stack structure
typedef struct {
    int stock_levels[STACK_SIZE];
    int top;
} StockStack;

// Set structure for unique product categories
typedef struct {
    char categories[MAX_CATEGORIES][30];
    int size;
} CategorySet;

// Function prototypes

// Product management functions
Product create_product(int id, const char* name, const char* description, float price, int stock_quantity, const char* category);
void add_product(ProductTable* table, Product product, CategorySet* categorySet);
void display_all_products(ProductTable* table);

// Set management functions (CategorySet)
bool add_to_set(CategorySet* set, const char* element);
bool is_in_set(CategorySet* set, const char* element);
void display_set(CategorySet* set);

// Utility functions
void print_menu();
void clear_input_buffer();

// Initialization functions
void init_product_table(ProductTable* table);
void init_category_set(CategorySet* set);

int main() {
    ProductTable productTable;
    CategorySet categorySet;

    // Initialize data structures
    init_product_table(&productTable);
    init_category_set(&categorySet);

    int choice;
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1: {
                int id;
                char name[50];
                char description[100];
                float price;
                int stock_quantity;
                char category[30];

                printf("Enter product ID: ");
                scanf("%d", &id);
                clear_input_buffer();
                printf("Enter product name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");  // Remove newline character
                printf("Enter product description: ");
                fgets(description, sizeof(description), stdin);
                strtok(description, "\n");  // Remove newline character
                printf("Enter product price: ");
                scanf("%f", &price);
                printf("Enter stock quantity: ");
                scanf("%d", &stock_quantity);
                clear_input_buffer();
                printf("Enter product category: ");
                fgets(category, sizeof(category), stdin);
                strtok(category, "\n");  // Remove newline character

                Product newProduct = create_product(id, name, description, price, stock_quantity, category);
                add_product(&productTable, newProduct, &categorySet);
                break;
            }
            case 2: {
                display_all_products(&productTable);
                break;
            }
            case 3: {
                display_set(&categorySet);
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function implementations

// Create a new product
Product create_product(int id, const char* name, const char* description, float price, int stock_quantity, const char* category) {
    Product p;
    p.id = id;
    strcpy(p.name, name);
    strcpy(p.description, description);
    p.price = price;
    p.stock_quantity = stock_quantity;
    strcpy(p.category, category);
    return p;
}

// Add product to the product table and update the category set
void add_product(ProductTable* table, Product product, CategorySet* categorySet) {
    if (table->count < MAX_PRODUCTS) {
        table->products[table->count] = product;
        table->count++;
        printf("Product added successfully!\n");

        // Add category to the set (unique)
        if (add_to_set(categorySet, product.category)) {
            printf("Category '%s' added to category set.\n", product.category);
        } else {
            printf("Category '%s' already exists in category set.\n", product.category);
        }
    } else {
        printf("Product table is full!\n");
    }
}

// Display all products in the product table
void display_all_products(ProductTable* table) {
    if (table->count == 0) {
        printf("No products available.\n");
    } else {
        printf("\nProduct List:\n");
        for (int i = 0; i < table->count; i++) {
            Product p = table->products[i];
            printf("ID: %d | Name: %s | Description: %s | Price: %.2f | Stock: %d | Category: %s\n", p.id, p.name, p.description, p.price, p.stock_quantity, p.category);
        }
    }
}

// Initialize product table
void init_product_table(ProductTable* table) {
    table->count = 0;
}

// Set functions (CategorySet)

// Initialize the category set
void init_category_set(CategorySet* set) {
    set->size = 0;
}

// Add an element to the set if it's not already present
bool add_to_set(CategorySet* set, const char* element) {
    if (!is_in_set(set, element)) {
        if (set->size < MAX_CATEGORIES) {
            strcpy(set->categories[set->size], element);
            set->size++;
            return true;
        } else {
            printf("Category set is full!\n");
            return false;
        }
    }
    return false;  // Element already in set
}

// Check if an element is already in the set
bool is_in_set(CategorySet* set, const char* element) {
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->categories[i], element) == 0) {
            return true;
        }
    }
    return false;
}

// Display all categories in the set
void display_set(CategorySet* set) {
    if (set->size == 0) {
        printf("No categories available.\n");
    } else {
        printf("\nCategory Set:\n");
        for (int i = 0; i < set->size; i++) {
            printf("%s\n", set->categories[i]);
        }
    }
}

// Utility function to display the menu
void print_menu() {
    printf("\nProduct Management System\n");
    printf("1. Add Product\n");
    printf("2. Display All Products\n");
    printf("3. Display Product Categories\n");
    printf("4. Exit\n");
}

// Utility function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}