load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_cc",
    sha256 = "3d9e271e2876ba42e114c9b9bc51454e379cbf0ec9ef9d40e2ae4cec61a31b40",
    strip_prefix = "rules_cc-0.0.6",
    urls = ["https://github.com/bazelbuild/rules_cc/releases/download/0.0.6/rules_cc-0.0.6.tar.gz"],
)

http_archive(
    name = "poco",
    build_file = "@//:third_party/poco.BUILD",
    sha256 = "71ef96c35fced367d6da74da294510ad2c912563f12cd716ab02b6ed10a733ef",
    strip_prefix = "poco-poco-1.12.4-release",
    urls = ["https://github.com/pocoproject/poco/archive/refs/tags/poco-1.12.4-release.tar.gz"],
)
