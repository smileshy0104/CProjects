#include <iostream>
#include <string>
using namespace std;

//* 类模板：用于创建通用类型的类
// NameType 和 AgeType 是模板参数，可以是任意数据类型
// 这使得 Person 类可以处理不同类型的姓名和年龄
template <class NameType, class AgeType>
class Person {
 public:
  // 构造函数：初始化姓名和年龄
  Person(NameType name, AgeType age) {
    this->m_Age = age;    // 初始化年龄
    this->m_Name = name;  // 初始化姓名
  }

  // 成员函数：显示姓名和年龄
  void showPerson() { cout << this->m_Name << " " << this->m_Age << endl; }

  // 成员变量：存储姓名和年龄
  NameType m_Name;
  AgeType m_Age;
};

void test01() {
  // 创建一个 Person 对象，指定模板参数为 string 和 int 类型
  // <> 中是模板的参数列表，分别对应 NameType 和 AgeType
  Person<string, int> p1("张三", 10);

  // 调用成员函数显示姓名和年龄
  p1.showPerson();
}

int main(void) {
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回程序执行状态
}