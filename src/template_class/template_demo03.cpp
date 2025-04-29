#include <iostream>
#include <string>
using namespace std;

//* 类模板中的成员函数创建实际
/*
类模板中成员函数和普通类中成员函数创建实际是有区别的:
1.普通类中的成员函数一开始就可以创建
2.类模板中的成员函数在调用时才创建
*/
// 普通类：定义了 showPerson1 成员函数
class Person1 {
 public:
  void showPerson1() { cout << "Person show1" << endl; }
};

// 普通类：定义了 showPerson2 成员函数
class Person2 {
 public:
  void showPerson2() { cout << "Person show2" << endl; }
};

// 类模板：定义了一个通用类，包含一个类型为 T 的成员变量 obj
template <class T>
class MyClass {
 public:
  T obj;  // 类型为 T 的成员变量

  // 成员函数：调用 obj 的 showPerson1 成员函数
  void func1() {
    obj.showPerson1();  // 调用 obj 的 showPerson1 函数
  }

  // 成员函数：调用 obj 的 showPerson2 成员函数
  void func2() {
    obj.showPerson2();  // 调用 obj 的 showPerson2 函数
  }
};

void test01() {
  // 创建一个 MyClass 对象，模板参数为 Person2
  MyClass<Person2> m;

  // 调用 func1 函数
  // 注意：此处会尝试调用 obj 的 showPerson1 函数，但 obj 是 Person2 类型，
  // Person2 并没有定义 showPerson1 函数，因此会导致编译错误。
  // m.func1();   // 错误

  // 调用 func2 函数
  // 如果取消注释以下代码，则可以正常调用 obj 的 showPerson2 函数。
  m.func2();
}

int main(void) {
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回程序执行状态
}