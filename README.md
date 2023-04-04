# bazel_poco_example

Demonstrate how to define a custom build file for Poco

Inspired by [Slack
conversation](https://bazelbuild.slack.com/archives/CA31HN1T3/p1680566937546549?thread_ts=1680541252.699009&cid=CA31HN1T3).

NOTE: This is not a complete, working example. I only worked to get the `@poco//:Foundation` target
to build.

```sh
bazel build @poco//:Foundation
```

## Notes

A few interesting things to note:

- Under Foundation , they use a convention of `_XXX.cpp`  and `_XXX.h` to distinguish
  platform-specific headers. They should not be processed `srcs` or `hdrs`. Instead, they should be 
  made available under `textual_hdrs`.
- The `defines` that I set were necessary to make it build on my laptop, MacOS. You will need to
  provide different defines based upon your platform. If you are going to make this work for
  multiple platforms, I recommend that you check out [Bazel’s configurable
  attributes](https://bazel.build/docs/configurable-attributes).
- I used `defines`, but you probably want to use [local_defines](https://bazel.build/reference/be/c-cpp#cc_library.local_defines).
- You will need to configure a separate cc_library for `Foundation`, `JSON`, `Net`, `Util` and
  `XML`.
- I think that you will need to use the
  [include_prefix](https://bazel.build/reference/be/c-cpp#cc_library.include_prefix) attribute when
  configuring the `cc_library` for `Util`. It looks like they prepend `Poco/` to their includes. 
- If you are going to compile for multiple platforms, you will need to leverage Bazel’s
  [platforms](https://bazel.build/extending/platforms) and [configurable
  attributes](https://bazel.build/docs/configurable-attributes) capabilities.

