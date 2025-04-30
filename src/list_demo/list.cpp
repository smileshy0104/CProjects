#include <iostream>  // 控制台输入输出
#include <list>      // 使用 list 容器
#include <string>    // 字符串处理
using namespace std;

// 定义一个 Person 类，表示人员信息
class Person {
 public:
  Person(string name, int age, int height) {
    this->m_Name = name;      // 初始化姓名
    this->m_Age = age;        // 初始化年龄
    this->m_Height = height;  // 初始化身高
  }

  string m_Name;  // 姓名
  int m_Age;      // 年龄
  int m_Height;   // 身高
};

// 自定义排序规则：先按年龄升序，若年龄相同则按身高降序
bool comparePerson(Person& p1, Person& p2) {
  if (p1.m_Age == p2.m_Age) {
    // 年龄相同，按身高从高到低排序（降序）
    return p1.m_Height > p2.m_Height;
  } else {
    // 按年龄从小到大排序（升序）
    return p1.m_Age < p2.m_Age;
  }
}

void test01() {
  // 创建一个 list 容器，用于存储 Person 对象
  list<Person> L;

  // 创建6个 Person 对象
  Person p1("s11", 23, 166);
  Person p2("s12", 23, 156);
  Person p3("s13", 23, 178);
  Person p4("s14", 33, 172);
  Person p5("s15", 43, 190);
  Person p6("s16", 45, 175);

  // 将对象依次插入到 list 的末尾
  L.push_back(p5);
  L.push_back(p1);
  L.push_back(p4);
  L.push_back(p2);
  L.push_back(p6);
  L.push_back(p3);

  // 打印原始数据
  cout << "原始数据：" << endl;
  for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
    cout << it->m_Name << " 年龄: " << it->m_Age << " 身高: " << it->m_Height
         << endl;
  }

  cout << "排序后：" << endl;

  // 使用自定义排序规则对 list 进行排序
  L.sort(comparePerson);

  // 打印排序后的数据
  for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
    cout << it->m_Name << " 年龄: " << it->m_Age << " 身高: " << it->m_Height
         << endl;
  }
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（Windows 下有效）
  return 0;         // 程序正常结束
}