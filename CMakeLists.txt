cmake_minimum_required (VERSION 3.8)

project ("Trabalho_APA")

# Include sub-projects.
#add_subdirectory ("Trabalho_APA")

#set (my_includes Golomb.h")
#set (my_cpps "Golomb.cpp" "main.cpp")
file(GLOB includes "*.h")
file(GLOB cpps "*.cpp")
add_executable (main ${includes} ${cpps})