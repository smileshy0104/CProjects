#include <algorithm>   // 提供 count、sort 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <string>      // 字符串支持
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义 Person 类，表示一个人的信息
class Person {
 public:
  // 构造函数，初始化姓名和年龄
  Person(string name, int age) {
    this->m_Name = name;
    this->m_Age = age;
  }

  // 重载 == 运算符，用于 count 比较两个 Person 对象是否“相等”
  bool operator==(const Person& p) {
    if (this->m_Age == p.m_Age) {
      return true;  // 只比较年龄是否相同
    } else {
      return false;
    }
  }

  string m_Name;  // 姓名
  int m_Age;      // 年龄
};

// 测试函数：统计内置数据类型 int 的出现次数
void test01() {
  // 创建一个 vector<int> 容器，并插入一些整数
  vector<int> v;
  v.push_back(10);
  v.push_back(10);
  v.push_back(40);
  v.push_back(20);
  v.push_back(30);

  // 使用 count 查找值为 10 的元素出现的次数
  int num = count(v.begin(), v.end(), 10);

  // 输出结果
  cout << "数字10出现的次数为：" << num << endl;  // 应该输出 2
}

// 测试函数：统计自定义数据类型 Person 的出现次数
void test02() {
  // 创建 vector<Person> 容器
  vector<Person> v;

  // 创建几个 Person 对象
  Person p1("s1", 11);
  Person p2("s2", 12);
  Person p3("s3", 13);
  Person p4("s4", 14);
  Person p5("s5", 14);  // 注意：p4 和 p5 年龄相同

  // 将对象添加到容器中
  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);
  v.push_back(p4);
  v.push_back(p5);

  // 使用 count 查找与 p5 相等的对象个数
  // 因为 Person 重载了 == 运算符，只比较年龄，所以会找到所有年龄相同的对象
  int num = count(v.begin(), v.end(), p5);

  // 输出结果
  cout << "年龄为 " << p5.m_Age << " 的人出现了 " << num << " 次" << endl;
  // 输出应为 2（p4 和 p5）
}
int main(void) {
  test01();
  test02();
  system("pause");
  return 0;
}
