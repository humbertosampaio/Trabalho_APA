cmake_minimum_required(VERSION 3.10)
project(Trabalho_APA)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Trabalho_APA
        FileReader.cpp
        FileReader.h
        Golomb.cpp
        Golomb.h
        Grafo.cpp
        Grafo.h
        HeapSort.cpp
        HeapSort.h
        main.cpp
        QuickSort.cpp
        QuickSort.h)
