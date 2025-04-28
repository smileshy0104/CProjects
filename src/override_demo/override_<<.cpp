#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

class Person {  // 定义一个名为Person的类
  friend ostream& operator<<(ostream& cout,
                             Person& p);  // 声明友元函数，用于重载<<运算符

 public:
  Person(int a, int b) {  // 构造函数，初始化成员变量m_A和m_B
    m_A = a;
    m_B = b;
  }

  // 下面这段代码被注释掉了，表示不使用成员函数来重载<<运算符
  // 因为成员函数无法实现将cout放在左边的语法（如：cout << p）
  /*
  void operator<<(ostream &cout, Person &p) {
      cout << p.m_A << endl;
      cout << p.m_B << endl;
  }
  */

 private:
  int m_A;  // 私有成员变量m_A
  int m_B;  // 私有成员变量m_B
};

// 全局函数重载<<运算符，本质是operator<<(cout, p)，简化后为cout << p
ostream& operator<<(ostream& cout, Person& p) {
  cout << p.m_A << endl;  // 输出m_A的值
  cout << p.m_B << endl;  // 输出m_B的值
  return cout;            // 返回ostream对象，支持链式调用
}

void test() {        // 定义测试函数
  Person p(10, 10);  // 创建Person对象p，初始化m_A和m_B为10
  cout << p << "hello world"
       << endl;  // 调用重载的<<运算符，输出p的对象信息和字符串"hello world"
}

int main(void) {    // 主函数
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}