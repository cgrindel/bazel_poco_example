load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "my_app",
    srcs = ["read-stats.cc"],
    copts = ["-std=c++20"],
    deps = [
        "@poco",
    ],
)
