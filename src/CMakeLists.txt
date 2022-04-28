# Works with 3.11 and tested through 3.23
cmake_minimum_required(VERSION 3.11...3.23)


project("Longbridge OpenAPI src"
        VERSION 0.1
        DESCRIPTION "Longbridge OpenAPI c++"
        LANGUAGES CXX)


add_library(longbridge STATIC ./lib.cpp ./http.cpp cxx/logger.rs.cc cxx/http.rs.cc cxx/lib.rs.cc ./websocket.cpp cxx/ws.rs.cc)
IF (WIN32)
    target_link_directories(longbridge PUBLIC ../lib/win/)
    target_link_libraries(longbridge engine_cxx.lib ws2_32.lib bcrypt kernel32 ntdll VCRUNTIME userenv)
ELSEIF (APPLE)
    target_link_directories(longbridge PUBLIC ../lib/mac/)
    target_link_libraries(longbridge libengine_cxx.a pthread dl ssl crypto iconv System resolv )
    target_link_options(longbridge PUBLIC -framework Security)
ELSEIF (UNIX)
    target_link_directories(longbridge PUBLIC ../lib/linux/)
    target_link_libraries(longbridge libengine_cxx.a pthread dl ssl crypto  util rt m c)
ENDIF ()
