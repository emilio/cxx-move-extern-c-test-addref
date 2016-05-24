#include "second.h"

extern "C" void UseAddRefed(already_AddRefed<int> t) {
    std::cout << "UseAddRefed\n";
    auto tPtr = t.take();
    std::cout << "UseAddRefed after take: " << (void*)tPtr << '\n';
}
