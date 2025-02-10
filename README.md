
# Test-Cases and Direct Project Implementations

## Overview

This project demonstrates a key operating system concepts including:
- **Multi-threading:** Basic thread operations simulating conversation channels.
- **Resource Protection:** Thread-safe access to shared conversation buffers using mutexes.
- **Deadlock Simulation & Resolution:** Deliberate deadlock creation and resolution via global lock ordering.
- **Inter-Process Communication (IPC):** A demonstration using Unix pipes to simulate communication between a conversation engine and a CSI module.

The code is written in C++ and built using CMake. This project is intended for Linux environments (tested on Arch Linux) due to the use of Unix-specific IPC functions.

## Directory Structure

- **src/**  
  Contains all the source code and header files.
  - `conversation_engine.h/cpp` – Basic conversation simulation with threads.
  - `conversation_buffer.h/cpp` – Thread-safe conversation buffer.
  - `protected_conversation_engine.h/cpp` – Conversation engine that demonstrates resource protection.
  - `deadlock_simulation.h/cpp` – Code for simulating deadlock conditions.
  - `deadlock_resolution.h/cpp` – Code for resolving deadlocks via global lock ordering.
  - `ipc_demo.cpp` – Demonstrates inter-process communication using pipes.
  - `main.cpp` – Main entry point for the conversation system demo.
  
- **tests/**  
  Contains test executables for individual modules.
  - `test_basic_threading.cpp`
  - `test_protected_shared_memory.cpp`
  - `test_deadlock_occurs.cpp`
  - `test_deadlock_resolution.cpp`
  - `test_ipc.cpp`

- **CMakeLists.txt** – The CMake build configuration file.

- **build/** - The Directory to create and run cmake in.

## Linux Requirements (for IPC Testing)

- This project uses Unix pipes and `fork()`, so it must be run on a POSIX-compliant system (e.g., Arch Linux).
- Ensure that your system has:
  - A C++ compiler with C++20 support (e.g., `g++`)
  - CMake (version 3.29 or later)

## Build Instructions

1. **Create a Build Directory:**
   Open a terminal in the project root and run:
   ```bash
   mkdir build
   cd build
   ```

2. **Configure the Project with CMake:**
   From within the build directory, run:
   ```bash
   cmake ..
   ```

3. **Build the Project:**
   After configuration, build the project with:
   ```bash
   make
   ```
   This will compile all targets and place the executables in the `bin/` subdirectory inside the build folder.

## Running the Executables

Executables are located in the `build/bin/` directory. Here are the commands to run each demo or test:

- **Main Conversation System Demo:**
  ```bash
  ./bin/csi_system
  ```

- **IPC Demo (using pipes on Linux):**
  ```bash
  ./bin/ipc_demo
  ```

- **Running Tests:**
  - Basic Threading Test:
    ```bash
    ./bin/test_basic_threading
    ```
  - Protected Shared Memory Test:
    ```bash
    ./bin/test_protected_shared_memory
    ```
  - Deadlock Occurrence Test:
    ```bash
    ./bin/test_deadlock_occurs
    ```
  - Deadlock Resolution Test:
    ```bash
    ./bin/test_deadlock_resolution
    ```
  - IPC Test:
    ```bash
    ./bin/test_ipc
    ```

## Summary

This CSI system project is designed to provide a complete demonstration of:
- Multi-threading and thread management in a simulated conversation environment.
- Protection of shared resources using mutexes.
- Simulation of deadlocks and their resolution.
- Inter-process communication via pipes for a simplified CSI module interface.

For Linux users, the IPC demo showcases the use of Unix pipes and process forking. The project is modular, allowing you to test and expand individual components independently. Enjoy exploring and extending the system!
