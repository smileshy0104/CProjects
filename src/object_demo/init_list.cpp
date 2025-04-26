#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

class Person {
 public:
  // 传统赋值操作（被注释掉的部分）
  /*
  Person(int a, int b, int c) {
      m_A = a; // 在构造函数体内逐个赋值
      m_B = b;
      m_C = c;
  }
  */

  // 初始化列表方式初始化属性
  Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {}
  // 使用初始化列表直接初始化成员变量，效率更高，尤其适用于引用、常量或自定义类型成员变量

  int m_A;  // 成员变量 A
  int m_B;  // 成员变量 B
  int m_C;  // 成员变量 C
};

void test() {
  // 创建一个 Person 对象 p，并通过初始化列表设置其属性值
  // Person p(10,20,30); // 被注释掉的构造方式
  Person p(30, 20,
           10);  // 使用初始化列表构造对象，参数顺序与初始化列表中的顺序一致

  // 输出对象的成员变量值
  cout << p.m_A << endl;  // 输出 m_A 的值
  cout << p.m_B << endl;  // 输出 m_B 的值
  cout << p.m_C << endl;  // 输出 m_C 的值
}

int main(void) {
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回0表示程序正常结束
}