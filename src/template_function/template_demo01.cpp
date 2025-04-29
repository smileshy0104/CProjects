#include <iostream>
using namespace std;

//* template——声明创建模板
/*
typena me——表明其后面的 符号为一种数据类型，----可以用class代替。

T——通用的数据类型，名称可以替换，通常为大写字母。
*/

/*
总结:
函数模板利用关键字template
使用函数类型模板有两种方式：自动类型推导、显示指定类型
模板的目的是为了提高复用性，将类型参数化
*/

// 非模板函数：交换两个整型变量的值
void SwapInt(int &a, int &b) {
  int temp = b;  // 临时变量存储 b 的值
  b = a;         // 将 a 的值赋给 b
  a = temp;      // 将临时变量的值赋给 a
}

// 非模板函数：交换两个浮点型变量的值
void SwapDouble(double &a, double &b) {
  double temp = a;  // 临时变量存储 a 的值
  a = b;            // 将 b 的值赋给 a
  b = temp;         // 将临时变量的值赋给 b
}

// 函数模板：用于交换任意类型变量的值
// template <typename T> 声明一个模板，T 是通用数据类型
// template <typename T>
template <class T>
void MySwap(T &a, T &b) {
  T Temp = a;  // 使用 T 类型的临时变量存储 a 的值
  a = b;       // 将 b 的值赋给 a
  b = Temp;    // 将临时变量的值赋给 b
}

// 测试函数：演示函数模板的使用
void test01() {
  int a = 10;
  int b = 20;

  // 利用函数模板进行交换
  // 编译器会自动推导出 T 的类型为 int
  MySwap(a, b);

  cout << a << endl;  // 输出交换后的 a 值
  cout << b << endl;  // 输出交换后的 b 值

  double c = 11.1;
  double d = 12.2;

  // 显式指定模板参数类型为 double
  MySwap<double>(c, d);

  cout << c << endl;  // 输出交换后的 c 值
  cout << d << endl;  // 输出交换后的 d 值
}

int main(void) {
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回程序执行状态
}