#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/task_create.h"
#include "include/save_to_file.h"

#include "model/task.h"

void task_create() {
	// Declare and allocate memory for 1 struct
	Task *task = (Task *)malloc(sizeof(Task));

	// Clear input buffer
	while (getchar() != '\n');

	printf("To cancel type '0'\n\n");

	// Get title from user
	printf("Enter title: ");
	fgets(task->title, sizeof(task->title), stdin);
	task->title[strcspn(task->title, "\n")] = 0; // Remove newline in array
	if (strcmp(task->title, "0") == 0) return;

	// Get description from user
	printf("Enter description: ");
	fgets(task->description, sizeof(task->description), stdin);
	task->description[strcspn(task->description, "\n")] = 0;
	if (strcmp(task->description, "0") == 0) return;

	// Declare variables to store datetime 
	int start_day, start_month, start_year, start_hour, start_minute; 
	int deadline_day, deadline_month, deadline_year, deadline_hour, deadline_minute;
	
	// Get start date from user 
	printf("Enter Start Date (DD MM YYYY): ");
    scanf("%d %d %d", &start_day, &start_month, &start_year);
	if (start_day == 0 || start_month == 0 || start_year == 0) return;
	getchar();

    // Get start time from user
	printf("Enter Start Time (HH MM, 24-hour format): ");
    scanf("%d %d", &start_hour, &start_minute);
	if (start_hour == 0 || start_minute == 0) return;
	getchar();
	
	// Create datetime format YYYY/MM/DD HH/MM
	task->start_date = (
		((long long)start_year * 100000000) + 
		((long long)start_month * 1000000) + 
		((long long)start_day * 10000) + 
		(start_hour * 100) + 
		start_minute
	);

	// Get deadline from user
	printf("Enter Deadline (DD MM YYYY): ");
    scanf("%d %d %d", &deadline_day, &deadline_month, &deadline_year);
	if (deadline_day == 0 || deadline_month == 0 || deadline_year == 0) return;
	getchar();

	// Get deadline time from user
    printf("Enter Deadline Time (HH MM, 24-hour format): ");
    scanf("%d %d", &deadline_hour, &deadline_minute);
	if (deadline_hour == 0 || deadline_minute == 0) return;
	getchar();
	
	task->deadline = (
		((long long)deadline_year * 100000000) + 
		((long long)deadline_month * 1000000) + 
		((long long)deadline_day * 10000) + 
		(deadline_hour * 100) + 
		deadline_minute
	);

	// Get priority from user
	printf("Enter priority (1 - 4): ");
	scanf("%d", &task->priority);
	if (task->priority == 0) return;
	getchar();
	
	// Save 'task' struct to csv file
	save_to_file(task);

	// Deallocate 'task' variable
	free(task);
}
