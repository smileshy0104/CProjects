#include <iostream>
using namespace std;
// 构造函数的调用规则
/*
**默认情况下，C++编译器至少给一个类添加三个函数**

1. **默认构造函数**(无参、函数体为空)
2. **默认析构函数**(无参、函数体为空)
3. **默认拷贝函数构造函数，对属性值拷贝**
*/

// 构造函数调用规则如下:
/*
- 如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造
- **如果用户定义拷贝构造函数，C++不会再提供其他构造函数**

**用户提供了有参，编译器不会提供无参，但会提供拷贝；**
**用户提供了拷贝，编译器什么构造函数都不会提供。**
*/

class Person {
 public:
  Person() { cout << "Person的默认构造函数调用" << endl; }
  Person(int age) {
    m_Age = age;
    cout << "Person的有参构造函数调用" << endl;
  }
  Person(const Person& p) {
    m_Age = p.m_Age;
    cout << "Person的拷贝构造函数调用" << endl;
  }
  ~Person() { cout << "Person的默认析构函数调用" << endl; }
  int m_Age;
};
void test() {
  Person p;
  p.m_Age = 18;
  Person p2(p);
  cout << "p2的年龄为" << p2.m_Age << endl;
}
// 当用户创建了有参构造函数，编译器就不再提供默认无参构造函数，但是会提供默认拷贝构造函数
void test02() {}
int main(void) {
  test();
  cout << "----------------------------------------------------------------"
       << endl;
  test02();
  system("pause");
  return 0;
}
