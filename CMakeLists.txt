cmake_minimum_required(VERSION 3.0)
project(TomatoTest)

cmake_policy(VERSION 3.0)

add_subdirectory(TomatoLib)

add_executable(tomatotest
	src/main.cpp
	src/MyGame.cpp
)

include_directories(${TOMATO_INCLUDES})
target_link_libraries(tomatotest
	tomato
	${TOMATO_LIBRARIES}
)

add_definitions(-DLINUX -std=c++11)
