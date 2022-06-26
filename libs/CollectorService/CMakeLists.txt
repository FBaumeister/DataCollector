
set(TARGET_NAME CollectorService)
set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src/${TARGET_NAME})


add_executable(${TARGET_NAME} "")


# Source Files
target_sources(${TARGET_NAME}
    PRIVATE
        ${SRC_DIR}/main.cpp
        #...
)

#######################################################################################################################
# Target's own include directories
# Merged Header Placement
#######################################################################################################################
target_include_directories(${TARGET_NAME} PUBLIC ${SRC_DIR})
#######################################################################################################################


#######################################################################################################################
# Targets Dependencies
#######################################################################################################################
target_link_libraries(${TARGET_NAME} PRIVATE DCS::Utilities)
target_link_libraries(${TARGET_NAME} PRIVATE DCS::DataCollector)
target_link_libraries(${TARGET_NAME} PRIVATE DCS::FileSystemMonitor)
target_link_libraries(${TARGET_NAME} PRIVATE DCS::DataPackager)
#######################################################################################################################
