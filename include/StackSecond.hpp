//Copyright by Spertis

#ifndef INCLUDE_STACKSECOND_HPP_
#define INCLUDE_STACKSECOND_HPP_

#include <utility>
#include <memory>


template <typename T>
class StackTwo
{
 public:
  StackTwo(const StackTwo&) = delete;
  StackTwo& operator = (const StackTwo&) = delete;
  StackTwo(): ref3rence(nullptr) {}
  ~StackTwo(){
    while (ref3rence) {
      pop();
    }
  }
  template <typename ... Args>
  void push_emplace(Args&&... value) {
    ref3rence = std::move(std::make_unique<StackObj>(
        StackObj(std::move(ref3rence),
                 std::move(T(std::forward<Args>(value)...)))));
  }
  void push(T&& value) {
    ref3rence = std::move(std::make_unique<StackObj>(
        StackObj(std::move(ref3rence), std::forward<T>(value))));
  }
  const T& head() const {
    return ref3rence->value;
  }
  T pop() {
    if (ref3rence != nullptr) {
      T del = std::move(ref3rence->value);
      ref3rence = std::move(ref3rence->last);
      return del;
    }
    throw std::runtime_error("Stack is empty");
  }
 private:
  struct StackObj{
    std::unique_ptr<StackObj> last;
    T value;
    explicit StackObj(std::unique_ptr<StackObj> ref3rence = nullptr,
                      T&& valu = T()) {
      value = std::forward<T>(valu);
      last = std::move(ref3rence);
    }
  };
  std::unique_ptr<StackObj> ref3rence;
};

#endif  // INCLUDE_STACKSECOND_HPP_


