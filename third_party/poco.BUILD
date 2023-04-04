load("@rules_cc//cc:defs.bzl", "cc_library")

_COMMON_COPTS = [
    "-std=c++20",
]

_SOURCE_DIRS = [
    "Foundation",
    "JSON",
    "Net",
    "Util",
    "XML",
]

_SPECIAL_SUFFIXES = [
    "Android",
    "C99",
    "DEC",
    "DUMMY",
    "HPUX",
    "POSIX",
    "QNX",
    "STD",
    "SUN",
    "UNIX",
    "VX",
    "WIN32",
    "WIN32U",
    "WINCE",
]

cc_library(
    name = "Foundation",
    srcs = glob(
        [
            "Foundation/src/*.cc",
            "Foundation/src/*.cpp",
            "Foundation/src/*.h",
        ],
        exclude = [
            "Foundation/src/**/*_{}.cpp".format(suf)
            for suf in _SPECIAL_SUFFIXES
        ] + [
            "Foundation/src/EventLogChannel.cpp",
            "Foundation/src/WindowsConsoleChannel.cpp",
        ],
    ),
    hdrs = glob(
        ["Foundation/include/**/*.h"],
        exclude = [
            "Foundation/include/**/*_{}.h".format(suf)
            for suf in _SPECIAL_SUFFIXES
        ],
    ),
    copts = _COMMON_COPTS + [
        "-Iexternal/poco/Foundation/src",
    ],
    defines = [
        "POCO_NO_FPENVIRONMENT",
        "POCO_NO_WINDOWS_H",
    ],
    includes = ["Foundation/include"],
    textual_hdrs = glob([
        "Foundation/**/*_{}.cpp".format(suf)
        for suf in _SPECIAL_SUFFIXES
    ] + [
        "Foundation/**/*_{}.h".format(suf)
        for suf in _SPECIAL_SUFFIXES
    ] + [
        "Foundation/**/*.cc",
    ]),
    visibility = ["//visibility:public"],
)

# cc_library(
#     name = "poco",
#     srcs = glob(
#         [
#             "{}/src/*.cpp".format(src_dir)
#             for src_dir in _SOURCE_DIRS
#         ],
#         exclude = [
#             "*_{}.cpp".format(suf)
#             for suf in _SPECIAL_SUFFIXES
#         ],
#     ),
#     hdrs = glob(
#         [
#             "{}/include/**/*.h".format(src_dir)
#             for src_dir in _SOURCE_DIRS
#         ],
#         exclude = [
#             "*_{}.h".format(suf)
#             for suf in _SPECIAL_SUFFIXES
#         ],
#     ),
#     copts = [
#         "-std=c++20",
#         # "-E",
#         # "-C",
#     ] + [
#         "-I{}/src".format(src_dir)
#         for src_dir in _SOURCE_DIRS
#     ],
#     includes = [
#         "-I{}/include".format(src_dir)
#         for src_dir in _SOURCE_DIRS
#     ],
#     local_defines = [
#         "POCO_NO_FPENVIRONMENT",
#         "POCO_NO_WINDOWS_H",
#         # "POCO_NO_GCC_API_ATTRIBUTE",
#     ],
#     textual_hdrs = glob([
#         "**/*_{}.cpp".format(suf)
#         for suf in _SPECIAL_SUFFIXES
#     ] + [
#         "**/*_{}.h".format(suf)
#         for suf in _SPECIAL_SUFFIXES
#     ]),
#     visibility = ["//visibility:public"],
# )
