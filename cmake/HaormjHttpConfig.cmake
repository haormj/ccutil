get_filename_component(HaormjHttp_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)

include(CMakeFindDependencyMacro)
find_dependency(CURL REQUIRED)

if(NOT TARGET HaormjHttp::HaormjHttp)
    include("${HaormjHttp_CMAKE_DIR}/HaormjHttpTargets.cmake")
endif()

