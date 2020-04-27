
set(Torch_DIR /usr/local/libtorch/share/cmake/Torch)

find_package(HaormjHttp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Torch REQUIRED)

add_library(HaormjVision)
target_compile_features(HaormjVision PRIVATE cxx_std_11)
aux_source_directory(src HaormjVision_SOURCE_DIR)
target_sources(HaormjVision PRIVATE ${HaormjVision_SOURCE_DIR})
target_include_directories(HaormjVision
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${TORCH_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS})
target_link_libraries(HaormjVision
    PRIVATE
        HaormjHttp::HaormjHttp
        ${TORCH_LIBRARIES}
        ${OpenCV_LIBS})

include(GNUInstallDirs)
install(TARGETS HaormjVision torch_library
        EXPORT HaormjVisionTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

## Then we install the auto-generated target file, in which have many
## exported names and paths of our target.
install(EXPORT HaormjVisionTargets
        FILE HaormjVisionTargets.cmake
        NAMESPACE HaormjVision::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HaormjVision)

## And we should install the header files.
install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


