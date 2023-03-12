package(default_visibility = ["//visibility:public"])
#load("//tools/install:install.bzl","install")
cc_binary(
    name = "front_laser",
    srcs = ["front_laser.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:lasers_proto_cc"
    ],
)
cc_binary(
    name = "back_laser",
    srcs = ["back_laser.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:lasers_proto_cc"
    ],
)

cc_library(
    name = "lasers_cpt_lib",
    srcs = ["lasers_cpt.cc"],
    hdrs = ["lasers_cpt.h"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:lasers_proto_cc"
    ],
)

cc_binary(
    name = "liblasers_cpt.so",
    linkshared = True,
    linkstatic = False,
    deps = [":lasers_cpt_lib"],
)

#dag和launch放到同一个文件组
filegroup(
    name = "conf",
    srcs = [
        ":cpt2.dag",
        ":cpt2.launch",
    ],
)

#install(
#    name = "install",
#    data = [":conf"],
#    runtime_dest = "cyber/demo_cc/component_common02",
#    target = [
#        ":front_laser",
#        ":back_laser",
#        ":liblasers_cpt.so"
#    ]
#)