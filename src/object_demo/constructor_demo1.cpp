#include <iostream>
using namespace std;
/*
#### 拷贝构造函数调用时机
C++中拷贝构造函数调用时机通常有三种情况

- 使用一个已经创建完毕的对象来初始化一个新对象
- 值传递的方式给函数参数传值
- 以值方式返回局部对象
*/
class Person {
 public:
  // 无参构造函数
  Person() { cout << "Person的默认构造函数调用" << endl; }
  // 有参构造函数
  Person(int age) {
    cout << "Person的有参构造函数调用" << endl;
    m_Age = age;
  }
  // 拷贝构造函数
  Person(const Person& p) {
    cout << "Person的拷贝构造函数调用" << endl;
    m_Age = p.m_Age;
  }
  // 析构函数
  ~Person() { cout << "Person的析构函数调用" << endl; }
  int m_Age;
};
// 使用一个已经创建完毕的对象来初始化一个对象
void test01() {
  Person p1(20);
  Person p2(p1);
  cout << "p2的年龄为" << p2.m_Age << endl;
}
// 值传递的方式给函数参数传值
void dowork(Person p) {}
void test02() {
  Person p;
  dowork(p);
}
// 值方式返回局部对象
Person dowork2() {
  Person p1;
  cout << (int*)&p1 << endl;
  return p1;
}
void test03() {
  Person p = dowork2();
  cout << (int*)&p << endl;
}

int main(void) {
  test01();
  cout << "------------------------" << endl;
  test02();
  cout << "------------------------" << endl;
  test03();
  cout << "------------------------" << endl;
  system("pause");
  return 0;
}
