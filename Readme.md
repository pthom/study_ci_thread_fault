Repository to study a CI issue. See https://github.com/Dobiasd/FunctionalPlus/issues/304
======================================================================

There is a serious issue in GitHub's runner CI.

This code:

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

when compiled and built in release mode for Visual Studio 2019, will crash when run in a GitHub runner, with a segmentation fault.

