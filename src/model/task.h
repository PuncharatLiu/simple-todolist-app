#ifndef TASK_H
#define TASK_H

typedef struct {
	char title[100];
	char description[200];
	long long int  start_date;
	long long int  deadline;
	int  priority;
} Task;

Task tasks[200];

extern Task task;
extern Task tasks[];

#endif