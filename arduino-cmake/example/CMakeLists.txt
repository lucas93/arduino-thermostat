set(ARDUINO_DEFAULT_BOARD uno) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyUSB0) # Default Port, when not specified

include(../../utilities.cmake)

#---- This part is just for auto-picking all sources and header files --------------------
#---- in project directory. Feel free to choose files in a different way -----------------

set( SOURCES_MAIN_DIRECTORY  "${CMAKE_CURRENT_LIST_DIR}/../../application")

#GetListOfSubDirectories( SOURCES_SUBDIRECTORIES     ${SOURCES_MAIN_DIRECTORY})

GetListOfAllFilesInSubDirectories(  APP_SOURCES  ${SOURCES_MAIN_DIRECTORY}      "*.cpp")
GetListOfAllFilesInSubDirectories(  APP_HEADERS  ${SOURCES_MAIN_DIRECTORY}      "*.h")
GetListOfSubDirectories( APP_HEADERS_DIRECTORIES              ${SOURCES_MAIN_DIRECTORY})


#print_foreach(APP_SOURCES)
#print_foreach(APP_HEADERS)

#-----------------------------------------------------------------------------------------
#-----------------------------------------------------------------------------------------

generate_arduino_firmware(blink
    SRCS blink.cpp ${APP_SOURCES}
#    HDRS           ${APP_HEADERS}  # I don't know why it doesn't work, using INCLUDE_DIRECTORIES instead
    ARDLIBS SPI Wire
    BOARD uno)
INCLUDE_DIRECTORIES(${APP_HEADERS_DIRECTORIES})

