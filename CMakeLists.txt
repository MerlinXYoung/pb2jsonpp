cmake_minimum_required(VERSION 3.15)

project(pb2json CXX)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIR})
add_library(pb2json_static STATIC  byReflection/pb2json.cpp byReflection/pb2json.h json.hpp pb2json.h pb2json.cpp )
add_library(pb2json SHARED byReflection/pb2json.cpp byReflection/pb2json.h json.hpp pb2json.h pb2json.cpp )

# 指定静态库的输出名称
set_target_properties(pb2json_static PROPERTIES OUTPUT_NAME "pb2json")
# 使动态库和静态库同时存在
set_target_properties(pb2json PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(pb2json_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 指定动态库版本
# VERSION 动态库版本
# SOVERSION API版本
# set_target_properties(pb2json PROPERTIES VERSION 1.0 SOVERSION 1)
