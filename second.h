#include <iostream>

// renaming to avoid using the same symbol
template<typename T>
class already_AddRefed2
{
private:
  T* mRawPtr;

public:
 already_AddRefed2() : mRawPtr(nullptr) {}

  explicit already_AddRefed2(T* aRawPtr) : mRawPtr(aRawPtr) {
      std::cout << "second constructor\n";
  }

  // Disallow copy constructor and copy assignment operator: move semantics used instead.
  already_AddRefed2(const already_AddRefed2<T>& aOther) = delete;
  already_AddRefed2<T>& operator=(const already_AddRefed2<T>& aOther) = delete;

  already_AddRefed2(already_AddRefed2<T>&& aOther) : mRawPtr(aOther.take()) {
    std::cout << "second move constructor\n";
  }

  already_AddRefed2<T>& operator=(already_AddRefed2<T>&& aOther)
  {
    std::cout << "second move constructor: " << (void*)mRawPtr << '\n';
    mRawPtr = aOther.take();
    return *this;
  }

  ~already_AddRefed2() {
    std::cout << "second destructor: " << (void*)mRawPtr << '\n';
  }

  T* take()
  {
    std::cout << "second take\n";
    T* rawPtr = mRawPtr;
    mRawPtr = nullptr;
    return rawPtr;
  }
};

template<typename T>
using already_AddRefed = already_AddRefed2<T>;
