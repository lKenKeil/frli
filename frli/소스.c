#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRUITS 10
#define MAX_NAME_LENGTH 20


void addFruit(char fruits[MAX_FRUITS][MAX_NAME_LENGTH], int* numFruits) {
    char newFruit[MAX_NAME_LENGTH];
    printf("Enter the name of the fruit to add: ");
    scanf("%s", newFruit);


    for (int i = 0; i < *numFruits; i++) {
        if (strcmp(fruits[i], newFruit) == 0) {
            printf("The fruit already exists in the list.\n");
            return;
        }
    }


    if (*numFruits < MAX_FRUITS) {
        strcpy(fruits[*numFruits], newFruit);
        (*numFruits)++;
        printf("The fruit has been added to the list.\n");
    }
    else {
        printf("The fruit list is full. Cannot add more fruits.\n");
    }
}


void deleteFruit(char fruits[MAX_FRUITS][MAX_NAME_LENGTH], int* numFruits, char deletedFruits[MAX_FRUITS][MAX_NAME_LENGTH], int* numDeleted) {
    char fruitToDelete[MAX_NAME_LENGTH];
    printf("Enter the name of the fruit to delete: ");
    scanf("%s", fruitToDelete);

    int fruitIndex = -1;

    for (int i = 0; i < *numFruits; i++) {
        if (strcmp(fruits[i], fruitToDelete) == 0) {
            fruitIndex = i;
            break;
        }
    }

    if (fruitIndex != -1) {
       
        strcpy(deletedFruits[*numDeleted], fruits[fruitIndex]);
        (*numDeleted)++;

       
        for (int i = fruitIndex; i < (*numFruits) - 1; i++) {
            strcpy(fruits[i], fruits[i + 1]);
        }

        (*numFruits)--;
        printf("The fruit has been deleted from the list.\n");
    }
    else {
        printf("The fruit does not exist in the list.\n");
    }
}


void printDeletedFruits(char deletedFruits[MAX_FRUITS][MAX_NAME_LENGTH], int numDeleted) {
    if (numDeleted == 0) {
        printf("No fruits have been deleted.\n");
    }
    else {
        printf("Deleted fruits:\n");
        for (int i = 0; i < numDeleted; i++) {
            printf("%s\n", deletedFruits[i]);
        }
    }
}

int main() {
    char fruits[MAX_FRUITS][MAX_NAME_LENGTH] = {
        "Mango", "Orange", "Apple", "Grape", "Cherry", "Plum", "Guava", "Raspberry", "Banana", "Peach"
    };
    int numFruits = 10;
    char deletedFruits[MAX_FRUITS][MAX_NAME_LENGTH];
    int numDeleted = 0;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("(1) Add a new fruit to the list\n");
        printf("(2) Delete fruits from the list\n");
        printf("(3) Print the list of deleted fruits\n");
        printf("(4) Termination\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addFruit(fruits, &numFruits);
            break;
        case 2:
            deleteFruit(fruits, &numFruits, deletedFruits, &numDeleted);
            break;
        case 3:
            printDeletedFruits(deletedFruits, numDeleted);
            break;
        case 4:
            printf("Terminating the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
