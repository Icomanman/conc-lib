cmake_minimum_required(VERSION 3.10)
# Set the project name
project(ConcreteLib)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add library target
add_library(ConcreteLib 
    src/core/Analysis.cpp
    src/core/Material.cpp
    src/core/Rebar.cpp
    src/core/Section.cpp
)

# If you have an executable that uses this library, add it here
add_executable(conc
    src/main.cpp
)

# Link the library to the executable (if needed)
target_link_libraries(conc ConcreteLib)
