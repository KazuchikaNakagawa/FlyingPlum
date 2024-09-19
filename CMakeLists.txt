cmake_minimum_required(VERSION 3.22)

# this needs u8string support
set(CMAKE_CXX_STANDARD 20)

project(FlyingPlum)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(engine)
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(support)
add_subdirectory(token)
add_subdirectory(ast)