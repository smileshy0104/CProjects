#include <iostream>
using namespace std;
//* 类模板对象做函数参数

/*
类模板实例化出的对象，向函数传参的方式

一共有三种传入方式:
1.指定传入的类型——直接显式对象的数据类型
2.参数模板化——将对象中的参数变为模板参数进行传递
3.整个类模板化——将这个对象类型，模板化进行传递
*/

// 类模板：定义了一个通用的 Person 类
// T1 表示姓名类型，T2 表示年龄类型
template <class T1, class T2>
class Person {
 public:
  // 构造函数：初始化姓名和年龄
  Person(T1 name, T2 age) {
    cout << "Person 构造函数被调用" << endl;
    this->m_Name = name;  // 初始化姓名
    this->m_Age = age;    // 初始化年龄
  }

  // 成员函数：显示姓名和年龄
  void showPerson() { cout << this->m_Name << " " << this->m_Age << endl; }

  // 成员变量：存储姓名和年龄
  T1 m_Name;  // 姓名类型
  T2 m_Age;   // 年龄类型
};

// 方法一：指定传入类型的函数
// 该函数只能接受 Person<string, int> 类型的对象作为参数
void PrintPerson1(Person<string, int> &p) {
  p.showPerson();  // 调用对象的 showPerson 函数显示信息
}

void test01() {
  // 创建一个 Person<string, int> 对象
  Person<string, int> p1("张三", 11);

  // 调用 PrintPerson1 函数显示对象信息
  PrintPerson1(p1);
}

// 方法二：参数模板化
// 通过模板参数 T1 和 T2，使得函数可以接受任意类型的 Person 对象
template <class T1, class T2>
void PrintPerson2(Person<T1, T2> &p) {
  p.showPerson();  // 调用对象的 showPerson 函数显示信息

  // 输出模板参数 T1 和 T2 的具体数据类型
  cout << "T1的数据类型为" << typeid(T1).name() << endl;
  cout << "T2的数据类型为" << typeid(T2).name() << endl;
}

void test02() {
  // 创建一个 Person<string, int> 对象
  Person<string, int> p2("李四", 12);

  // 调用 PrintPerson2 函数显示对象信息，并输出模板参数类型
  PrintPerson2(p2);
}

// 方法三：整个类模板化
// 通过模板参数 T，使得函数可以接受任意类型的对象
template <class T>
void PrintPerson3(T &p) {
  p.showPerson();  // 调用对象的 showPerson 函数显示信息

  // 输出模板参数 T 的具体数据类型
  cout << "T的数据类型为" << typeid(T).name() << endl;
}

void test03() {
  // 创建一个 Person<string, int> 对象
  Person<string, int> p3("赵四", 14);

  // 调用 PrintPerson3 函数显示对象信息，并输出模板参数类型
  PrintPerson3(p3);
}

int main(void) {
  test01();         // 测试方法一：指定传入类型的函数
  test02();         // 测试方法二：参数模板化
  test03();         // 测试方法三：整个类模板化
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回程序执行状态
}