#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "include/task_display.h"
#include "model/task.h"

// Convert a string to lowercase for case-insensitive search
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to search for tasks based on a specific field
void task_search(Task *tasks, int task_count) {
    if (task_count == 0) {
        printf("No tasks available!\n");
        getchar();
        return;
    }

    int field;
    printf("Select a field to search by:\n");
    printf("1. Title\n");
    printf("2. Description\n");
    printf("3. Start Date\n");
    printf("4. Deadline\n");
    printf("5. Priority\n");
    printf("\nType '0' to cancel\n\n");
    printf("Enter field number: ");
    scanf("%d", &field);
    getchar(); // Clear newline from input buffer

    if (field == 0) return;

    char search_term[100];
    int search_int = -1; // For numeric fields

    if (field == 1 || field == 2) {
        printf("Enter search term: ");
        fgets(search_term, sizeof(search_term), stdin);
        search_term[strcspn(search_term, "\n")] = 0; // Remove newline
        to_lowercase(search_term); // Convert to lowercase
    } else {
        printf("Enter search number: ");
        scanf("%d", &search_int);
        getchar();
    }
    
    int found = 0;

    printf("\nMatching Tasks:\n\n");
    for (int i = 0; i < task_count; i++) {
        int match = 0;

        if (field == 1) {
            char title_lower[100];
            strcpy(title_lower, tasks[i].title);
            to_lowercase(title_lower);
            if (strstr(title_lower, search_term)) match = 1;
        } else if (field == 2) {
            char description_lower[200];
            strcpy(description_lower, tasks[i].description);
            to_lowercase(description_lower);
            if (strstr(description_lower, search_term)) match = 1;
        } else if (field == 3 && tasks[i].start_date == search_int) {
            match = 1;
        } else if (field == 4 && tasks[i].deadline == search_int) {
            match = 1;
        } else if (field == 5 && tasks[i].priority == search_int) {
            match = 1;
        }

        if (match) {
            found = 1;
            Task *temp_tasks[1] = {&tasks[i]};
            task_display(temp_tasks[i], 1);
        }
    }

    if (!found) {
        printf("No matching tasks found!\n");
    }
    
    getchar();
}
