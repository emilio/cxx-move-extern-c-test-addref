#include "first.h"

static int TEST = 0;

int main() {
  std::cout << "Passing ptr: " << (void*)&TEST << '\n';
  auto addreffed = already_AddRefed<int>(&TEST);
  auto other = UseAddRefed(std::move(addreffed));
  std::cout << "Received: " << other.take() << '\n';
}
