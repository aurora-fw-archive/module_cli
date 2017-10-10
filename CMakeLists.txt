# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
# A Powerful General Purpose Framework
# More information in: https://aurora-fw.github.io/
#
# Copyright (C) 2017 Aurora Framework, All rights reserved.
#
# This file is part of the Aurora Framework. This framework is free
# software; you can redistribute it and/or modify it under the terms of
# the GNU Lesser General Public License version 3 as published by the
# Free Software Foundation and appearing in the file LICENSE included in
# the packaging of this file. Please review the following information to
# ensure the GNU Lesser General Public License version 3 requirements
# will be met: https://www.gnu.org/licenses/lgpl-3.0.html.

cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project (aurorafw-cli)

message(STATUS "Starting framework build system...")
message("┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─")
message("├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐")
message("┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴")
message("A Powerful General Purpose Framework")
message("More information in: https://aurora-fw.github.io/\n")


#General Flags
if (NOT CONFIGURED_ONCE)
if(CMAKE_GENERATOR MATCHES "Ninja")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fdiagnostics-color")
endif()
#Add flag for AFW_PREFIX
add_definitions(-DAURORA_IS_COMPILING)
#C++ 17 Standard Revision
set_property(GLOBAL PROPERTY CXX_STANDARD 17)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	#Add custom flags to the CXX compiler
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -g3 -Wall -Wextra -Wformat -pedantic -Wdouble-promotion -std=c++17")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -g0 -Werror -std=c++17")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	#Add custom flags to the CXX compiler
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -g3 -Wall -Wextra -Wformat -pedantic -Wdouble-promotion -std=c++1z")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -g0 -Werror -std=c++1z")
endif()
#Aurora specific flags
set(AURORAFW_ROOT_DIR ${CMAKE_SOURCE_DIR})

#Define output directory
if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(LIBRARY_OUTPUT_PATH ${AURORAFW_ROOT_DIR}/bin/dbg)
	set(EXECUTABLE_OUTPUT_PATH ${AURORAFW_ROOT_DIR}/bin/dbg)
else()
	set(LIBRARY_OUTPUT_PATH ${AURORAFW_ROOT_DIR}/bin)
	set(EXECUTABLE_OUTPUT_PATH ${AURORAFW_ROOT_DIR}/bin)
endif()
endif()

set(AURORAFW_MODULE_CLI_DIR ${AURORAFW_ROOT_DIR})
include(module.cmake)