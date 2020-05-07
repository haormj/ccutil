cmake_minimum_required(VERSION 3.11)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()


enable_testing()

project(HaormjVision VERSION 0.1.0 LANGUAGES CXX)

set(Torch_DIR /usr/local/libtorch/share/cmake/Torch)

find_package(HaormjHttp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Torch REQUIRED)

add_library(haormj_vision)
target_compile_features(haormj_vision PRIVATE cxx_std_11)
aux_source_directory(src HaormjVision_SOURCE_DIR)
target_sources(haormj_vision PRIVATE ${HaormjVision_SOURCE_DIR})
target_include_directories(haormj_vision
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${TORCH_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS})
target_link_libraries(haormj_vision
    PRIVATE
        Haormj::haormj_http
        ${TORCH_LIBRARIES}
        ${OpenCV_LIBS})

include(GNUInstallDirs)
install(TARGETS haormj_vision torch_library
        EXPORT HaormjVisionTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

## Then we install the auto-generated target file, in which have many
## exported names and paths of our target.
install(EXPORT HaormjVisionTargets
        FILE HaormjVisionTargets.cmake
        NAMESPACE Haormj::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HaormjVision)

## And we should install the header files.
install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_CURRENT_LIST_DIR}/cmake/HaormjVisionConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HaormjVision)


