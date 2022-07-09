
set(TARGET_NAME CollectorService)
set(SRC_DIR_ROOT ${CMAKE_CURRENT_LIST_DIR}/src)
set(SRC_DIR ${SRC_DIR_ROOT}/${TARGET_NAME})


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
target_include_directories(${TARGET_NAME} PUBLIC ${SRC_DIR_ROOT})
#######################################################################################################################


#######################################################################################################################
# Targets Dependencies
#######################################################################################################################
target_link_libraries(${TARGET_NAME} PRIVATE DCS::Utilities)
#target_link_libraries(${TARGET_NAME} PRIVATE DCS::DataCollector)
target_link_libraries(${TARGET_NAME} PRIVATE DCS::FileSystemMonitor)
#target_link_libraries(${TARGET_NAME} PRIVATE DCS::DataPackager)
#######################################################################################################################
