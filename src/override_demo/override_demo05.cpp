#include <iostream>   // 引入输入输出流库
#include <string>     // 引入字符串库
using namespace std;  // 使用标准命名空间

// 函数调用运算符重载示例

class MyPrint {  // 定义一个名为MyPrint的类
 public:
  // 重载函数调用运算符()，使其像函数一样可以被调用
  void operator()(string text) {  // 参数为字符串类型
    cout << text << endl;         // 输出传入的字符串，并换行
  }
};

class MyAdd {  // 定义一个名为MyAdd的类
 public:
  // 重载函数调用运算符()，实现两个整数相加的功能
  int operator()(int a, int b) {  // 参数为两个整数
    return a + b;                 // 返回两数之和
  }
};

void test() {              // 测试函数
  MyPrint myprint;         // 创建MyPrint对象myprint
  myprint("hello world");  // 调用重载的()运算符，输出"hello world"

  MyAdd myadd;                  // 创建MyAdd对象myadd
  cout << myadd(1, 2) << endl;  // 调用重载的()运算符，计算1+2并输出结果

  // 匿名函数对象：创建临时的MyAdd对象并立即调用其()运算符
  // 特点：当前行被执行完后，匿名对象会被立即释放
  cout << MyAdd()(100, 100)
       << endl;  // 创建临时MyAdd对象，计算100+100并输出结果
}

int main(void) {    // 主函数
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}