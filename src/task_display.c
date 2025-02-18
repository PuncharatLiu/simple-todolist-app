#include <stdio.h>

#include "model/task.h"

// Function to format datetile DD/MM/YYYY HH:MM
void format_date(long long start_date, long long deadline) {
    // Extracting start date
    int start_year = start_date / 100000000;        // YYYY
    int start_month = (start_date / 1000000) % 100; // MM
    int start_day = (start_date / 10000) % 100;     // DD
    int start_hour = (start_date / 100) % 100;        // HH
    int start_minute = start_date % 100;             // MM

    // Extracting deadline
    int deadline_year = deadline / 100000000;        // YYYY
    int deadline_month = (deadline / 1000000) % 100; // MM
    int deadline_day = (deadline / 10000) % 100;     // DD
    int deadline_hour = (deadline / 100) % 100;        // HH
    int deadline_minute = deadline % 100;             // MM

    // Print formatted date
    printf("%02d/%02d/%04d %02d:%02d - %02d/%02d/%04d %02d:%02d\n",
           start_day, start_month, start_year, start_hour, start_minute,
           deadline_day, deadline_month, deadline_year, deadline_hour, deadline_minute);
}

// Function to display tasks
void task_display(Task *tasks, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("\n");
        printf(" ID:        %d\n", i + 1);
        printf(" Title:     %s\n", tasks[i].title);
        printf(" Desc:      %s\n", tasks[i].description);
        printf(" Duration:  ");
        format_date(tasks[i].start_date, tasks[i].deadline);
        if (tasks[i].priority == 1) {
            printf(" Priority:  Very High\n");    
        } else if (tasks[i].priority == 2) {
            printf(" Priority:  High\n");    
        } else if (tasks[i].priority == 3) {
            printf(" Priority:  Low\n");    
        } else {
            printf(" Priority:  Very Low\n");    
        }
        printf("________________________________\n");
    }
}