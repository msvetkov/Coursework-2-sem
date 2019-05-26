cmake_minimum_required(VERSION 3.13)
project(course_work)

set(CMAKE_CXX_STANDARD 14)

add_executable(course_work main.cpp header_files/str.h header_files/str_node.h source_files/str_node.cpp source_files/str_list.cpp header_files/str_list.h header_files/book.h source_files/book_node.cpp header_files/book_node.h source_files/book_list.cpp header_files/book_list.h source_files/ref_node.cpp header_files/ref_node.h source_files/ref_list.cpp header_files/ref_list.h source_files/search.cpp header_files/search.h source_files/book_io.cpp header_files/book_io.h)