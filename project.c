#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an object
struct ToDoObject {
    char name[50];
    char unit[20];
    int need;
    int counter;
};

// Function to add a new object to the list
void addObject(struct ToDoObject *list, int *size) {
    if (*size >= 100) {
        printf("Sorry, the list is full.\n");
        return;
    }

    printf("Enter the name of the task: ");
    scanf("%s", list[*size].name);

    printf("Enter the unit (e.g., minutes, hours): ");
    scanf("%s", list[*size].unit);

    printf("Enter the amount needed for completion: ");
    scanf("%d", &list[*size].need);

    list[*size].counter = 0;

    (*size)++;
}

// Function to update the counter for a specific object
void updateCounter(struct ToDoObject *list, int *size) {
    if (*size == 0) {
        printf("The list is empty.\n");
        return;
    }

    printf("Enter the name of the task to update: ");
    char taskName[50];
    scanf("%s", taskName);

    for (int i = 0; i < *size; ++i) {
        if (strcmp(list[i].name, taskName) == 0) {
            list[i].counter++;

            if (list[i].counter == list[i].need) {
                printf("Task '%s' completed! Removing from the list.\n", list[i].name);

                // Remove the object by shifting the remaining elements
                for (int j = i; j < *size - 1; ++j) {
                    list[j] = list[j + 1];
                }

                (*size)--;
            }

            return;
        }
    }

    printf("Task not found.\n");
}

// Function to display the current list of objects
void displayList(struct ToDoObject *list, int size) {
    printf("Current list of tasks:\n");
    for (int i = 0; i < size; ++i) {
        printf("%s (%d/%d %s)\n", list[i].name, list[i].counter, list[i].need, list[i].unit);
    }
    printf("\n");
}

int main() {
    struct ToDoObject toDoList[100];
    int listSize = 0;
    int choice;

    do {
        printf("1. Add a task\n");
        printf("2. Update task completion\n");
        printf("3. Display list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addObject(toDoList, &listSize);
                break;
            case 2:
                updateCounter(toDoList, &listSize);
                break;
            case 3:
                displayList(toDoList, listSize);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
