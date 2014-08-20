cmake_minimum_required(VERSION 2.8.11)

if ("$ENV{MGEN_INSTALL_PATH}" STREQUAL "")
	message(FATAL_ERROR "Unable to find MGen install path, please check that MGEN_INSTALL_PATH environmental variable is set")
else()
	message("MGen install path found: $ENV{MGEN_INSTALL_PATH}")
endif()

project(pinger)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5WebSockets)

include_directories(    $ENV{MGEN_INSTALL_PATH}/include
                        main/cpp_generated    )

add_executable( ${PROJECT_NAME} 
                main/cpp/main.cpp    
                main/cpp/WebSocket.h
                main/cpp/ReconnectingWebSocket.h
				main/cpp/MNetClient.h
				main/cpp/MNetSerializer.h 
				main/cpp/Route.h )

target_link_libraries(${PROJECT_NAME} Qt5::WebSockets)
