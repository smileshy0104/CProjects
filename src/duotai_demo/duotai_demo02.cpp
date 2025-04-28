#include <iostream>   // 引入输入输出流库
#include <string>     // 引入字符串库
using namespace std;  // 使用标准命名空间

// 利用多态实现计算器

// 实现计算器抽象类
class AbstractCalculator {
 public:
  virtual int getResult() {
    return 0;
  }  // 虚函数，默认返回 0，子类需要重写此方法
  int m_Num1;  // 第一个操作数
  int m_Num2;  // 第二个操作数
};

// 加法计算器类，继承自 AbstractCalculator
class AddCalculator : public AbstractCalculator {
 public:
  int getResult() override {
    return m_Num1 + m_Num2;
  }  // 重写虚函数，实现加法运算
};

// 减法计算器类，继承自 AbstractCalculator
class SubCalculator : public AbstractCalculator {
 public:
  int getResult() override {
    return m_Num1 - m_Num2;
  }  // 重写虚函数，实现减法运算
};

// 乘法计算器类，继承自 AbstractCalculator
class MulCalculator : public AbstractCalculator {
 public:
  int getResult() override {
    return m_Num1 * m_Num2;
  }  // 重写虚函数，实现乘法运算
};

// 测试函数 test
void test() {
  // 多态使用条件
  // 父类指针或者引用指向子类对象

  // 加法
  AbstractCalculator* abc =
      new AddCalculator;  // 父类指针指向子类对象（AddCalculator）
  abc->m_Num1 = 10;       // 设置第一个操作数为 10
  abc->m_Num2 = 10;       // 设置第二个操作数为 10
  cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult()
       << endl;  // 输出加法结果
  delete abc;    // 堆区数据，手动开辟手动释放（释放 AddCalculator 对象）

  // 减法
  abc = new SubCalculator;  // 父类指针指向子类对象（SubCalculator）
  abc->m_Num1 = 10;         // 设置第一个操作数为 10
  abc->m_Num2 = 10;         // 设置第二个操作数为 10
  cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult()
       << endl;  // 输出减法结果
  delete abc;    // 释放 SubCalculator 对象

  // 乘法
  abc = new MulCalculator;
  abc->m_Num1 = 10;
  abc->m_Num2 = 10;
  cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
  delete abc;
}

int main(void) {
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}