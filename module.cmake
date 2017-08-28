message(STATUS "Loading cli module...")

if (NOT CONFIGURED_ONCE)
	set(MODULE_CLI_SOURCE_DIR ${MODULE_CLI_DIR}/src)
endif()

include_directories(${MODULE_CLI_DIR}/include)

add_library (aurora-cli SHARED ${MODULE_CLI_SOURCE_DIR}/Color.cpp
                               ${MODULE_CLI_SOURCE_DIR}/Input.cpp
						   	   ${MODULE_CLI_SOURCE_DIR}/Output.cpp)

set_target_properties(aurora-cli PROPERTIES OUTPUT_NAME aurora-cli)
