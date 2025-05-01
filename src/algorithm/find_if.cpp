#include <algorithm>   // 提供 find_if、sort 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <string>      // 字符串支持
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义一元谓词类：用于判断整数是否大于5
class GreaterFive {
 public:
  // 重载 () 运算符，使其可以像函数一样调用
  bool operator()(int val) {
    return val > 5;  // 如果 val 大于5，返回 true
  }
};

// 测试查找内置数据类型 int
void test01() {
  // 创建一个 vector<int> 容器，并插入 0~9
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);  // 插入元素
  }

  // 使用 find_if 查找第一个大于5的元素
  vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

  // 判断是否找到符合条件的元素
  if (it == v.end()) {
    cout << "没找到" << endl;
  } else {
    cout << "找到了: " << *it << endl;  // 输出第一个大于5的值（应该是6）
  }
}

// 自定义 Person 类，表示一个人的信息
class Person {
 public:
  // 构造函数，初始化姓名和年龄
  Person(string name, int age) {
    this->m_Name = name;
    this->m_Age = age;
  }

  string m_Name;  // 姓名
  int m_Age;      // 年龄
};

// 自定义一元谓词类：用于判断 Person 对象的年龄是否大于20
class Greater20 {
 public:
  // 接收一个 Person 引用作为参数
  bool operator()(Person& p) {
    return p.m_Age > 20;  // 如果年龄大于20，返回 true
  }
};

// 测试查找自定义数据类型 Person
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

  // 使用 find_if 查找第一个年龄大于20的 Person 对象
  vector<Person>::iterator it = find_if(V.begin(), V.end(), Greater20());

  // 判断是否找到
  if (it == V.end()) {
    cout << "没找到" << endl;
  } else {
    cout << "找到了: " << it->m_Name << " 年龄: " << it->m_Age << endl;
  }
}

int main(void) {
  test01();  // 测试查找内置类型
  test02();  // 测试查找自定义类型

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}