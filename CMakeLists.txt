cmake_minimum_required(VERSION 3.14)
project(Inar)

set(CMAKE_CXX_STANDARD 17)
add_executable(Inar src/main.cpp src/Graphics.cpp src/movementHandling.cpp)
target_include_directories(Inar PRIVATE src)

# link Aruna
set(aruna_DIR libs/aruna)
find_package(aruna)
add_dependencies(Inar aruna)
add_dependencies(Inar glfw)
target_link_libraries(Inar aruna)
target_link_libraries(Inar glfw)
