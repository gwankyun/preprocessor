# cmake最低版本
cmake_minimum_required(VERSION 3.19)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 包括模板
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
include(CMakePrintHelpers)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 項目名
project(preprocessor)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP;/Zc:__cplusplus;>")
add_compile_definitions("SCOPE_GUARD_HAS_CXX_11=0")

set(preprocessor_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
find_package(preprocessor REQUIRED)

# 生成執行文件
set(preprocessor preprocessor)
add_executable(${preprocessor})

target_sources(${preprocessor}
  PRIVATE
    src/main.cpp
    include/preprocessor.hpp
    cmake/Findpreprocessor.cmake
)

# 引用庫
target_link_libraries(${preprocessor}
  PUBLIC
    preprocessor::preprocessor
)

target_compile_features(${preprocessor} PRIVATE cxx_std_17)
