//Copyright by Spertis

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <memory>
#include <utility>

template <typename T>
class Stack
{
 public:
  Stack(const Stack&) = delete;
  Stack& operator = (const Stack&) = delete;
  Stack(): pointer(nullptr) {}
  void push(T&& value) {
    auto mov = std::unique_ptr<StackObj>(new StackObj(std::move(pointer),
                                                      std::move(value)));
    pointer = std::move(mov);
  }
  void push(const T& value) {
    auto mov = std::unique_ptr<StackObj>(new StackObj(std::move(pointer),
                                                      (value)));
    pointer = std::move(mov);
  }
  T pop() {
    if (pointer != nullptr) {
      auto del = pointer->value;
      pointer = std::move(pointer->last);
      return del;
    }
    throw std::runtime_error("Null error");
  }
  const T& head() const {
    return pointer->value;
  }
 private:
  struct StackObj{
    typedef  std::unique_ptr < StackObj> StackObjPtr;
    StackObjPtr last;
    T value;
    explicit StackObj(StackObjPtr pointer = nullptr, T valu = T()) {
      value = valu;
      last = std::move(pointer);
    }
  };
  std::unique_ptr<StackObj> pointer;
};

#endif // INCLUDE_STACK_HPP_

