cmake_minimum_required(VERSION 2.8.11)

if ("$ENV{MGEN_INSTALL_PATH}" STREQUAL "")
	message(FATAL_ERROR "Unable to find MGen install path, please check that MGEN_INSTALL_PATH environmental variable is set")
else()
	message("MGen install path found: $ENV{MGEN_INSTALL_PATH}")
endif()

project(pinger)

IF(CMAKE_COMPILER_IS_GNUCC)
	ADD_DEFINITIONS(-std=c++11)
ENDIF(CMAKE_COMPILER_IS_GNUCC)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5WebSockets)

include_directories(    $ENV{MGEN_INSTALL_PATH}/include
                        ${CMAKE_CURRENT_SOURCE_DIR}
                        ../../main/cpp
                        ../../main/cpp_generated   )

add_executable( ${PROJECT_NAME} 
                test_main.cpp    
                File2Vector.h
                ../../main/cpp/mnet/MNetClient.h
                ../../main/cpp/mnet/MNetSerializer.h 
                ../../main/cpp/mnet/ReconnectingWebSocket.h
                ../../main/cpp/mnet/Route.h 
                ../../main/cpp/mnet/WebSocket.h )

target_link_libraries(${PROJECT_NAME} Qt5::WebSockets)
