cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ConcreteLib)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# ==========================
# Main Library Configuration
# ==========================

# Add library target
add_library(ConcreteLib STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/Analysis.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/Material.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/Rebar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/core/Section.cpp
)

# Add include directories
target_include_directories(ConcreteLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)


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
${CMAKE_CURRENT_SOURCE_DIR}/core_tests.cpp  # Add your test files here
)

target_include_directories(initTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Link the library to the executable
target_link_libraries(initTest PRIVATE ConcreteLib)

# Link Google Test and the library under test
target_link_libraries(initTest PRIVATE GTest::GTest GTest::Main pthread ConcreteLib)

# Discover and register tests with CTest
include(GoogleTest)
gtest_discover_tests(initTest)
