#include <stdio.h>
#include <string.h>

#include "include/clear_terminal.h"
#include "model/task.h"


#define FILE_NAME "task.csv"
#define TEMP_FILE "temp_task.csv"

// Function to edit task
void task_edit() {    
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP_FILE, "w");

    // If no file or temp
    if (!file || !temp) {
        printf("Error opening file!\n");
        getchar();
        return;
    }

    char line[350];
    int task_id;
    int task_count = 0;
    int edited = 0;

    printf("\nType '0' to cancel\n");
    printf("\nEnter the task ID: ");
    scanf("%d", &task_id);
    getchar();  // Clear leftover newline

    if (task_id == 0) return;

    if (fgets(line, sizeof(line), file)) {
        fprintf(temp, "%s", line);  // Write header
    }

    // Get task's data to temp file
    while (fgets(line, sizeof(line), file)) {
        task_count++;
        
        char title[100], description[200];
        long long int start_date, deadline;
        int priority;

        sscanf(line, "%99[^,],%199[^,],%lld,%lld,%d", title, description, &start_date, &deadline, &priority);

        if (task_id == task_count) {  // Corrected condition
            edited = 1;
            int field = 0;

            clear_terminal();

            printf("1. Title\n");
            printf("2. Description\n");
            printf("3. Start date\n");
            printf("4. Deadline\n");
            printf("5. Priority\n");
            printf("\nType '0' to Cancel\n");

            printf("\nEnter the field to edit: ");

            scanf("%d", &field);
            getchar();  // Clear buffer after scanf()

            int start_day, start_month, start_year, start_hour, start_minute; 
            int deadline_day, deadline_month, deadline_year, deadline_hour, deadline_minute;

            // Change by task's field
            switch (field) {
                case 1:
                    printf("Enter new title: ");
                    fgets(title, sizeof(title), stdin);
                    title[strcspn(title, "\n")] = 0;
                    break;
                case 2: 
                    printf("Enter new description: ");
                    fgets(description, sizeof(description), stdin);
                    description[strcspn(description, "\n")] = 0;
                    break;
                case 3:
                    printf("Enter new start date: ");

                    // Get start date from user 
                    printf("Enter Start Date (DD MM YYYY): ");
                    scanf("%d %d %d", &start_day, &start_month, &start_year);
                    getchar();

                    // Get start time from user
                    printf("Enter Start Time (HH MM, 24-hour format): ");
                    scanf("%d %d", &start_hour, &start_minute);
                    getchar();
                    // Create datetime format YYYY/MM/DD HH/MM
                    start_date = (
                        ((long long)start_year * 100000000) + 
                        ((long long)start_month * 1000000) + 
                        ((long long)start_day * 10000) + 
                        (start_hour * 100) + 
                        start_minute
                    );
                    break;
                case 4:
                    printf("Enter new deadline: ");

                    // Get deadline from user
                    printf("Enter Deadline (DD MM YYYY): ");
                    scanf("%d %d %d", &deadline_day, &deadline_month, &deadline_year);
                    getchar();

                    // Get deadline time from user
                    printf("Enter Deadline Time (HH MM, 24-hour format): ");
                    scanf("%d %d", &deadline_hour, &deadline_minute);
                    getchar();

                    deadline = (
                        ((long long)deadline_year * 100000000) + 
                        ((long long)deadline_month * 1000000) + 
                        ((long long)deadline_day * 10000) + 
                        (deadline_hour * 100) + 
                        deadline_minute
                    );
                    break;
                case 5:
                    printf("\nEnter new priority: ");
                    scanf("%d", &priority);
                    getchar();
                    break;
                case 0:
                    return;
                default:
                    printf("Invalid option!\n");
                    getchar();
                    return;
            }
        }

        // Write to temp file
        fprintf(temp, "%s,%s,%lld,%lld,%d\n", title, description, start_date, deadline, priority);
    }

    fclose(file);
    fclose(temp);

    // If task edited remove task.csv and rename temp file to task.csv
    if (edited) {
        remove(FILE_NAME);
        rename(TEMP_FILE, FILE_NAME);
        printf("\nTask ID '%d' edited successfully!\n", task_id);
    } else {
        remove(TEMP_FILE);
        printf("\nTask '%d' not found!\n", task_id);
    }

    getchar();
}
