cmake_minimum_required(VERSION 3.8)
project(Arguing)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES ${SOURCES}
        argument.h
        listener.h
)

set(GCC_COVERAGE_COMPILE_FLAGS "-lstdc++ -pedantic -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_library(listener listener.cpp ${SOURCE_FILES} ${SOURCES})

set(OBJECTS listener)

add_executable(${PROJECT_NAME}.out Source.cpp ${OBJECTS} ${SOURCE_FILES} ${SOURCES})
