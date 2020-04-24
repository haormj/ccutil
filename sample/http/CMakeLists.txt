cmake_minimum_required(VERSION 3.11)


find_package(HaormjHttp REQUIRED)

add_executable(http_get http_get.cpp)
target_compile_features(http_get PRIVATE cxx_std_11)
target_link_libraries(http_get PRIVATE HaormjHttp::HaormjHttp)
 
