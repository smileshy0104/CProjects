#include <iostream>   // 引入输入输出流库
#include <string>     // 引入字符串库
using namespace std;  // 使用标准命名空间

// 定义 Calculator 类
class Calculator {
 public:
  // 根据操作符计算结果
  int getResult(string oper) {
    if (oper == "+") {         // 如果操作符是加号
      return m_Num1 + m_Num2;  // 返回加法结果
    } else if (oper == "-") {  // 如果操作符是减号
      return m_Num1 - m_Num2;  // 返回减法结果
    } else if (oper == "*") {  // 如果操作符是乘号
      return m_Num1 * m_Num2;  // 返回乘法结果
    }
    // 如果想扩展新的功能，需要修改原码
    // 在真实的开发中，实行开闭原则，对扩展进行开放，对修改进行关闭
    // 当前设计不符合开闭原则，新增功能需要修改此方法
  }

  int m_Num1;  // 第一个操作数
  int m_Num2;  // 第二个操作数
};

// 测试函数 test
void test() {
  Calculator c;   // 创建 Calculator 对象
  c.m_Num1 = 10;  // 设置第一个操作数为 10
  c.m_Num2 = 10;  // 设置第二个操作数为 10
  cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+")
       << endl;  // 输出加法结果
}

int main(void) {
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}