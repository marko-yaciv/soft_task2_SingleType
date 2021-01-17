set(SOURCES
            SingleType.h
            SingleType.cpp
        Helper.cpp Helper.h)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SOURCES})
