package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hello_great",
    srcs = ["hello_great.cc"],
    hdrs = ["hello_great.h"],
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = [":hello_great"],
)