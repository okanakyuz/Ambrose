cmake_minimum_required(VERSION 3.0.0)
project(Ambrose VERSION 0.1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(Ambrose src/main.cpp src/Window.cpp)

find_package(glm CONFIG REQUIRED)
target_link_libraries(Ambrose PRIVATE glm)

find_package(SFML COMPONENTS graphics CONFIG REQUIRED)
target_link_libraries(Ambrose PRIVATE 
    FLAC OpenAL OpenGL Vorbis 
    sfml-graphics)

