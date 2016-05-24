#include <iostream>

template<typename T>
class already_AddRefed
{
private:
  T* mRawPtr;

public:
 already_AddRefed() : mRawPtr(nullptr) {}

  explicit already_AddRefed(T* aRawPtr) : mRawPtr(aRawPtr) {
      std::cout << "first constructor\n";
  }

  // Disallow copy constructor and copy assignment operator: move semantics used instead.
  already_AddRefed(const already_AddRefed<T>& aOther) = delete;
  already_AddRefed<T>& operator=(const already_AddRefed<T>& aOther) = delete;

  already_AddRefed(already_AddRefed<T>&& aOther) : mRawPtr(aOther.take()) {
      std::cout << "first move constructor\n";
  }

  already_AddRefed<T>& operator=(already_AddRefed<T>&& aOther)
  {
    std::cout << "first move operator= " << (void*)mRawPtr << '\n';
    mRawPtr = aOther.take();
    return *this;
  }

  ~already_AddRefed() {
    std::cout << "first destructor: " << (void*)mRawPtr << '\n';
  }

  T* take()
  {
    std::cout << "first take\n";
    T* rawPtr = mRawPtr;
    mRawPtr = nullptr;
    return rawPtr;
  }
};

extern "C" void UseAddRefed(already_AddRefed<int> t);
