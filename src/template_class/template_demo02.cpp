#include <iostream>
#include <string>
using namespace std;
//* 类模板与函数模板的区别
/*
类模板与函数模板的区别主要有两点:
1.类模板没有自动类型推导的使用方式(类模板使用----只能用显式指定类型方式)
2.类模板在模板参数列表中可以有默认参数
*/

// 类模板：定义了一个通用的 Person 类
// 模板参数列表中可以指定默认类型，默认情况下 AgeType 为 int
template <class NameType, class AgeType = int>
class Person {
 public:
  // 构造函数：初始化姓名和年龄
  Person(NameType name, AgeType age) {
    this->m_Name = name;  // 初始化姓名
    this->m_Age = age;    // 初始化年龄
  }

  // 成员函数：显示姓名和年龄
  void ShowPerson() { cout << this->m_Name << " " << this->m_Age << endl; }

  // 成员变量：存储姓名和年龄
  NameType m_Name;  // 姓名类型
  AgeType m_Age;    // 年龄类型
};

// 测试函数：类模板没有自动类型推导功能
void test01() {
  // 类模板在实例化时需要显式指定模板参数类型
  // 以下代码会报错，因为类模板不支持自动类型推导
  // Person p("李四", 13);

  // 正确的方式是显式指定模板参数类型
  Person<string, int> p("李四",
                        13);  // 显式指定 NameType 为 string，AgeType 为 int
  p.ShowPerson();             // 调用成员函数显示姓名和年龄
}

// 测试函数：类模板支持模板参数默认类型
void test02() {
  // 在模板参数列表中，AgeType 默认为 int，因此可以省略 AgeType 的显式指定
  Person<string> p2("张三", 13);  // 等价于 Person<string, int> p2("张三", 13);
}

int main(void) {
  test01();         // 测试类模板的显式类型指定
  test02();         // 测试类模板的默认类型功能
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回程序执行状态
}