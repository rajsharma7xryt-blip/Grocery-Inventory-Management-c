#include <stdio.h>
#include <string.h>

#define MAX 100

struct Product {
    int id;
    char name[30];
    int quantity;
    float price;
};

struct Product p[MAX];
int count = 0;

void addProduct();
void displayProducts();
void searchProduct();
void updateStock();
void deleteProduct();

int main() {
    int choice;

    while (1) {
        printf("\n===== Grocery Inventory Management =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Stock\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateStock();
                break;

            case 5:
                deleteProduct();
                break;

            case 6:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}

void addProduct() {
    printf("\nEnter Product ID: ");
    scanf("%d", &p[count].id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", p[count].name);

    printf("Enter Quantity: ");
    scanf("%d", &p[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &p[count].price);

    count++;

    printf("\nProduct Added Successfully!\n");
}

void displayProducts() {
    int i;

    if (count == 0) {
        printf("\nNo Products Available!\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Qty", "Price");

    for (i = 0; i < count; i++) {
        printf("%-10d %-20s %-10d %.2f\n",
               p[i].id,
               p[i].name,
               p[i].quantity,
               p[i].price);
    }
}

void searchProduct() {
    int id, i;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("\nProduct Found\n");
            printf("ID: %d\n", p[i].id);
            printf("Name: %s\n", p[i].name);
            printf("Quantity: %d\n", p[i].quantity);
            printf("Price: %.2f\n", p[i].price);
            return;
        }
    }

    printf("\nProduct Not Found!\n");
}

void updateStock() {
    int id, i;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("Enter New Quantity: ");
            scanf("%d", &p[i].quantity);

            printf("Stock Updated Successfully!\n");
            return;
        }
    }

    printf("\nProduct Not Found!\n");
}

void deleteProduct() {
    int id, i, j;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (p[i].id == id) {
            for (j = i; j < count - 1; j++) {
                p[j] = p[j + 1];
            }

            count--;

            printf("Product Deleted Successfully!\n");
            return;
        }
    }

    printf("\nProduct Not Found!\n");
}