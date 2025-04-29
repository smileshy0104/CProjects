#include <iostream>  // 包含输入输出流库，用于控制台输入输出
#include <string>    // 包含字符串库，用于处理字符串
using namespace std;

//* 类模板与友元  建议全局函数做类内实现，用法简单，而且编译器可以直接识别。
/*
 全局函数---类内实现，直接在类内声明友元即可（建议使用）
 全局函数---类外实现，需要提前让编译器知道全局函数的存在
*/

// 通过全局函数打印 Person 的信息
// 提前让编译器知道 Person 类的存在
template <class T1, class T2>
class Person;

// 类外实现的全局函数声明
template <class T1, class T2>
void PrintPerson2(Person<T1, T2> p);

// 类模板定义
template <class T1, class T2>
class Person {
  // 全局函数类内实现
  friend void PrintPerson(Person<T1, T2> p) {
    cout << "类内实现 - 姓名: " << p.m_Name << ", 年龄: " << p.m_Age << endl;
  }

  // 全局函数类外实现
  // 加空模板参数列表
  // 如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
  friend void PrintPerson2<>(Person<T1, T2> p);

 public:
  // 构造函数声明
  Person(T1 name, T2 age) {
    this->m_Name = name;  // 初始化姓名
    this->m_Age = age;    // 初始化年龄
  }

 private:
  T1 m_Name;  // 姓名，类型为 T1
  T2 m_Age;   // 年龄，类型为 T2
};

// 类外实现的全局函数定义
template <class T1, class T2>
void PrintPerson2(Person<T1, T2> p) {
  cout << "类外实现 - 姓名: " << p.m_Name << ", 年龄: " << p.m_Age << endl;
}

void test01() {
  // 创建一个 Person 对象，姓名为字符串 "zbc"，年龄为整数 12
  Person<string, int> p("zbc", 12);
  PrintPerson(p);  // 调用类内实现的全局函数显示信息
}

void test02() {
  // 创建一个 Person 对象，姓名为字符串 "年轻人"，年龄为整数 18
  Person<string, int> p2("年轻人", 18);
  PrintPerson2(p2);  // 调用类外实现的全局函数显示信息
}

int main(void) {
  test01();         // 调用 test01 函数进行测试
  test02();         // 调用 test02 函数进行测试
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}