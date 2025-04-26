#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

// 深拷贝与浅拷贝问题
/*
**浅拷贝**：简单的赋值拷贝操作。对于指针成员变量，浅拷贝————只会复制指针地址，而不会复制指针指向的内容。
**深拷贝**：在堆区中重新申请空间，进行拷贝操作。对于指针成员变量，深拷贝会复制指针指向的内容，而不是仅仅复制指针地址。
*/
//* **浅拷贝带来的问题——内存重复释放**。如果两个对象共享同一个指针，并且在析构函数中都释放该指针指向的内存，会导致同一块内存被释放两次，从而引发未定义行为。

class Person {
 public:
  // 默认构造函数
  Person() { cout << "Person的默认构造函数调用" << endl; }

  // 有参构造函数
  Person(int age, int height) {
    m_Height = new int(height);  // 在堆区动态分配内存存储身高
    m_Age = age;                 // 初始化年龄
    cout << "Person的有参构造函数调用" << endl;
  }

  // 拷贝构造函数
  Person(const Person& p) {
    cout << "Person的拷贝构造函数调用" << endl;
    m_Age = p.m_Age;        // 浅拷贝年龄（整型变量）
    m_Height = p.m_Height;  // 浅拷贝指针（直接复制指针地址）
    // 编译器默认实现的就是这行代码，但这里存在浅拷贝问题
  }
  // 深拷贝操作
  Person(const Person& p) {
    cout << "Person的拷贝构造函数调用" << endl;
    m_Age = p.m_Age;
    // m_Height = p.m_Height;编译器默认实现的就是这行代码
    // 深拷贝操作
    m_Height = new int(*p.m_Height);
  }

  // 析构函数
  ~Person() {
    // 将堆区开辟的数据进行释放
    if (m_Height != NULL) {  // 检查指针是否为空
      delete m_Height;       // 释放堆区内存
      m_Height = NULL;       // 将指针置空，避免野指针
    }
    cout << "Person的析构构造函数调用" << endl;
  }

  int m_Age;  // 年龄，使用栈区存储
  int*
      m_Height;  // 身高，使用堆区存储（为什么要用指针？因为需要动态分配内存来模拟复杂场景）
};

// 测试函数
void test() {
  Person p1(18, 166);  // 创建一个 Person 对象 p1，初始化年龄为 18，身高为 166
  cout << p1.m_Age << "\t" << *p1.m_Height << endl;  // 输出 p1 的年龄和身高

  Person p2(p1);  // 使用拷贝构造函数创建 p2，此时会发生浅拷贝问题
  cout << p2.m_Age << "\t" << *p2.m_Height << endl;  // 输出 p2 的年龄和身高
}

int main(void) {
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回0表示程序正常结束
}