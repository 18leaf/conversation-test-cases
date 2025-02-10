cmake_minimum_required(VERSION 3.29)
project(csi_system)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include the src directory for header files.
include_directories(${CMAKE_SOURCE_DIR}/src)

# ------------------------------------------------------------------------------
# Create a static library with common source files.
# (Note: ipc_demo.cpp is a standalone executable so it’s not part of this library.)
add_library(csi_lib
        src/conversation_engine.cpp
        src/conversation_buffer.cpp
        src/protected_conversation_engine.cpp
        src/deadlock_simulation.cpp
        src/deadlock_resolution.cpp
)

# ------------------------------------------------------------------------------
# Main Executable for the Conversation System.
add_executable(csi_system
        src/main.cpp
)
target_link_libraries(csi_system PRIVATE csi_lib)

# ------------------------------------------------------------------------------
# Standalone Executable for the IPC Demo.
add_executable(ipc_demo
        src/ipc_demo.cpp
)
target_link_libraries(ipc_demo PRIVATE csi_lib)

# ------------------------------------------------------------------------------
# Test Executables.
add_executable(test_basic_threading
        tests/test_basic_threading.cpp
)
target_link_libraries(test_basic_threading PRIVATE csi_lib)

add_executable(test_protected_shared_memory
        tests/test_protected_shared_memory.cpp
)
target_link_libraries(test_protected_shared_memory PRIVATE csi_lib)

add_executable(test_deadlock_occurs
        tests/test_deadlock_occurs.cpp
)
target_link_libraries(test_deadlock_occurs PRIVATE csi_lib)

add_executable(test_deadlock_resolution
        tests/test_deadlock_resolution.cpp
)
target_link_libraries(test_deadlock_resolution PRIVATE csi_lib)

add_executable(test_ipc
        tests/test_ipc.cpp
)
target_link_libraries(test_ipc PRIVATE csi_lib)

# ------------------------------------------------------------------------------
# Enable CTest and register the test executables.
enable_testing()
add_test(NAME BasicThreadingTest COMMAND test_basic_threading)
add_test(NAME ProtectedSharedMemoryTest COMMAND test_protected_shared_memory)
add_test(NAME DeadlockOccursTest COMMAND test_deadlock_occurs)
add_test(NAME DeadlockResolutionTest COMMAND test_deadlock_resolution)
add_test(NAME IPC_Test COMMAND test_ipc)
