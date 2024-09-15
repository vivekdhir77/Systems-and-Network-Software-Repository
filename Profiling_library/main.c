#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "profiling.h"

void task_read_sensor() {
    usleep(50000);
}

void task_process_data() {
    usleep(100000);
}

void task_update_display() {
    usleep(75000); 
}

int main() {
    init_profiler();
    int task_read = add_task("Read Sensor");
    int task_process = add_task("Process Data");
    int task_display = add_task("Update Display");
    
    for (int i = 0; i < 10; i++) {
        printf("Iteration %d\n", i + 1);

        start_task(task_read);
        task_read_sensor();
        end_task(task_read);

        start_task(task_process);
        task_process_data();
        end_task(task_process);

        start_task(task_display);
        task_update_display();
        end_task(task_display);

        usleep(200000); 
    }

    print_profiling_results();
    save_profiling_results("profiling_results.txt");
}
