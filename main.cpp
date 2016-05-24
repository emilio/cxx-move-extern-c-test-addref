#include "first.h"

static int TEST = 0;

int main() {
  auto addreffed = already_AddRefed<int>(&TEST);
  UseAddRefed(std::move(addreffed));
}
