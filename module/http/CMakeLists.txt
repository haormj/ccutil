
find_package(CURL REQUIRED)

add_library(HaormjHttp)
target_compile_features(HaormjHttp PRIVATE cxx_std_11)
aux_source_directory(src HaormjHttp_SOURCE_DIR)
target_sources(HaormjHttp PRIVATE ${HaormjHttp_SOURCE_DIR})
target_include_directories(HaormjHttp
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CURL_INCLUDE_DIRS})
target_link_libraries(HaormjHttp PRIVATE ${CURL_LIBRARIES})

include(GNUInstallDirs)
install(TARGETS HaormjHttp
        EXPORT HaormjHttpTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

## Then we install the auto-generated target file, in which have many
## exported names and paths of our target.
install(EXPORT HaormjHttpTargets
        FILE HaormjHttpTargets.cmake
        NAMESPACE HaormjHttp::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HaormjHttp)

## And we should install the header files.
install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


