#define _DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR
#include <future>
#include <cstdio>

int main()
{
    auto handle = std::async(std::launch::async, []() { return 1; });
    int r = handle.get();
    printf("Result: %d\n", r);
}
