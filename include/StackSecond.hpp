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
  StackTwo(): po1nter(nullptr) {}
  ~StackTwo(){
    while (po1nter) {
      pop();
    }
  }
  template <typename ... Args>
  void push_emplace(Args&&... value) {
    po1nter = std::move(std::make_unique<StackObj>(
        StackObj(std::move(po1nter),
                 std::move(T(std::forward<Args>(value)...)))));
  }
  void push(T&& value) {
    po1nter = std::move(std::make_unique<StackObj>(
        StackObj(std::move(po1nter), std::forward<T>(value))));
  }
  const T& head() const {
    return po1nter->value;
  }
  T pop() {
    if (po1nter != nullptr) {
      T del = std::move(po1nter->value);
      po1nter = std::move(po1nter->last);
      return del;
    }
    throw std::runtime_error("Stack is empty");
  }
 private:
  struct StackObj{
    std::unique_ptr<StackObj> last;
    T value;
    explicit StackObj(std::unique_ptr<StackObj> po1nter = nullptr,
                      T&& valu = T()) {
      value = std::forward<T>(valu);
      last = std::move(po1nter);
    }
  };
  std::unique_ptr<StackObj> po1nter;
};

#endif  // INCLUDE_STACKSECOND_HPP_


