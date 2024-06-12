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


Insights
========


This repository was posted to SO: https://stackoverflow.com/questions/78612314/github-runners-issue-with-visual-studio-2022-segmentation-fault-with-the-simple?noredirect=1#comment138594337_78612314

A workaround (non satisfactory) is provided at https://stackoverflow.com/questions/78598141/first-stdmutexlock-crashes-in-application-built-with-latest-visual-studio.
Add this:

```cpp
#define _DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR
```

before include <future> or <mutex> in the code.

Related github issues:

https://github.com/actions/runner-images/issues/10004#issuecomment-2156109231


https://github.com/actions/runner/issues/3331

Solution
========

This issue was fixed by GitHub on 2024-06-12
