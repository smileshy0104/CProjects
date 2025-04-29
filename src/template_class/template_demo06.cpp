#include <iostream>  // 包含输入输出流库，用于控制台输入输出
#include <string>    // 包含字符串库，用于处理字符串
using namespace std;

//* 类模板成员函数类外实现
// 类模板中成员函数类外实现时，需要加上模板参数列表。

template <class T1, class T2>
class Person {
 public:
  // 构造函数声明
  Person(T1 name, T2 age);

  // 成员函数声明
  void showPerson();

  // 成员变量
  T1 m_Name;  // 姓名，类型为 T1
  T2 m_Age;   // 年龄，类型为 T2
};

// 构造函数类外实现
// 注意：模板参数列表----需要与类模板声明一致
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

void test01() {
  // 创建一个 Person 对象，姓名为字符串 "新二"，年龄为整数 13
  Person<string, int> p1("新二", 13);
  p1.showPerson();  // 调用 showPerson 函数显示信息
}

int main(void) {
  test01();         // 调用 test01 函数进行测试
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}