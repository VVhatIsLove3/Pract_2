cmake_minimum_required(VERSION 3.10)
project(sp2 C)

set(CMAKE_C_STANDARD 11)

add_executable(sp2 main.c users.c processes.c help.c logger.c error_handler.c)
