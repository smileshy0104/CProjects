#include "Person.hpp"  // 包含 Person 类模板的头文件

#include <iostream>  // 包含输入输出流库，用于控制台输入输出
using namespace std;

#include <string>  // 包含字符串库，用于处理字符串

//* 主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp
void test01() {
  // 创建一个 Person 对象，姓名为字符串 "伞兵"，年龄为整数 18
  Person<string, int> p1("伞兵", 18);
  p1.showPerson();  // 调用 showPerson 函数显示信息
}

int main(void) {
  test01();         // 调用 test01 函数进行测试
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}