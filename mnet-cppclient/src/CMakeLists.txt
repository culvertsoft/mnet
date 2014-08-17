cmake_minimum_required(VERSION 2.8.11)

project(pinger)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5WebSockets)

add_executable( ${PROJECT_NAME} 
                main.cpp    
                WebSocket.h
                ReconnectingWebSocket.h )
                
target_link_libraries(${PROJECT_NAME} Qt5::WebSockets)
