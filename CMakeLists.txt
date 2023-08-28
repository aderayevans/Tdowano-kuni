cmake_minimum_required(VERSION 3.22.1) # 3.22.1 is shipping with ubuntu 22.04
project(SDL2_Template VERSION 1.0)

# Make sure to add the CMAKE_CXX_STANDARD declarations above the call to add_executable()
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
add_compile_options(
    $<$<CXX_COMPILER_ID:GNU>:-Wno-psabi>
    $<$<CXX_COMPILER_ID:GNU>:-funwind-tables>
    $<$<CXX_COMPILER_ID:GNU>:-fasynchronous-unwind-tables>
)

# https://stackoverflow.com/questions/75551185/cmake-using-sdl2-and-sdl2-image-via-fetchcontent
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.26.3
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL2)

FetchContent_Declare(
    SDL2_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-2.6.3
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
set(SDL2IMAGE_INSTALL OFF)
set(BUILD_SHARED_LIBS FALSE)
FetchContent_MakeAvailable(SDL2_image)

add_executable(${PROJECT_NAME} 
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE include/
)

target_link_libraries(${PROJECT_NAME} 
    SDL2::SDL2main SDL2::SDL2-static 
    SDL2_image::SDL2_image-static
)
