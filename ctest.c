#include <stdio.h>

static int TEST = 0;

struct holder {
    int* ptr;
};

// This should be equivalent in layout to the C++ class.
struct holder UseAddRefed(struct holder t) {
    printf("c: Received %p, %d\n", t.ptr, *t.ptr);

    struct holder ret = { &TEST };
    return ret;
}

void UseAddRefedPtr(int** t) {
    printf("c: Received %p\n", t);
}
