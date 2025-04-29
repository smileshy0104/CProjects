#include <iostream>
#include <string>
using namespace std;

//* C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板。

// 定义一个Person类，包含姓名和年龄两个成员变量
class Person {
 public:
  // 构造函数：初始化姓名和年龄
  Person(string name, int age) {
    this->m_Name = name;  // 初始化姓名
    this->m_Age = age;    // 初始化年龄
  }

  string m_Name;  // 姓名
  int m_Age;      // 年龄
};

// 模板函数：用于比较两个数据是否相等
// 适用于大多数数据类型
template <class T>
bool myCompare(T& a, T& b) {
  if (a == b) {  // 使用 == 运算符比较两个值
    return true;
  } else {
    return false;
  }
}

// 模板特化：针对Person类实现特定的比较逻辑
// 因为Person类无法直接使用 == 运算符进行比较，需要自定义比较规则
template <>
bool myCompare(Person& p1, Person& p2) {
  if (p1.m_Name == p2.m_Name &&
      p1.m_Age == p2.m_Age) {  // 比较姓名和年龄是否相等
    return true;
  } else {
    return false;
  }
}

// 测试函数：测试普通数据类型的比较
void test01() {
  int a = 10;
  int b = 20;

  bool ret = myCompare(a, b);  // 调用模板函数比较两个整数
  if (ret) {
    cout << "相等" << endl;  // 如果相等，输出“相等”
  } else {
    cout << "不相等" << endl;  // 如果不相等，输出“不相等”
  }
}

// 测试函数：测试Person类的比较
void test02() {
  Person p1("Tom", 10);  // 创建第一个Person对象
  Person p2("Tom", 10);  // 创建第二个Person对象

  bool ret = myCompare(p1, p2);  // 调用模板特化版本比较两个Person对象
  if (ret) {
    cout << "相等" << endl;  // 如果相等，输出“相等”
  } else {
    cout << "不相等" << endl;  // 如果不相等，输出“不相等”
  }
}

int main(void) {
  test01();         // 测试普通数据类型的比较
  test02();         // 测试Person类的比较
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回程序执行状态
}