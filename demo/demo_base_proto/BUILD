load("//tools:python_rules.bzl", "py_proto_library")
package(default_visibility = ["//visibility:public"])
proto_library(
    name = "student_proto",
    srcs = ["student.proto"]
)

cc_proto_library(
    name = "student_cc",
    deps = [":student_proto"]
)

py_proto_library(
    name = "student_py",
    deps = [":student_proto"]
)

cc_binary(
    name = "test_student",
    srcs = ["test_student.cc"],
    deps = [":student_cc"],
)

proto_library(
    name = "addints_proto",
    srcs = ["addints.proto"]
)
cc_proto_library(
    name = "addints_proto_cc",
    deps = [":addints_proto"]
)
py_proto_library(
    name = "addints_proto_py",
    deps = [":addints_proto"]
)

proto_library(
    name = "lasers_proto",
    srcs = ["lasers.proto"]
)
cc_proto_library(
    name = "lasers_proto_cc",
    deps = [
        ":lasers_proto",
    ],
)
py_proto_library(
    name = "lasers_proto_py",
    deps = [
        ":lasers_proto",
    ],
)