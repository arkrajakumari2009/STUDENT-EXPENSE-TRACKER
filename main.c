#include <stdio.h>

#define MAX 100

struct Expense {
    char category[30];
    float amount;
};

int main() {
    struct Expense expenses[MAX];
    int count = 0;
    int choice;
    float total;

    while (1) {
        printf("\n====================================\n");
        printf("       STUDENT EXPENSE TRACKER\n");
        printf("====================================\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= MAX) {
                printf("Expense limit reached!\n");
            } else {
                printf("Enter category: ");
                scanf("%s", expenses[count].category);

                printf("Enter amount: ");
                scanf("%f", &expenses[count].amount);

                count++;

                printf("Expense added successfully!\n");
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("No expenses recorded.\n");
            } else {
                printf("\n--------- EXPENSE LIST ---------\n");

                for (int i = 0; i < count; i++) {
                    printf("%d. %s - Rs. %.2f\n",
                           i + 1,
                           expenses[i].category,
                           expenses[i].amount);
                }
            }
        }

        else if (choice == 3) {
            total = 0;

            for (int i = 0; i < count; i++) {
                total += expenses[i].amount;
            }

            printf("\nTotal Expense: Rs. %.2f\n", total);
        }

        else if (choice == 4) {
            printf("Thank you for using Student Expense Tracker!\n");
            break;
        }

        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
