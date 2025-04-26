#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间
//* 空指针返回成员函数
/*
C++中**空指针也是可以调用成员函数的**，但是也要注意有没有用到this指针，**如果用到this指针，需要加以判断来保证代码的健壮性。**
*/
class Person {
 public:
  // 显示类名的方法
  void ShowClassName() {
    cout << "this is Person class" << endl;  // 输出类名信息
  }

  // 显示年龄的方法，并增加健壮性检查
  void ShowPersonAge() {
    // 提高健壮性，空指针直接返回，防止代码崩溃
    if (this == NULL) {
      return;  // 如果 this 指针为空（即对象指针为
               // NULL），则直接返回，避免访问空指针
    }

    // 报错原因是因为传入的指针是 NULL——无中生有，用一个空指针访问里面的属性
    cout << this->m_Age << endl;  // 输出成员变量 m_Age 的值
  }

  int m_Age;  // 成员变量 m_Age 存储年龄
};

// 测试函数
void test() {
  Person* p = NULL;  // 创建一个指向 Person 类型的空指针 p

  // 调用 ShowClassName 方法
  // 注意：即使 p
  // 是空指针，调用非虚函数时不会崩溃，因为编译器在编译时已经确定了函数地址
  p->ShowClassName();

  // 调用 ShowPersonAge 方法
  // 这里可能会导致崩溃，因为试图通过空指针访问成员变量 m_Age
  p->ShowPersonAge();
}

int main(void) {
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回0表示程序正常结束
}