cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ConcreteLib)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# ==========================
# Main Library Configuration
# ==========================

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add library target
add_library(ConcreteLib 
    src/core/Analysis.cpp
    src/core/Material.cpp
    src/core/Rebar.cpp
    src/core/Section.cpp
)

# Add executable target (optional)
add_executable(conc
    src/main.cpp
)

# Link the library to the executable
target_link_libraries(conc ConcreteLib)