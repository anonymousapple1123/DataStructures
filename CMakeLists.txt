cmake_minimum_required(VERSION 3.10)

# Set the project name
project(data_structures)

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/src/HeaderFiles)

# Find all source files in the implementation directory
file(GLOB SOURCES "src/ImplementationFiles/*.cpp")

# Add the executable target
add_executable(MyExecutable ${SOURCES})
