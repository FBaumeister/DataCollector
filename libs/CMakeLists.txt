# Add submodules to build

list(APPEND ENABLED_COMPONENT "Utilities")
list(APPEND ENABLED_COMPONENT "FileSystemMonitor")
#list(APPEND ENABLED_COMPONENT "DataPackager")
#list(APPEND ENABLED_COMPONENT "DataCollector")

list(APPEND ENABLED_COMPONENT "CollectorService")


foreach(component ${ENABLED_COMPONENT})
	add_subdirectory(${component})
endforeach()


if(BUILD_UNITTESTS)
	foreach(component ${ENABLED_COMPONENT})
		set(COMPONENT_TEST_PATH ${CMAKE_CURRENT_LIST_DIR}/${component}/tests)
		if(EXISTS ${COMPONENT_TEST_PATH} AND EXISTS ${COMPONENT_TEST_PATH}/CMakeLists.txt)
			add_subdirectory(${COMPONENT_TEST_PATH})
		endif()
	endforeach()
endif()
