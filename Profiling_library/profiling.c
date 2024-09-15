#include "profiling.h"

Profiler profiler;

uint64_t get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64_t)(tv.tv_sec) * 1000000 + (uint64_t)(tv.tv_usec);
}

void init_profiler() {
    profiler.task_count = 0;
}

int add_task(const char* name) {
    if (profiler.task_count >= MAX_TASKS) {
        return -1;  // Profiler is full
    }
    
    Task* task = &profiler.tasks[profiler.task_count];
    strncpy(task->name, name, MAX_TASK_NAME_LENGTH - 1);
    task->name[MAX_TASK_NAME_LENGTH - 1] = '\0';
    task->total_time = 0;
    task->call_count = 0;
    
    return profiler.task_count++;
}

void start_task(int task_id) {
    if (task_id >= 0 && task_id < profiler.task_count) {
        profiler.tasks[task_id].start_time = get_current_time();
    }
}

void end_task(int task_id) {
    if (task_id >= 0 && task_id < profiler.task_count) {
        uint64_t end_time = get_current_time();
        uint64_t duration = end_time - profiler.tasks[task_id].start_time;
        profiler.tasks[task_id].total_time += duration;
        profiler.tasks[task_id].call_count++;
    }
}

void print_profiling_results() {
    for (int i = 0; i < profiler.task_count; i++) {
        Task* task = &profiler.tasks[i];
        printf("Task: %s\n", task->name);
        printf("  Total time: %llu microseconds\n", task->total_time);
        printf("  Call count: %u\n", task->call_count);
        printf("  Average time: %llu microseconds\n", task->call_count > 0 ? task->total_time / task->call_count : 0);
        printf("\n");
    }
}

void save_profiling_results(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing\n");
        return;
    }

    for (int i = 0; i < profiler.task_count; i++) {
        Task* task = &profiler.tasks[i];
        fprintf(file, "Task: %s\n", task->name);
        fprintf(file, "  Total time: %llu microseconds\n", task->total_time);
        fprintf(file, "  Call count: %u\n", task->call_count);
        fprintf(file, "  Average time: %llu microseconds\n", task->call_count > 0 ? task->total_time / task->call_count : 0);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Profiling results saved to %s\n", filename);
}
