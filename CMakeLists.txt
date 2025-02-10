cmake_minimum_required(VERSION 3.29)
project(csi_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(csi_system main.cpp
        src/conversation_engine.cpp
        src/conversation_engine.h
        tests/test_basic_threading.cpp
        src/conversation_buffer.cpp
        src/conversation_buffer.h
        src/protected_conversation_engine.cpp
        src/protected_conversation_engine.h
        tests/test_protected_shared_memory.cpp
        src/deadlock_simulation.cpp
        src/deadlock_simulation.h
        tests/test_deadlock_occurs.cpp
        src/deadlock_resolution.cpp
        src/deadlock_resolution.h
        tests/test_deadlock_resolution.cpp
        src/ipc_demo.cpp
        tests/test_ipc.cpp
)
