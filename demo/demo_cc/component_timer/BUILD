cc_library(
    name = "timer_cpt_lib",
    srcs = ["timer_cpt.cc"],
    hdrs = ["timer_cpt.h"],
    deps = [
        "//cyber",
    ],
)

cc_binary(
    name = "libtimer_cpt.so",
    linkshared = True,
    linkstatic = False,
    deps = [":timer_cpt_lib"],
)

filegroup(
    name = "conf",
    srcs = [
        ":timer.dag",
        ":timer.launch",
    ],
)