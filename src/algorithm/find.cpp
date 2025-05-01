#include <algorithm>   // 提供 find 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <string>      // 字符串支持
#include <vector>      // 使用 vector 容器
using namespace std;

// 定义一个 Person 类，表示一个人的信息
class Person {
 public:
  // 构造函数，初始化姓名和年龄
  Person(string name, int age) {
    this->m_Name = name;
    this->m_Age = age;
  }

  // 重载 == 运算符，用于 find 查找时判断两个 Person 对象是否“相等”
  bool operator==(const Person& p) {
    if (this->m_Age == p.m_Age && this->m_Name == p.m_Name) {
      return true;  // 姓名和年龄都相同才认为是同一个对象
    } else {
      return false;
    }
  }

  string m_Name;  // 姓名
  int m_Age;      // 年龄
};

// 测试查找内置数据类型（int）
void test01() {
  // 创建 vector<int> 容器，并插入 0~9
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);  // 插入元素
  }

  // 使用 find 查找值为 5 的元素
  vector<int>::iterator it = find(v.begin(), v.end(), 5);

  // 判断是否找到
  if (it == v.end()) {
    cout << "没找到" << endl;
  } else {
    cout << "找到: " << *it << endl;  // 输出找到的值
  }
}

// 测试查找自定义数据类型（Person）
void test02() {
  // 创建 vector<Person> 容器
  vector<Person> V;

  // 创建几个 Person 对象
  Person p1("1", 11);
  Person p2("2", 22);
  Person p3("3", 33);
  Person p4("4", 44);

  // 将对象添加到容器中
  V.push_back(p1);
  V.push_back(p2);
  V.push_back(p3);
  V.push_back(p4);

  // 使用 find 查找 p2 对象
  vector<Person>::iterator it = find(V.begin(), V.end(), p2);

  // 判断是否找到
  if (it == V.end()) {
    cout << "没找到" << endl;
  } else {
    cout << "找到: " << it->m_Name << " " << it->m_Age << endl;
  }
}

int main(void) {
  test01();  // 测试查找内置类型
  test02();  // 测试查找自定义类型

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}