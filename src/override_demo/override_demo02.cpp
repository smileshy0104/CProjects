#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

// 重载递增运算符示例

class MyInteger {  // 定义一个名为MyInteger的类
  friend ostream& operator<<(
      ostream& cout, MyInteger myint);  // 声明友元函数，用于重载<<运算符

 public:
  MyInteger() { m_Num = 0; }  // 构造函数，初始化成员变量m_Num为0

  // 重载++运算符——前置
  // 返回引用是为了支持连续递增操作（如：++++myint）
  MyInteger& operator++() {
    ++m_Num;       // 先将m_Num加1
    return *this;  // 返回当前对象的引用
  }

  // 重载++运算符——后置
  MyInteger operator++(
      int)  // 这里的int是一个占位参数，用来区分前置递增和后置递增
  {
    MyInteger temp = *this;  // 创建一个临时对象，保存当前值
    m_Num++;                 // 将m_Num加1
    return temp;             // 返回递增前的值
    // 后置递增返回的是值，而不是引用，因为返回局部对象的引用会导致非法操作
  }

 private:
  int m_Num;  // 私有成员变量m_Num
};

// 全局函数重载左移运算符
ostream& operator<<(ostream& cout, MyInteger myint) {
  cout << myint.m_Num << endl;  // 输出m_Num的值
  return cout;                  // 返回ostream对象，支持链式调用
}

void test() {           // 测试前置递增
  MyInteger myint;      // 创建MyInteger对象myint
  cout << ++(++myint);  // 调用前置递增两次，并输出结果
  cout << myint;        // 再次输出myint的值
}

void test02() {             // 测试后置递增
  MyInteger myint;          // 创建MyInteger对象myint
  cout << myint++ << endl;  // 调用后置递增，并输出递增前的值
  cout << myint << endl;    // 再次输出myint的值
}

int main(void) {  // 主函数
  test();         // 调用测试前置递增的函数
  cout << "--------------------------------------" << endl;
  test02();         // 调用测试后置递增的函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}