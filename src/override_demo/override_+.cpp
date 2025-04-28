#include <iostream>   // 引入输入输出流库
#include <string>     // 引入字符串库（虽然这里没有用到）
using namespace std;  // 使用标准命名空间

// 加号运算符重载示例

class Person {  // 定义一个名为Person的类
 public:
  // 1. 成员函数重载+
  /*Person operator+(Person& p) {
          Person temp;
          temp.m_A = this->m_A + p.m_A; // 将当前对象的m_A与参数p的m_A相加
          temp.m_B = this->m_B + p.m_B; // 将当前对象的m_B与参数p的m_B相加
          return temp; // 返回一个新的Person对象
  }*/
  int m_A;  // 公有成员变量m_A
  int m_B;  // 公有成员变量m_B
};

// 2. 全局函数重载+
Person operator+(Person& p1, Person& p2) {  // 定义全局函数重载+运算符
  Person temp;                              // 创建一个临时的Person对象
  temp.m_A = p1.m_A + p2.m_A;               // 将p1的m_A与p2的m_A相加
  temp.m_B = p1.m_B + p2.m_B;               // 将p1的m_B与p2的m_B相加
  return temp;                              // 返回结果对象
}

// 函数重载版本：支持Person对象与整数相加
Person operator+(Person& p1,
                 int num) {  // 定义全局函数重载+运算符（支持整数相加）
  Person temp;               // 创建一个临时的Person对象
  temp.m_A = p1.m_A + num;   // 将p1的m_A与整数num相加
  temp.m_B = p1.m_B + num;   // 将p1的m_B与整数num相加
  return temp;               // 返回结果对象
}

void test01() {  // 测试函数
  Person p1;     // 创建Person对象p1
  p1.m_A = 10;   // 初始化p1的m_A为10
  p1.m_B = 10;   // 初始化p1的m_B为10

  Person p2;    // 创建Person对象p2
  p2.m_A = 10;  // 初始化p2的m_A为10
  p2.m_B = 10;  // 初始化p2的m_B为10

  // 成员函数重载的本质调用方式
  // Person p3 = p1.operator+(p2); // 调用成员函数重载的+运算符
  // Person p3 = p1 + p2; // 简化形式

  // 全局函数重载的本质调用方式
  // Person p3 = operator+(p1, p2); // 调用全局函数重载的+运算符

  /*cout << p3.m_A << endl; // 输出p3的m_A
  cout << p3.m_B << endl; // 输出p3的m_B*/

  // 运算符重载也可以发生函数重载
  Person p3 = p1 + 10;     // 调用全局函数重载的+运算符（支持整数相加）
  cout << p3.m_A << endl;  // 输出p3的m_A
  cout << p3.m_B << endl;  // 输出p3的m_B
}

int main(void) {    // 主函数
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}