cmake_minimum_required(VERSION 2.8)	 

project(OOP1)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB Long.cpp)	

add_library(Long STATIC ${SOURCE_LIB})

add_executable(oop_exercise_01 ${SOURCE_EXE})	

target_link_libraries(oop_exercise_01 Long)