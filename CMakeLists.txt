cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME ElectricFieldIntensity)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2")
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Drawer.cpp Drawer.h Field.cpp Field.h)

file(GLOB ALL_REQUIRED_DLL "C:/Libraries/SFML-2.5.1/bin/*.dll")
file(COPY ${ALL_REQUIRED_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML/")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
