#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "model/task.h"

// Function to swap tasks
void swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to bubble sort task
void tasks_sort(Task *tasks, int task_count) {    
    // Check the number of task
    if (task_count <= 1) {
        printf("Not enough tasks to sort!\n");
        getchar();
        getchar();
        return;
    }

    // Sort option
    int option;
    printf("Sort by:\n");
    printf("1. Start Date\n");
    printf("2. Deadline\n");
    printf("3. Priority\n");
    printf("\nType '0' to cancel\n\n");
    printf("Enter option: ");
    scanf("%d", &option);
    getchar();

    if (option == 0) return;

    // Bubble sort
    int i, j;
    for (i = 0; i < task_count - 1; i++) {
        for (j = 0; j < task_count - i - 1; j++) {
            int swap_needed = 0;
            
            // If user enter option then swap need
            switch (option) {
                case 1:
                    swap_needed = (tasks[j].start_date > tasks[j + 1].start_date);
                    break;
                case 2:
                    swap_needed = (tasks[j].deadline > tasks[j + 1].deadline);
                    break;
                case 3:
                    swap_needed = (tasks[j].priority > tasks[j + 1].priority);
                    break;
                default:
                    printf("Invalid option!\n");
                    getchar();
                    return;
            }
            
            // Swap
            if (swap_needed) {
                swap(&tasks[j], &tasks[j + 1]);
            }
        }
    }

    printf("Tasks sorted successfully!\n");
    getchar();
}