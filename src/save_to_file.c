#include <stdio.h>

#include "model/task.h"

#define FILE_NAME "task.csv"

/*
Function to check if file exist, if exist is there data
*/
int file_exist_with_data() {
    FILE *file = fopen(FILE_NAME, "r");
    
    if(!file){
        printf("There is no file name task.csv\n");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size > 0;
}

// Function to save task struct to csv file
int save_to_file(Task *task) {
    FILE *file = fopen(FILE_NAME, "a+");
    if (!file) {
        printf("Error opening the file\n");
        getchar();
        return 1;
    };

    int file_has_data = file_exist_with_data();

    if(!file_has_data) {
        fprintf(file, "title,description,start_date,deadline,priority\n");
    }

    fprintf(file, "%s,%s,%lld,%lld,%d\n", task->title, task->description, task->start_date, task->deadline, task->priority);

    fclose(file);
    printf("Task added successfully\n");
    getchar();
    return 0;
}