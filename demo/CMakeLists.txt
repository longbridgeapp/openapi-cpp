# Works with 3.11 and tested through 3.23
cmake_minimum_required(VERSION 3.11...3.23)

set (CMAKE_CXX_STANDARD 20)

project("Longbridge OpenAPI Demo"
        VERSION 0.1
        DESCRIPTION "Longbridge OpenAPI c++ demo"
        LANGUAGES CXX)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(logger src/logger.cpp)
target_link_libraries(logger longbridge)

add_executable(http src/http.cpp)
target_link_libraries(http longbridge)

add_executable(ws_test src/websocket_test.cpp src/proto/quote.pb.cc)
target_link_libraries(ws_test longbridge)
target_link_libraries(ws_test ${Protobuf_LIBRARIES})