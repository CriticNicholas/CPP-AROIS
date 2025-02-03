cmake_minimum_required(VERSION 3.10)

project(ManInTheMiddleDemo)

#find_package(OpenSSL REQUIRED)

#include_directories(OPENSSL_INCLUDE_DIR)

include_directories(include/asio/asio/include)

add_subdirectory(src)