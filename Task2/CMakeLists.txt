cmake_minimum_required(VERSION 3.21)
project(CPS1011_Task2 C)

set(CMAKE_C_STANDARD 11)


set(SOURCE_FILES1 Datatable.h main.c)
add_executable(CPS1011_Task2 ${SOURCE_FILES1})


add_library(Datatable SHARED Datatable.c)
target_link_libraries(CPS1011_Task2 Datatable)


