#include <algorithm>   // 提供 count_if、sort 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义一元谓词类：用于判断整数是否大于20
class Greater20 {
 public:
  // 重载 () 运算符，使其可以像函数一样调用
  bool operator()(int val) {
    return val > 20;  // 如果 val 大于20，返回 true
  }
};

// 测试查找内置数据类型 int 的条件统计
void test01() {
  // 创建一个 vector<int> 容器，并插入一些整数
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(40);
  v.push_back(30);
  v.push_back(50);

  // 使用 count_if 统计满足条件（大于20）的元素个数
  int num = count_if(v.begin(), v.end(), Greater20());

  // 输出结果
  cout << "大于20的数字有：" << num << " 个" << endl;
  // 示例输出应为 3（40,30,50）
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
class AgeGreater20 {
 public:
  // 接收一个 const Person& 引用作为参数
  bool operator()(const Person& p) {
    return p.m_Age > 20;  // 如果年龄大于20，返回 true
  }
};

// 测试查找自定义数据类型 Person 的条件统计
void test02() {
  // 创建 vector<Person> 容器
  vector<Person> v;

  // 创建几个 Person 对象
  Person p1("s1", 11);
  Person p2("s2", 22);
  Person p3("s3", 33);
  Person p4("s4", 44);

  // 将对象添加到容器中
  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);
  v.push_back(p4);

  // 使用 count_if 查找年龄大于20的人的数量
  int num = count_if(v.begin(), v.end(), AgeGreater20());

  // 输出结果
  cout << "年龄大于20的人有：" << num << " 人" << endl;
  // 示例输出应为 3（22,33,44）
}
int main(void) {
  test01();
  test02();
  system("pause");
  return 0;
}
