#include <iostream>  // 输入输出流库
#include <string>    // 字符串处理支持
using namespace std;

// 自定义仿函数类 MyAdd：实现两个整数相加的功能
class MyAdd {
 public:
  // 重载 () 运算符，使其可以像函数一样调用
  int operator()(int v1, int v2) {
    return v1 + v2;  // 返回两个整数的和
  }
};

// 测试 MyAdd 类的使用
void test01() {
  MyAdd myadd;                    // 创建 MyAdd 对象
  cout << myadd(10, 10) << endl;  // 调用仿函数，输出结果为 20
}

// 自定义仿函数类 MyPrint：用于打印字符串，并记录打印次数
class MyPrint {
 public:
  // 构造函数，初始化调用次数计数器
  MyPrint() { this->count = 0; }

  // 重载 () 运算符，接收一个字符串参数并打印
  void operator()(string test) {
    cout << "operator()被调用了" << endl;
    cout << test << endl;  // 打印传入的字符串
    this->count++;         // 每次调用后计数器 +1
  }

  int count;  // 成员变量，记录该对象被调用的次数
};

// 测试 MyPrint 类的使用
void test02() {
  MyPrint myprint;  // 创建 MyPrint 对象

  // 多次调用仿函数
  myprint("hello world");
  myprint("hello world");
  myprint("hello world");
  myprint("hello world");
  myprint("hello world");
  myprint("hello world");

  // 输出仿函数被调用的总次数
  cout << "MyPrint调用次数为:" << myprint.count << endl;  // 输出应为 6
}

// 封装一个普通函数，用于调用仿函数
void doPrint(MyPrint& mp, string test) {
  mp(test);  // 调用传入的仿函数对象 mp，并传递字符串参数 test
}

// 测试将仿函数作为参数传递给其他函数
void test03() {
  MyPrint myPrint;                // 创建 MyPrint 对象
  doPrint(myPrint, "hello c++");  // 将仿函数对象传入 doPrint 函数
}

// 主函数入口
int main(void) {
  test01();  // 测试加法仿函数
  test02();  // 测试打印仿函数及状态记录
  test03();  // 测试仿函数作为参数传递

  system("pause");  // 暂停程序（仅限 Windows 系统）
  return 0;         // 返回 0 表示程序正常结束
}