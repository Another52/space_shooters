cmake_minimum_required(VERSION 3.28)
project(spacefighters LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC headers/)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE SFML::Graphics SFML::Audio)

if(TARGET SFML::Main)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE SFML::Main)
endif()

#code macros
target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")