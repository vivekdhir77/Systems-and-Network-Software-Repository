# Microcontroller Profiling Library

## Overview

This project provides a simple profiling library designed for use in microcontroller environments, along with an example program demonstrating its usage. The library allows you to measure and analyze the execution time of various tasks in your microcontroller application. 

Addtionally, the library has the option to save profiling results to non-volatile memory

## Definitions

- Task:
 It's essentially any block of code whose execution time you're interested in tracking. For example, in a microcontroller application, tasks might include:


Reading data from a sensor
Processing incoming data
Updating a display
Sending data over a network
Performing a calculation

- Profiler:
Manages the collection and reporting of performance data for multiple tasks. It performs several functions:

Keeps track of all the tasks being monitored
Measures the execution time of each task
Calculates statistics like total time and average time for each task
Provides an interface for starting and stopping timing for each task
Generates a report of the collected data


## Files

The project consists of three main files:

1. `profiling.h`: The header file for the profiling library.
2. `profiling.c`: The implementation of the profiling library.
3. `main.c`: An example program that demonstrates how to use the profiling library.

## Profiling Library (`profiling.h` and `profiling.c`)

### Key Features

- Supports up to 10 tasks (configurable via `MAX_TASKS`)
- Measures execution time in microseconds
- Calculates total time, call count, and average time for each task
- Easy-to-use API for adding tasks and measuring their execution time

### API Functions

- `void init_profiler()`: Initializes the profiler.
- `int add_task(const char* name)`: Adds a new task to be profiled. Returns the task ID.
- `void start_task(int task_id)`: Marks the start of a task execution.
- `void end_task(int task_id)`: Marks the end of a task execution.
- `void print_profiling_results()`: Prints the profiling results for all tasks.

### Data Structures

- `Task`: Represents a single task with its name, timing information, and call count.
- `Profiler`: Contains an array of tasks and keeps track of the number of tasks.

## Example Program (`main.c`)

The example program demonstrates how to use the profiling library in a simulated microcontroller environment. It defines three tasks:

1. Read Sensor
2. Process Data
3. Update Display

The program runs these tasks in a loop for 10 iterations, simulating a typical microcontroller main loop. After the iterations, it prints the profiling results.

## Usage

To use the profiling library in your own projects:

1. Include `profiling.h` in your source file.
2. Call `init_profiler()` at the beginning of your program.
3. Use `add_task()` to register each task you want to profile.
4. Wrap the code for each task with `start_task()` and `end_task()` calls.
5. Call `print_profiling_results()` when you want to see the profiling data.

## Compilation and Execution

To compile the example program:

```bash
clang -o profiling_example main.c profiling.c
```

To run the compiled program:

```bash
./profiling_example
```

## Output

The program will output the iteration number for each loop and then print the profiling results. The results include:

- Task name
- Total execution time (in microseconds)
- Number of times the task was called
- Average execution time per call (in microseconds)

## Customization

You can customize the library by modifying the following in `profiling.h`:

- `MAX_TASKS`: Maximum number of tasks that can be profiled (default: 10)
- `MAX_TASK_NAME_LENGTH`: Maximum length of a task name (default: 20)

## Limitations and Considerations

- The library uses `gettimeofday()` for timing, which may not be available on all microcontroller platforms. You may need to replace this with a platform-specific timing function.
- The example program uses `usleep()` to simulate work, which may not be available or appropriate for real microcontroller environments.
- This library is designed for basic profiling and may introduce some overhead. For extremely time-sensitive applications, you may need a more optimized solution.

## Future Improvements

- Add support for nested task measurements
- Implement memory usage tracking
- Create a more detailed report with statistical analysis of task execution times