cmake_minimum_required(VERSION 3.10)

project(ManInTheMiddleDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(OpenSSL REQUIRED)

#include_directories(OPENSSL_INCLUDE_DIR)

include_directories(include/asio/asio/include)

add_subdirectory(src)