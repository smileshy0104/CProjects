#include <iostream>   // 引入输入输出流库
#include <string>     // 引入字符串库
using namespace std;  // 使用标准命名空间

class Person {  // 定义一个名为Person的类
 public:
  // 重载==运算符，用于比较两个Person对象是否相等
  bool operator==(Person &p) {
    if (this->m_Name == p.m_Name &&
        this->m_Age == p.m_Age) {  // 比较姓名和年龄是否相等
      return true;                 // 如果相等，返回true
    } else {
      return false;  // 否则返回false
    }
  }

  // 重载!=运算符，用于比较两个Person对象是否不相等
  bool operator!=(Person &p) {
    if (this->m_Name == p.m_Name &&
        this->m_Age == p.m_Age) {  // 比较姓名和年龄是否相等
      return false;                // 如果相等，返回false
    } else {
      return true;  // 否则返回true
    }
  }

  // 构造函数，初始化成员变量m_Name和m_Age
  Person(string name, int age) {
    m_Name = name;  // 初始化姓名
    m_Age = age;    // 初始化年龄
  }

  string m_Name;  // 成员变量：姓名
  int m_Age;      // 成员变量：年龄
};

void test() {             // 测试函数
  Person p1("张三", 20);  // 创建Person对象p1，姓名为"张三"，年龄为20
  Person p2("张三", 20);  // 创建Person对象p2，姓名为"张三"，年龄为20

  // 判断p1和p2是否相等
  if (p1 == p2) {                      // 调用重载的==运算符
    cout << "p1和p2是相等的" << endl;  // 如果相等，输出提示信息
  } else {
    cout << "p1和p2是不相等的" << endl;  // 否则输出不相等的信息
  }

  // 判断p1和p2是否不相等
  if (p1 != p2) {                        // 调用重载的!=运算符
    cout << "p1和p2是不相等的" << endl;  // 如果不相等，输出提示信息
  } else {
    cout << "p1和p2是相等的" << endl;  // 否则输出相等的信息
  }
}

int main(void) {    // 主函数
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}