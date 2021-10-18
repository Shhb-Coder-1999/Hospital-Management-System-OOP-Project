cmake_minimum_required(VERSION 3.17)
project(Final_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Final_Project
        Doctor.cpp
        Doctor.h
        Hospital.cpp
        Hospital.h
        Human.cpp
        Human.h
        main.cpp
        Nurse.cpp
        Nurse.h
        Patient.cpp
        Patient.h)
