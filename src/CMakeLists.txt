set(SOURCES
            SingleType.h
            SingleType.cpp
            type.h
            type.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SOURCES})
