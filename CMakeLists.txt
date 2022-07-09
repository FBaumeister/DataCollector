cmake_minimum_required(VERSION 3.16)

#######################################################################################################################
# Cpp Standard
#######################################################################################################################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#######################################################################################################################

#######################################################################################################################
# Project config
#######################################################################################################################
project(DataCollectorService  VERSION 1.0.0
                              LANGUAGES CXX
                              HOMEPAGE_URL "https://github.com/FBaumeister/DataCollector")
set(PROJECT_NAMESPACE DCS)

option(BUILD_UNITTESTS  "Build Unit Tests." ON)

#######################################################################################################################


# Find some project-wide dependencies

#######################################################################################################################
# Threads package
#######################################################################################################################
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
#######################################################################################################################



#######################################################################################################################
# Googletest
# Download Googletest as described here:
# https://github.com/google/googletest/blob/master/googletest/README.md#incorporating-into-an-existing-cmake-project
#######################################################################################################################
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# No GMock needed for now
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
enable_testing()
#######################################################################################################################


# Proceed to submodules
add_subdirectory(libs)
