package(default_visibility = ["//visibility:public"])

cc_library(
    name = "common_cpt_lib",
    srcs = ["common_cpt.cc"],
    hdrs = ["common_cpt.h"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:student_cc"
    ],
)

cc_binary(
    name = "lib_common_cpt.so",
    linkshared = True,
    linkstatic = False,
    deps = [":common_cpt_lib"],
)

filegroup(
    name = "conf",
    srcs = [
        ":cpt.dag",
        ":cpt.launch",
    ],
)