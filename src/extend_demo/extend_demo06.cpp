#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

//* 继承同名静态成员变量和同名静态成员函数
/*
- 访问子类同名成员，直接访问即可
- 访问父类同名成员，需要加作用域

同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式(通过对象和类名)。
*/

class Base {  // 定义父类Base
 public:
  static void func() {
    cout << "父类静态成员函数调用" << endl;
  }  // 父类静态成员函数func()
  static void func(int a) {
    cout << "父类静态成员重载函数调用" << endl;
  }  // 父类静态成员函数func()的重载版本
  static int m_A;  // 父类静态成员变量m_A
};
int Base::m_A = 100;  // 初始化父类静态成员变量m_A为100

class Son : public Base {  // 定义子类Son，公共继承自Base
 public:
  static void func() {
    cout << "子类静态成员函数调用" << endl;
  }  // 子类静态成员函数func()
  static int m_A;  // 子类静态成员变量m_A（与父类同名）
};
int Son::m_A = 200;  // 初始化子类静态成员变量m_A为200

// 同名静态成员变量的访问方式
void test() {
  // 通过对象访问静态成员变量
  Son son1;
  cout << "通过对象访问" << endl;
  cout << son1.m_A
       << endl;  // 输出子类中的静态成员变量m_A（优先访问子类的同名成员）
  cout << son1.Base::m_A
       << endl;  // 输出父类中的静态成员变量m_A（需要加作用域）

  // 通过类名访问静态成员变量
  cout << "通过类名访问" << endl;
  cout << Son::m_A << endl;  // 输出子类中的静态成员变量m_A
  // 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
  cout << Son::Base::m_A << endl;  // 输出父类中的静态成员变量m_A
}

// 同名静态成员函数的访问方式
void test01() {
  // 通过对象访问静态成员函数
  Son son2;
  cout << "通过对象访问" << endl;
  son2.func();  // 调用子类中的静态成员函数func()（子类的同名成员会隐藏父类的同名成员）
  son2.Base::func();  // 调用父类中的静态成员函数func()（需要加作用域）

  // 通过类名访问静态成员函数
  cout << "通过类名访问" << endl;
  Son::func();        // 调用子类中的静态成员函数func()
  Son::Base::func();  // 调用父类中的静态成员函数func()

  // 子类出现和父类同名的静态成员函数，也会隐藏掉父类中所有同名成员函数（包括重载版本）
  // 如果想访问父类中被隐藏的同名成员函数，需要加作用域
  Son::Base::func(100);  // 调用父类中重载的静态成员函数func(int a)
}

int main(void) {  // 主函数
  test();         // 测试同名静态成员变量的访问方式
  cout << "我是分割线------" << endl;
  test01();         // 测试同名静态成员函数的访问方式
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}