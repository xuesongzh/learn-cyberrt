cc_binary(
    name = "demo00_helloworld",
    srcs = ["demo00_helloworld.cc"],
    deps = ["//cyber"],
)

cc_binary(
    name = "demo01_talker",
    srcs = ["demo01_talker.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:student_cc"
    ],
)

cc_binary(
    name = "demo02_listener",
    srcs = ["demo02_listener.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:student_cc"
    ],
)

cc_binary(
    name = "demo03_server",
    srcs = ["demo03_server.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:addints_proto_cc"
    ],
)

cc_binary(
    name = "demo04_client",
    srcs = ["demo04_client.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:addints_proto_cc"
    ],
)

cc_binary(
    name = "demo05_param_server",
    srcs = ["demo05_param_server.cc"],
    deps = [
        "//cyber",
        "//cyber/parameter"
    ],
)

cc_binary(
    name = "demo06_param_client",
    srcs = ["demo06_param_client.cc"],
    deps = [
        "//cyber",
        "//cyber/parameter"
    ],
)
