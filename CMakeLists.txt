cmake_minimum_required(VERSION 3.5)

project("Book Store")

set(PROJECT_DESCRIPTION "Book Store Management System")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/test)


add_executable(
    book_store
    book_store.cc
)



target_include_directories(
    book_store
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)



add_subdirectory(${CMAKE_SOURCE_DIR}/src)

target_link_libraries(
    book_store
    book_store_lib
)

target_include_directories(
    book_store
    PRIVATE
    ${CMAKE_BINARY_DIR}
)
