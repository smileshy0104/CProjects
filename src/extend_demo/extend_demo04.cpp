#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

//* 继承中先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反。
// 定义基类 Base
class Base {
 public:
  Base() { cout << "父类的构造函数" << endl; }   // 基类的构造函数，打印提示信息
  ~Base() { cout << "父类的析构函数" << endl; }  // 基类的析构函数，打印提示信息
};

// 定义派生类 Son，继承自 Base
class Son : public Base {
 public:
  Son() { cout << "子类的构造函数" << endl; }   // 子类的构造函数，打印提示信息
  ~Son() { cout << "子类的析构函数" << endl; }  // 子类的析构函数，打印提示信息
};

// 测试函数 test01
void test01() {
  Son son;  // 创建子类对象 son，会自动调用基类和子类的构造函数
}

int main(void) {
  test01();         // 调用测试函数 test01
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}