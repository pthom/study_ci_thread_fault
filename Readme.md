Study issue / GitHub Runners / Visual Studio 2022 / std::async
======================================================================

This repository is here to study an issue which was discovered at https://github.com/Dobiasd/FunctionalPlus/issues/304

There is a serious issue in GitHub's runner CI. This code:

```cpp
#include <future>
#include <cstdio>

int main()
{
    auto handle = std::async(std::launch::async, []() { return 1; });
    int r = handle.get();
    printf("Result: %d\n", r);
}
```

when compiled and built in release mode for Visual Studio 2022, will **crash** when run in a GitHub runner (windows 2022), with a segmentation fault!

See for example: https://github.com/pthom/study_ci_thread_fault/actions/runs/9481503691/job/26124415183

