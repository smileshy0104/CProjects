#include <iostream>  // 输入输出流库
#include <set>       // set 容器头文件
#include <string>    // 字符串支持
using namespace std;

//* 对于自定义数据类型，set必须指定排序规则才可以插入数据。

// 定义 Person 类，表示一个人的信息（姓名和年龄）
class Person {
 public:
  // 构造函数
  Person(string name, int age) {
    this->m_Name = name;  // 初始化姓名
    this->m_Age = age;    // 初始化年龄
  }

  string m_Name;  // 姓名
  int m_Age;      // 年龄
};

// 自定义比较类 Mycompare，用于设置 set 的排序规则
class Mycompare {
 public:
  // 重载 () 运算符，使其可以作为排序依据
  // 按照年龄从大到小排序（降序）
  bool operator()(const Person& p1, const Person& p2) const {
    return p1.m_Age > p2.m_Age;  // 如果 p1 的年龄更大，则排在前面
  }
};

void test01() {
  // 创建一个 set 容器，存储 Person 对象，并使用自定义比较类 Mycompare 排序
  set<Person, Mycompare> s1;

  // 创建几个 Person 对象
  Person p1("s1", 11);
  Person p2("s2", 22);
  Person p3("s3", 33);
  Person p4("s4", 44);

  // 将 Person 对象插入 set 中
  s1.insert(p1);
  s1.insert(p2);
  s1.insert(p3);
  s1.insert(p4);

  // 遍历 set 容器并打印其中的元素
  for (set<Person, Mycompare>::iterator it = s1.begin(); it != s1.end(); it++) {
    cout << "姓名：" << it->m_Name << "，年龄：" << it->m_Age << endl;
  }
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 系统）
  return 0;         // 返回 0 表示程序正常结束
}