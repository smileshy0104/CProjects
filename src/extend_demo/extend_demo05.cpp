#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

//* 继承同名成员处理方式

/*
- 访问子类同名成员，直接访问即可
- 访问父类同名成员，需要加**作用域**

1. 子类对象可以直接访问到子类中同名成员
2. 子类对象加作用域可以访问到父类同名成员
3.
当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类同名函数。
*/
class Base {  // 定义父类Base
 public:
  Base() { m_A = 100; }  // 父类构造函数，初始化成员变量m_A为100
  void func() { cout << "父类同名成员函数调用" << endl; }  // 父类成员函数func()
  void func(int a) {
    cout << "父类同名重载成员函数调用" << endl;
  }  // 父类成员函数func()的重载版本
  int m_A;  // 父类成员变量m_A
};

class Son : public Base {  // 定义子类Son，公共继承自Base
 public:
  Son() { m_A = 200; }  // 子类构造函数，初始化成员变量m_A为200
  void func() { cout << "子类同名成员函数调用" << endl; }  // 子类成员函数func()
  int m_A;  // 子类成员变量m_A（与父类同名）
};

// 同名成员属性处理方式
void test01() {
  Son son;                  // 创建子类对象son
  cout << son.m_A << endl;  // 输出子类中的m_A（优先访问子类的同名成员）
  // 如果要通过子类对象访问到父类中的同名成员，需要加作用域。
  cout << son.Base::m_A << endl;  // 输出父类中的m_A
}

// 同名成员函数处理方式
void test02() {
  Son son1;     // 创建子类对象son1
  son1.func();  // 调用子类中的func()（子类的同名成员会隐藏父类的同名成员）
  son1.Base::func();  // 调用父类中的func()（需要加作用域）
  // 如果子类中出现和父类同名的成员函数
  // 子类的同名成员会---隐藏掉父类中所有同名成员函数
  // 如果想要访问到父类中被隐藏的同名成员函数，需要加作用域
  son1.Base::func(10);  // 调用父类中重载的func(int a)
}

int main(void) {    // 主函数
  test02();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}