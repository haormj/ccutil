get_filename_component(HaormjHttp_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)

include(CMakeFindDependencyMacro)
find_dependency(CURL REQUIRED)
find_dependency(GTest REQUIRED)

if(NOT TARGET Haormj::haormj_http)
    include("${HaormjHttp_CMAKE_DIR}/HaormjHttpTargets.cmake")
endif()

