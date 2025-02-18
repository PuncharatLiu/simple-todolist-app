#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "model/task.h" // Task struct and array

#define FILE_NAME "task.csv" // File where task stored

/*
Function to load task's data from csv file 
(title, description, start date, deadline, priority).
and store each task's data to array
*/
int load_task_from_csv(Task *tasks) {
    FILE *file = fopen(FILE_NAME, "r"); // Open file with read permission
    if (!file) { // Is file not file or error
        printf("Error opening file!\n");
        return 1;
    }

    char line[500]; // Temp for store each task's data
    int count = 0;

    fgets(line, sizeof(line), file); // Clear header

    while (fgets(line, sizeof(line), file)) { // Get eack task's data
        // Extract data in line and store in 'task' struct
        sscanf(line, "%99[^,],%199[^,],%lld,%lld,%d", 
            tasks[count].title, 
            tasks[count].description, 
            &tasks[count].start_date, 
            &tasks[count].deadline, 
            &tasks[count].priority
        );
        
        count++; // Increase count (the number of task)
    }

    fclose(file); // Close file

    return count; // Return the number of task
}