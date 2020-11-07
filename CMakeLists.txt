cmake_minimum_required(VERSION 2.8)

project(main)

#aux_source_directory(. SRC_LIST)

set(VECTOR_SRC main.cpp Node.cpp CStack.cpp Autotest.cpp data.txt datadat.txt autotest.txt)
set(VECTOR_HDR Node.h CStack.h)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")