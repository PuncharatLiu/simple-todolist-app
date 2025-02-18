#include <stdio.h>
#include <stdlib.h>

// Include task operation function
#include "include/task_create.h"
#include "include/load_task_from_csv.h"
#include "include/task_display.h"
#include "include/task_delete.h"
#include "include/task_edit.h"
#include "include/tasks_sort.h"
#include "include/task_search.h"
#include "include/clear_terminal.h"

// Include task struct
#include "model/task.h"

// Define utility function
void menu();
void clear_terminal();

// Define global variables
int task_count; // To track the number of tasks in the array 'tasks'
Task tasks[200]; // Array for temp store task

int main() {
	// Load tasks from the csv file and store in array 'tasks'
	task_count = load_task_from_csv(tasks);

	// App loop
	while (1) {
		if (task_count > 0) { // If there's task 
        	clear_terminal();
			
			printf("------------------------------------------------------------\n");
    		printf("|                TO-DO LIST APPLICATION                     |\n");
    		printf("------------------------------------------------------------\n");
			
			task_display(tasks, task_count);
    	} else {
        	printf("\nNo tasks found or file is missing!\n");
    	}	

		char open_menu = '\0';
		printf("\nType 'm' to open app menu: ");
		scanf(" %c", &open_menu);

		if (open_menu == 'm') { // If user open app menu
			menu();
		}
	}
	
	return 0;
}

/*
Function to show the application menus 
and the entry point for task operation 
*/
void menu() {
	clear_terminal();

	char menu = '\0';
	printf("1. Create task\n");
	printf("2. Delete task\n");
	printf("3. Edit task\n");
	printf("4. Sort tasks\n");
	printf("5. Search task\n\n");
	printf("Type 'c' to close app menu\n");
	printf("\nEnter the menu number: ");
	
	while (getchar() != '\n');
	
	scanf(" %c", &menu);

	switch (menu) {
		case '1': // Create task
			clear_terminal();
			printf("|---------------------------|\n");
			printf("|####### CREATE TASK #######|\n");
			printf("|---------------------------|\n\n");
			task_create();
			task_count = load_task_from_csv(tasks);
			break;
		case '2': // Delete task
			clear_terminal();
			printf("|---------------------------|\n");
			printf("|####### DELETE TASK #######|\n");
			printf("|---------------------------|\n\n");
			task_display(tasks, task_count);
			task_delete();
			task_count = load_task_from_csv(tasks);
			break;
		case '3': // Edit task
			clear_terminal();
			printf("|---------------------------|\n");
			printf("|######## EDIT TASK ########|\n");
			printf("|---------------------------|\n\n");
			task_display(tasks, task_count);
			task_edit();
			task_count = load_task_from_csv(tasks); 
			break;
		case '4': // Sort tasks
			clear_terminal();
			printf("|---------------------------|\n");
			printf("|######## SORT TASK ########|\n");
			printf("|---------------------------|\n\n");
			tasks_sort(tasks, task_count);
			break;
		case '5': // Search tasks
			clear_terminal();
			printf("|---------------------------|\n");
			printf("|####### SEARCH TASK #######|\n");
			printf("|---------------------------|\n\n");
			task_search(tasks, task_count);
			break;
		case 'c': // Close app menu
			clear_terminal();
			task_display(tasks, task_count);
			break;
		default:
			break;
	}
}