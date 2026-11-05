
#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[30];
    char type[20];
    char value[30];
};

struct Symbol table[100];
int count = 0;

void insert() {
    char name[30];

    printf("Enter identifier: ");
    scanf("%29s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Symbol already exists!\n");
            return;
        }
    }

    strcpy(table[count].name, name);

    printf("Enter data type: ");
    scanf("%19s", table[count].type);

    printf("Enter value: ");
    scanf("%29s", table[count].value);

    count++;
    printf("Symbol inserted successfully!\n");
}

void search() {
    char name[30];

    printf("Enter identifier to search: ");
    scanf("%29s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Symbol found!\n");
            printf("Name: %s\n", table[i].name);
            printf("Type: %s\n", table[i].type);
            printf("Value: %s\n", table[i].value);
            return;
        }
    }

    printf("Symbol not found!\n");
}

void deleteSymbol() {
    char name[30];

    printf("Enter identifier to delete: ");
    scanf("%29s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                table[j] = table[j + 1];
            }

            count--;
            printf("Symbol deleted successfully!\n");
            return;
        }
    }

    printf("Symbol not found!\n");
}

void display() {
    if (count == 0) {
        printf("Symbol table is empty!\n");
        return;
    }

    printf("\nSymbol Table:\n");
    printf("-----------------------------------\n");
    printf("%-15s %-10s %-10s\n", "Name", "Type", "Value");
    printf("-----------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-15s %-10s %-10s\n",
               table[i].name,
               table[i].type,
               table[i].value);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- SYMBOL TABLE OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: deleteSymbol(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
