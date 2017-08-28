message(STATUS "Loading cli module...")

if (NOT CONFIGURED_ONCE)
	set(MODULE_CLI_SOURCE_DIR ${MODULE_CLI_DIR}/src)
endif()

include_directories(${MODULE_CLI_DIR}/include)

add_library (aurora-cli SHARED ${SOURCE_DIR}/aurora-cli-core/Color.cpp
                               ${SOURCE_DIR}/aurora-cli-core/Input.cpp
                               ${SOURCE_DIR}/aurora-cli-core/Output.cpp)

set_target_properties(aurora-cli PROPERTIES OUTPUT_NAME aurora-cli)
