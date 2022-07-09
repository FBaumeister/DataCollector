
set(TARGET_NAME FileSystemMonitor)

set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src/${TARGET_NAME})
set(INCLUDE_DIR_ROOT ${CMAKE_CURRENT_LIST_DIR}/include)
set(INCLUDE_DIR ${INCLUDE_DIR_ROOT}/${TARGET_NAME})


# Create the target (alias target for referencing in other parts of the project)
add_library(${TARGET_NAME} STATIC "")
add_library(${PROJECT_NAMESPACE}::${TARGET_NAME} ALIAS ${TARGET_NAME})


# Include Files
target_sources(${TARGET_NAME}
    PRIVATE
        ${INCLUDE_DIR}/Prerequisites.h
        ${INCLUDE_DIR}/FileSystemMonitor_fwd.h
        ${INCLUDE_DIR}/FolderMonitor.h
        #...
)

# Source Files
target_sources(${TARGET_NAME}
    PRIVATE
        ${SRC_DIR}/FolderMonitor.cpp
        #...
)

#######################################################################################################################
# Target's own include directories
# Separate Header Placement
#######################################################################################################################
target_include_directories(${TARGET_NAME} PUBLIC
                           $<BUILD_INTERFACE:${INCLUDE_DIR_ROOT}>
                           $<INSTALL_INTERFACE:include>)
#######################################################################################################################


#######################################################################################################################
# Targets Dependencies
#######################################################################################################################
# ...
#######################################################################################################################
