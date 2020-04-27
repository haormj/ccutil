cmake_minimum_required(VERSION 3.11)


find_package(HaormjVision REQUIRED)

add_executable(vgg vgg.cpp)
target_compile_features(vgg PRIVATE cxx_std_11)
target_link_libraries(vgg PRIVATE HaormjVision::HaormjVision)
