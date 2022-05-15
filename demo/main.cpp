#include <iostream>
#include "Stack.hpp"
#include "StackSecond.hpp"

int main() {
  int x = 6;
  Stack<int> mystack;
  mystack.push(x);
//  mystack.head();
//  mystack.push(0);
//  std::cout << mystack.head() << " ";//<< mystack.pop();

  class Myclass {
   public:
    Myclass(Myclass&) = delete;
    Myclass& operator = (Myclass&) = delete;
    Myclass(Myclass&& obj)  noexcept {
      t2 = std::move(obj.t2);
      t1 = obj.t1;
      t0 = obj.t0;
    }
    Myclass& operator=(Myclass&& obj)  noexcept {
      t2 = std::move(obj.t2);
      t1 = obj.t1;
      t0 = obj.t0;
      return *this;
    }
    Myclass(){
      t0 = 7;
      t1 = 0.1;
      t2 = "0ggg";
    }
    Myclass(int a, double b, std::string c): t0(a), t1(b), t2(c){}
    int t0;
    double t1;
    std::string t2;
  };
  StackTwo<Myclass> MySteck;
  int t0 = 2;
  double t1 = 2.2;
  std::string t2 = "2";
  MySteck.push_emplace(Myclass(1, 1.1, "12"));
  MySteck.push_emplace(t0, t1, t2);
  MySteck.push(Myclass());
 std::cout <<  MySteck.pop().t0 << MySteck.pop().t0 << MySteck.pop().t0;
}