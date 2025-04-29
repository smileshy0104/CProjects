#pragma once  // 防止头文件重复包含

#include <iostream>  // 包含输入输出流库，用于控制台输入输出
using namespace std;

// 定义一个类模板 Person，包含两个类型参数 T1 和 T2
template <class T1, class T2>
class Person {
 public:
  // 构造函数声明，用于初始化姓名和年龄
  Person(T1 name, T2 age);

  // 成员函数声明，用于显示姓名和年龄
  void showPerson();

  // 成员变量，存储姓名，类型为 T1
  T1 m_Name;

  // 成员变量，存储年龄，类型为 T2
  T2 m_Age;
};

// 构造函数类外实现
// 注意：模板参数列表需要与类模板声明一致
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
  this->m_Name = name;  // 初始化姓名
  this->m_Age = age;    // 初始化年龄
}

// 成员函数类外实现
// 注意：模板参数列表需要与类模板声明一致
template <class T1, class T2>
void Person<T1, T2>::showPerson() {
  cout << "姓名: " << this->m_Name << ", 年龄: " << this->m_Age
       << endl;  // 输出姓名和年龄
}