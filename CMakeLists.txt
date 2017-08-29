# Author: Frank Leveque
# Simple CMakeLists.txt file using glob and basic flags

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Prevented in-tree build. Please use shell script.")
endif()

CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
SET(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
SET(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
SET(CMAKE_C_STANDARD 99)
SET(CMAKE_CXX_STANDARD 11)

SET(ProjectName Matasano)

PROJECT(${ProjectName})

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/include)

FILE(GLOB Headers 
    ${CMAKE_SOURCE_DIR}/include/*.hpp 
    ${CMAKE_SOURCE_DIR}/include/*.h)
FILE(GLOB Sources 
    ${CMAKE_SOURCE_DIR}/src/hexconverter.cpp
    ${CMAKE_SOURCE_DIR}/src/b64converter.cpp
    )
FILE(GLOB TestSources 
    ${CMAKE_SOURCE_DIR}/tests/*.cpp)

ADD_EXECUTABLE(Tests
    ${Headers}
    ${Sources}
    ${TestSources})

ADD_EXECUTABLE(challenge1
    ${Headers}
    ${Sources}
    ${CMAKE_SOURCE_DIR}/src/challenge1.cpp
    )

ADD_EXECUTABLE(challenge2
    ${Headers}
    ${Sources}
    ${CMAKE_SOURCE_DIR}/src/challenge2.cpp
    )


ADD_EXECUTABLE(challenge3
    ${Headers}
    ${Sources}
    ${CMAKE_SOURCE_DIR}/src/challenge3.cpp
    )


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -static -static-libgcc -static-libstdc++ ")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s -Os")

