#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

//* 常函数
class Person {
 public:
  // 构造函数
  Person() {
    m_a = 10;
    m_b = 20;
  }
  // this指针的本质是指针常量，指针的指向是不可以修改的
  // 就相当于 Person *const this;
  // 在成员函数后面加 const 修饰的是 this 指向的内容，让指针指向的值也不可以修改
  void showPerson() const {  // 加个 const 就不允许修改成员变量了
    // this->m_a = 100; // 错误：在常函数中，不能修改非 mutable 成员变量
    this->m_b = 100;  // 正确：mutable 修饰的成员变量可以在常函数中修改
    // this = NULL; // 错误：this 指针是不可以修改指针的指向的
  }

  int m_a;          // 普通成员变量，在常函数中不可修改
  mutable int m_b;  // 加了 mutable
                    // 修饰的特殊变量，即使在常函数或常对象中，也可以修改这个值

  void func() {
    m_a = 100;  // 在普通成员函数中是可以修改成员变量的
  }
};

// 测试常函数
void test() {
  Person P;        // 创建一个普通对象 P
  P.showPerson();  // 调用常函数 showPerson
}

// 测试常对象
void test1() {
  const Person p;  // 在对象前加 const，变为常对象
  // p.m_a = 100; // 错误：常对象的成员变量（非 mutable）不可修改
  p.m_b = 100;  // 正确：mutable 修饰的成员变量可以在常对象中修改

  // 常对象只能调用常函数
  p.showPerson();  // 正确：常对象可以调用常函数
  // p.func(); // 错误：常对象不能调用普通成员函数，因为普通成员函数可以修改属性
}

int main(void) {
  test();           // 调用测试常函数的函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回0表示程序正常结束
}