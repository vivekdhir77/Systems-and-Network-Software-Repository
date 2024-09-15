#ifndef PROFILING_H
#define PROFILING_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 20

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    uint64_t start_time;
    uint64_t total_time;
    uint32_t call_count;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} Profiler;

extern Profiler profiler;

uint64_t get_current_time();
void init_profiler();
int add_task(const char* name);
void start_task(int task_id);
void end_task(int task_id);
void print_profiling_results();
void save_profiling_results(const char* filename);

#endif // PROFILING_H
