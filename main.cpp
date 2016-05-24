#include "first.h"

static int TEST = 1000;

int main() {
  auto addreffed = already_AddRefed<int>(&TEST);

  std::cout << "Sending: " << (void*)&addreffed << " to UseAddRefedPtr\n";
  UseAddRefedPtr(&addreffed);

  std::cout << "Passing ptr: " << (void*)&TEST << '\n';
  auto other = UseAddRefed(std::move(addreffed));
  std::cout << "Received: " << other.take() << '\n';
}
