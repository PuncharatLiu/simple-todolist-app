#include <stdio.h>

#include "model/task.h"

#define FILE_NAME "task.csv"
#define TEMP_FILE "temp_task.csv"

//Function to delete task from csv file
void task_delete() {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP_FILE, "w");

    if (!file && !temp) { // If no file or temp
        printf("Error opening file!\n");
        getchar();
        return;
    }

    char line[350];
    int task_id;  
    int task_count = 0;
    int deleted = 0;

    printf("\nType '0' to cancel\n");
    printf("\nEnter the task ID: ");
    scanf("%d", &task_id);

    if (task_id == 0) return;

    getchar();

    // Write header to temp file
    if (fgets(line, sizeof(line), file)) {
        fprintf(temp, "%s", line);
    }

    // Get and extract task's data to temp file
    while (fgets(line, sizeof(line), file)) {
        task_count++;
        
        char title[100], description[200];
        long long int start_date, deadline; 
        int priority;

        sscanf(line, "%99[^,],%199[^,],%lld,%lld,%d", title, description, &start_date, &deadline, &priority);

        if (task_id == task_count) {
            deleted = 1;
            continue; 
        }

        fprintf(temp, "%s,%s,%lld,%lld,%d\n", title, description, start_date, deadline, priority);
    }

    // Close file
    fclose(file);
    fclose(temp);

    // If task deleted
    if (deleted) {
        remove(FILE_NAME);  
        rename(TEMP_FILE, FILE_NAME);
        printf("Task ID '%d' deleted successfully!\n", task_id);
        getchar();
    } else {
        remove(TEMP_FILE); 
        printf("Task '%d' not found!\n", task_id);
        getchar();
    }
}