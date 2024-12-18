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

# ==========================
# Google Test Integration
# ==========================

# Enable testing
enable_testing()

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(initTest
    tests/core_tests.cpp  # Add your test files here
)

# Link Google Test and the library under test
target_link_libraries(initTest GTest::GTest GTest::Main pthread ConcreteLib)

# Discover and register tests with CTest
include(GoogleTest)
gtest_discover_tests(initTest)
