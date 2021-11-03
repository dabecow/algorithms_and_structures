cmake_minimum_required(VERSION 3.15)
project(algorithms_and_structures)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_DIR "C:/labs/Semestr 5/algorithms_and_structures")

file(GLOB_RECURSE SOURCES ${PROJECT_DIR}/src/*.cpp ${PROJECT_DIR}/src/*.h ${PROJECT_DIR}/main.cpp)

add_executable(algorithms_and_structures ${SOURCES})

target_include_directories(algorithms_and_structures PUBLIC ${PROJECT_DIR}/src/sorting)
target_include_directories(algorithms_and_structures PUBLIC ${PROJECT_DIR}/src/structures)

target_link_libraries(algorithms_and_structures -lmingw32)
