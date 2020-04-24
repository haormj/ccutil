cmake_minimum_required(VERSION 3.11)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

project(Haormj VERSION 0.1.0 LANGUAGES CXX)

# add module
add_subdirectory(module)

install(FILES ${CMAKE_CURRENT_LIST_DIR}/cmake/HaormjHttpConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HaormjHttp)

