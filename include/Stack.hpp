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
  Stack(): reference(nullptr) {}
  void push(T&& value) {
    auto mov = std::unique_ptr<StackObj>(new StackObj(std::move(reference),
                                                      std::move(value)));
    reference = std::move(mov);
  }
  void push(const T& value) {
    auto mov = std::unique_ptr<StackObj>(new StackObj(std::move(reference),
                                                      (value)));
    reference = std::move(mov);
  }
  T pop() {
    if (reference != nullptr) {
      auto del = reference->value;
      reference = std::move(reference->last);
      return del;
    }
    throw std::runtime_error("Null error");
  }
  const T& head() const {
    return reference->value;
  }
 private:
  struct StackObj{
    typedef  std::unique_ptr < StackObj> StackObjPtr;
    StackObjPtr last;
    T value;
    explicit StackObj(StackObjPtr reference = nullptr, T valu = T()) {
      value = valu;
      last = std::move(reference);
    }
  };
  std::unique_ptr<StackObj> reference;
};

#endif // INCLUDE_STACK_HPP_

