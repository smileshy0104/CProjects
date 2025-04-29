#include <iostream>
using namespace std;

//* 普通函数与函数模板的区别：
// 1. 普通函数调用时----可以发生隐式类型转换。
// 2. 函数模板----在使用自动类型推导时，无法发生隐式类型转换。
// 3. 函数模板----在显式指定类型时，可以发生隐式类型转换。

// 普通函数：支持隐式类型转换
int myAdd01(int a, int b) {
  return a + b;  // 返回两个整数的和
}

// 函数模板：支持通用类型的加法操作
template <class T>
T myAdd02(T a, T b) {
  return a + b;  // 返回两个同类型变量的和
}

void test01() {
  int a = 10;
  int b = 20;
  char c = 'c';  // 字符 'c' 的 ASCII 值为 99

  // 调用普通函数 myAdd01
  // 在普通函数中，char 类型会隐式转换为 int 类型（ASCII 值）
  cout << myAdd01(a, c) << endl;  // 输出结果为 10 + 99 = 109

  // 调用函数模板 myAdd02 使用自动类型推导
  // 自动类型推导时，编译器----无法将 char 和 int 隐式----转换为同一类型
  // 因此以下代码会导致编译错误：
  // cout << myAdd02(a, c) << endl;

  // 显式指定模板类型为 int
  // 此时 char 类型----会被隐式转换为 int 类型（ASCII 值） char ->  int
  cout << myAdd02<int>(a, c) << endl;  // 输出结果为 10 + 99 = 109
}

int main(void) {
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回程序执行状态
}