cmake_minimum_required(VERSION 3.11)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()


enable_testing()

project(HaormjHttp VERSION 0.1.0 LANGUAGES CXX)

find_package(CURL REQUIRED)
find_package(GTest CONFIG)

add_library(haormj_http)
target_compile_features(haormj_http PRIVATE cxx_std_11)
aux_source_directory(src HaormjHttp_SOURCE_DIR)
target_sources(haormj_http PRIVATE ${HaormjHttp_SOURCE_DIR})
target_include_directories(haormj_http
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CURL_INCLUDE_DIRS})

target_link_libraries(haormj_http
    PRIVATE
        ${CURL_LIBRARIES})

## test
add_executable(haormj_http_test test/http_test.cpp)
target_link_libraries(haormj_http_test
    PRIVATE
        GTest::gtest_main
        haormj_http)
add_test(HaormjHttpTest haormj_http_test)

include(GNUInstallDirs)
install(TARGETS haormj_http
        EXPORT HaormjHttpTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

## Then we install the auto-generated target file, in which have many
## exported names and paths of our target.
install(EXPORT HaormjHttpTargets
        FILE HaormjHttpTargets.cmake
        NAMESPACE Haormj::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HaormjHttp)

## And we should install the header files.
install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_CURRENT_LIST_DIR}/cmake/HaormjHttpConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HaormjHttp)
