cmake_minimum_required(VERSION 3.31)
project(hanshu C)

set(CMAKE_C_STANDARD 99)

add_executable(hanshu change.c
        height.c
        priority.c
        if.c
        while.c
        data-sequence.c
        data-LinkList.c
)
