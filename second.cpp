#include "second.h"


static int TEST3 = 0;

extern "C" already_AddRefed<int> UseAddRefed(already_AddRefed<int> t) {
    std::cout << "UseAddRefed\n";
    auto tPtr = t.take();
    std::cout << "UseAddRefed after take: " << (void*)tPtr << '\n';
    return already_AddRefed<int>(&TEST3);
}

extern "C" void UseAddRefedPtr(already_AddRefed<int>* t) {
    std::cout << "UseAddRefedPtr: " << (void*) t << '\n';
}
