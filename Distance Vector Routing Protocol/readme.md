# Distance Vector Routing Protocol in C++

This repository contains a simple implementation of the Distance Vector Routing Protocol in C++. The Distance Vector Routing Protocol is used in networking to determine the shortest path for routing data between nodes in a network.

## Overview

The program simulates a network of routers using the Distance Vector Routing Protocol. It allows users to define the number of routers and the links between them, then calculates and displays the distance vector for each router.

## Features

- **Dynamic Router Setup**: Enter the number of routers and links interactively.
- **Distance Vector Calculation**: Automatically calculates and updates distance vectors based on input links.
- **Output**: Displays initial and updated distance vectors for each router.

## Getting Started

### Prerequisites

- A C++ compiler

### Compilation

To compile the program, use the following command:

```sh
g++ -o distance_vector main.cpp
```