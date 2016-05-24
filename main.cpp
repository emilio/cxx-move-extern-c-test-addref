#include "first.h"

static int TEST = 0;

int main() {
  auto addreffed = already_AddRefed<int>(&TEST);
  auto other = UseAddRefed(std::move(addreffed));
}
