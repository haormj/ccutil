get_filename_component(HaormjVision_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)
include(CMakeFindDependencyMacro)

set(Torch_DIR /usr/local/libtorch/share/cmake/Torch)

find_package(HaormjHttp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Torch REQUIRED)


if(NOT TARGET HaormjVision::HaormjVision)
    include("${HaormjVision_CMAKE_DIR}/HaormjVisionTargets.cmake")
endif()

