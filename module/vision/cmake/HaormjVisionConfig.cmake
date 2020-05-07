get_filename_component(HaormjVision_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)
include(CMakeFindDependencyMacro)

set(Torch_DIR /usr/local/libtorch/share/cmake/Torch)

find_dependency(HaormjHttp REQUIRED)
find_dependency(OpenCV REQUIRED)
find_dependency(Torch REQUIRED)


if(NOT TARGET Haormj::haormj_vision)
    include("${HaormjVision_CMAKE_DIR}/HaormjVisionTargets.cmake")
endif()

