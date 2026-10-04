#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10
#define MAX_LINE_LENGTH 200

char **lines;
int lineCount = 0;
int capacity = INITIAL_SIZE;

void resizeDocument()
{
    capacity = capacity * 2;

    lines = realloc(lines, capacity * sizeof(char *));

    if (lines == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void insertLine()
{
    int position;
    char text[MAX_LINE_LENGTH];

    printf("Enter line number to insert: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid line number!\n");
        return;
    }

    if (lineCount >= capacity)
    {
        resizeDocument();
    }

    for (int i = lineCount; i >= position; i--)
    {
        lines[i] = lines[i - 1];
    }

    printf("Enter text: ");
    fgets(text, MAX_LINE_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    lines[position - 1] = malloc(strlen(text) + 1);

    strcpy(lines[position - 1], text);

    lineCount++;

    printf("Line inserted successfully!\n");
}

void deleteLine()
{
    int position;

    if (lineCount == 0)
    {
        printf("Document is empty!\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number!\n");
        return;
    }

    free(lines[position - 1]);

    for (int i = position - 1; i < lineCount - 1; i++)
    {
        lines[i] = lines[i + 1];
    }

    lineCount--;

    printf("Line deleted successfully!\n");
}

void displayDocument()
{
    if (lineCount == 0)
    {
        printf("\nDocument is empty!\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

void freeDocument()
{
    for (int i = 0; i < lineCount; i++)
    {
        free(lines[i]);
    }

    free(lines);
}

int main()
{
    int choice;

    lines = malloc(capacity * sizeof(char *));

    if (lines == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1)
    {
        printf("\n===== LINE EDITOR =====\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                displayDocument();
                break;

            case 4:
                freeDocument();
                printf("Exiting Line Editor...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}