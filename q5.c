// To insert, delete and display the entries in Symbol Table
#include <stdio.h>
#include <string.h>

#define MAX 50 // Maximum number of symbols
#define LEN 20 // Maximum length of symbol name

char symbolTable[MAX][LEN];
int count = 0;

// Insert a symbol
void insert(char name[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(symbolTable[i], name) == 0)
        {
            printf("Symbol '%s' already exists!\n", name);
            return;
        }
    }
    if (count < MAX)
    {
        strcpy(symbolTable[count], name);
        count++;
        printf("Inserted: %s\n", name);
    }
    else
    {
        printf("Symbol Table is full!\n");
    }
}

// Delete a symbol
void delete(char name[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(symbolTable[i], name) == 0)
        {
            for (int j = i; j < count - 1; j++)
            {
                strcpy(symbolTable[j], symbolTable[j + 1]);
            }
            count--;
            printf("Deleted: %s\n", name);
            return;
        }
    }
    printf("Symbol '%s' not found!\n", name);
}

// Display symbol table
void display()
{
    if (count == 0)
    {
        printf("Symbol Table is empty.\n");
        return;
    }
    printf("\nSymbol Table:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, symbolTable[i]);
    }
}

int main()
{
    int choice;
    char name[LEN];

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter symbol to insert: ");
            scanf("%s", name);
            insert(name);
            break;
        case 2:
            printf("Enter symbol to delete: ");
            scanf("%s", name);
            delete(name);
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
