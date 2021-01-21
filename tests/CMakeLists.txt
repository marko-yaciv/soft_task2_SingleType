set(BINARY ${CMAKE_PROJECT_NAME}_test)

set(SOURCES main.cpp template_tests/templatesTest.cpp template_tests/customTypeForTest.h)

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

add_test(NAME ${BINARY} COMMAND ${BINARY})