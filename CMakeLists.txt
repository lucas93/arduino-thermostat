cmake_minimum_required(VERSION 2.8.2)

project(Arduino_Unit_Test_Example)

include(CTest)
include(utilities.cmake)
add_compile_options(-std=c++14)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
set(GOOGLE_TEST_INCLUDE_DIRECTORY "${googletest_SOURCE_DIR}/googletest/include")
set(GOOGLE_MOCK_INCLUDE_DIRECTORY "${googletest_SOURCE_DIR}/googlemock/include")


#---- This part is just for auto-picking all sources and header files --------------------
#---- in project directory. Feel free to choose files in a different way -----------------
set( UNIT_TESTS_DIRECTORY               "${CMAKE_CURRENT_SOURCE_DIR}/ut/tests")
set( MOCKS_DIRECTORY                    "${CMAKE_CURRENT_SOURCE_DIR}/ut/mocks")
set( APPLICATION_SOURCES_DIRECTORY      "${CMAKE_CURRENT_SOURCE_DIR}/application")

GetListOfSubDirectories( UNIT_TESTS_SUBDIRECTORIES              ${UNIT_TESTS_DIRECTORY})
GetListOfSubDirectories( MOCKS_SUBDIRECTORIES                   ${MOCKS_DIRECTORY})
GetListOfSubDirectories( APPLICATION_SOURCES_SUBDIRECTORIES     ${APPLICATION_SOURCES_DIRECTORY})

GetListOfAllFilesInSubDirectories(  UNIT_TESTS_SOURCES  ${UNIT_TESTS_DIRECTORY}             "*.cpp")
GetListOfAllFilesInSubDirectories(  UNIT_TESTS_HEADERS  ${UNIT_TESTS_DIRECTORY}             "*.h")
GetListOfAllFilesInSubDirectories(  MOCKS_SOURCES       ${MOCKS_DIRECTORY}                  "*.cpp")
GetListOfAllFilesInSubDirectories(  MOCKS_HEADERS       ${MOCKS_DIRECTORY}                  "*.h")
GetListOfAllFilesInSubDirectories(  APPLICATION_SOURCES ${APPLICATION_SOURCES_DIRECTORY}    "*.cpp")
GetListOfAllFilesInSubDirectories(  APPLICATION_HEADERS ${APPLICATION_SOURCES_DIRECTORY}    "*.h")
#-----------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------

add_executable(unit_tests
    ${UNIT_TESTS_SOURCES}
    ${APPLICATION_SOURCES}
    ${MOCKS_SOURCES}
    ${MOCKS_HEADERS})   # QtCreator has problems with displaying header files in project tree if they are not a part of executable

include_directories(
    ${APPLICATION_SOURCES_SUBDIRECTORIES}
    ${MOCKS_SUBDIRECTORIES}
    ${UNIT_TESTS_SUBDIRECTORIES}
    ${GOOGLE_TEST_INCLUDE_DIRECTORY}
    ${GOOGLE_MOCK_INCLUDE_DIRECTORY})

target_link_libraries(unit_tests gtest gmock_main)
add_test(NAME unit_tests COMMAND unit_tests)
