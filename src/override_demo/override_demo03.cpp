#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

class Person {  // 定义一个名为Person的类
 public:
  Person(int age) {
    m_Age = new int(age);
  }  // 构造函数，初始化成员变量m_Age为动态分配的整数

  ~Person() {             // 析构函数，释放动态分配的内存
    if (m_Age != NULL) {  // 检查m_Age是否为空
      delete m_Age;       // 释放堆区内存
      m_Age = NULL;       // 将指针置为空，避免野指针
    }
  }

  // 重载赋值运算符
  Person &operator=(Person &p) {  // 赋值运算符重载函数
    // 编译器默认提供的赋值操作是浅拷贝（仅复制指针地址）
    // m_Age = p.m_Age;
    // 浅拷贝会导致两个对象共享同一块堆区内存，可能会引发内存泄漏或非法访问问题。

    // 正确的做法：先判断当前对象是否有堆区属性，如果有则先释放干净
    if (m_Age != NULL) {  // 检查当前对象的m_Age是否为空
      delete m_Age;       // 释放当前对象的堆区内存
      m_Age = NULL;       // 将指针置为空，避免野指针
    }

    // 深拷贝操作：为当前对象重新分配内存，并复制数据
    m_Age =
        new int(*p.m_Age);  // 动态分配新的内存，并将p对象的m_Age值赋给当前对象

    return *this;  // 返回当前对象的引用，支持链式赋值
  }

  int *m_Age;  // 指向堆区整数的指针
};

void test1() {    // 测试函数
  Person p1(18);  // 创建Person对象p1，初始化年龄为18
  Person p2(20);  // 创建Person对象p2，初始化年龄为20
  Person p3(30);  // 创建Person对象p3，初始化年龄为30

  p3 = p2 = p1;  // 链式赋值：p2 = p1，然后p3 = p2
                 // 调用重载的赋值运算符，执行深拷贝操作

  cout << *(p1.m_Age) << endl;  // 输出p1的年龄
  cout << *(p2.m_Age) << endl;  // 输出p2的年龄
  cout << *(p3.m_Age) << endl;  // 输出p3的年龄
}

int main(void) {    // 主函数
  test1();          // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}