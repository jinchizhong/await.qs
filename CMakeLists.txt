cmake_minimum_required(VERSION 2.8.11)

project(await)

set(QTSERVER_CPP1x on)
include(cmake/qsm.cmake)

qs_project(
	await
	# add your source and headers files below
	include/await.h
	src/await.cpp

	main.cpp
	)

target_link_libraries(await Qt5::Core Qt5::Network Qt5::Server)
