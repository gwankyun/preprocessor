# cmake最低版本
cmake_minimum_required(VERSION 3.21)

# 項目名
project(preprocessor)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 包括模板
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
include(CMakePrintHelpers)
include(common)
include(GNUInstallDirs)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP;/Zc:__cplusplus;>")
# add_compile_definitions("SCOPE_GUARD_HAS_CXX_11=0")

# set(preprocessor_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
# find_package(preprocessor REQUIRED)

set(target preprocessor)

add_library(${target} INTERFACE)

# install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# target_include_directories(${target}
#   INTERFACE
#     "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
#     "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
# )

# find_package(Boost REQUIRED)

# target_link_libraries(${target} INTERFACE Boost::headers)

# target_install(${target} "0.0.1")

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/preprocessor.hpp" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

target_include_directories(${target}
  INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

if(NOT Boost_ROOT)
  set(Boost_ROOT "C:/Program Files/boost_1_77_0")
endif()

find_package(Boost REQUIRED)

target_link_libraries(${target} INTERFACE Boost::headers)

target_install(${target} "0.0.1")

# 生成執行文件
set(main main)
add_executable(${main})

target_sources(${main}
  PRIVATE
    src/main.cpp
    include/preprocessor.hpp
    cmake/Findpreprocessor.cmake
)

# 引用庫
target_link_libraries(${main}
  PUBLIC
    preprocessor
)

target_compile_features(${main} PRIVATE cxx_std_17)
