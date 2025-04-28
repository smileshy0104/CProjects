#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

//* 多继承语法
// 多继承中如果父类中出现了同名情况，子类使用时要加作用域。
// 定义第一个父类Base1
class Base1 {
 public:
  Base1() { m_A = 100; }  // 构造函数，初始化成员变量m_A为100
  int m_A;                // 成员变量m_A
};

// 定义第二个父类Base2
class Base2 {
 public:
  Base2() { m_A = 200; }  // 构造函数，初始化成员变量m_A为200
  int m_A;                // 成员变量m_A（与Base1中的m_A同名）
};

// 子类Son继承自Base1和Base2
class Son : public Base1, public Base2 {  // 多继承语法
 public:
  Son() {
    m_C = 300;  // 初始化成员变量m_C为300
    m_D = 400;  // 初始化成员变量m_D为400
  }
  int m_C;  // 成员变量m_C
  int m_D;  // 成员变量m_D
};

void test01() {
  Son son1;  // 创建子类对象son1
  cout << sizeof(son1)
       << endl;  // 输出子类对象son1的大小（字节数）
                 // 由于Son类包含两个int类型的基类成员（Base1::m_A 和
                 // Base2::m_A）， 以及两个自身的int类型成员（m_C 和
                 // m_D），总共4个int类型成员。
                 // 在大多数系统中，一个int占4字节，因此总大小为16字节。

  // 访问父类中的同名成员变量m_A
  cout << "第一个父类的m_A:" << son1.Base1::m_A
       << endl;  // 通过作用域解析运算符访问Base1中的m_A
  cout << "第二个父类的m_A:" << son1.Base2::m_A
       << endl;  // 通过作用域解析运算符访问Base2中的m_A
}

int main(void) {    // 主函数
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}