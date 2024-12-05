cmake_minimum_required(VERSION 3.22)

project(advent-of-code-2024 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

file(GLOB globbed *.cpp)

foreach( src_file ${globbed} )
    cmake_path(GET src_file STEM stem)
    set(target_name advent-of-code-${stem})
    add_executable(${target_name} ${src_file}) 
    set_target_properties(${target_name} PROPERTIES
                          XCODE_GENERATE_SCHEME TRUE
                          XCODE_SCHEME_WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                          XCODE_SCHEME_ARGUMENTS "in.txt")
endforeach()
