#include "MyArray.hpp"

#include <iostream>
#include <string>
using namespace std;

// 打印整型数组
void PrintArry(MyArray<int>& arr) {
  for (int i = 0; i < arr.getSize(); i++) {
    cout << arr[i] << endl;  // 输出数组中的每个元素
  }
}

// 测试 MyArray 类的基本功能
void test01() {
  MyArray<int> arr1(5);  // 创建一个容量为 5 的整型数组

  for (int i = 0; i < 5; i++) {
    // 利用尾插法向数组中插入数据
    arr1.PushBack(i);  // 插入数据 0 到 4
  }

  cout << "arr1的打印输出" << endl;
  PrintArry(arr1);                                       // 打印 arr1 的内容
  cout << "arr1的容量为" << arr1.getCapacity() << endl;  // 输出 arr1 的容量
  cout << "arr1的大小为" << arr1.getSize() << endl;      // 输出 arr1 的大小

  cout << "arr2的打印输出" << endl;
  MyArray<int> arr2(arr1);  // 使用拷贝构造函数创建 arr2
  PrintArry(arr2);          // 打印 arr2 的内容

  // 尾删
  arr2.PopBack();  // 删除 arr2 的最后一个元素
  cout << "arr2尾删后" << endl;
  cout << "arr2的容量为" << arr2.getCapacity() << endl;  // 输出 arr2 的容量
  cout << "arr2的大小为" << arr2.getSize() << endl;      // 输出 arr2 的大小
  PrintArry(arr2);                                       // 打印 arr2 的内容

  MyArray<int> arr3(100);
  arr3 = arr1;                                           // 使用赋值运算符
  cout << "arr3的容量为" << arr3.getCapacity() << endl;  // 输出 arr3 的容量
  cout << "arr3的大小为" << arr3.getSize() << endl;      // 输出 arr3 的大小
  PrintArry(arr3);                                       // 打印 arr3 的内容
}

// 自定义数据类型 Person
class Person {
 public:
  Person() {}  // 默认构造函数
  Person(string name, int age) {
    this->m_Name = name;  // 初始化姓名
    this->m_Age = age;    // 初始化年龄
  }
  string m_Name;  // 姓名
  int m_Age;      // 年龄
};

// 打印 Person 类型的数组
void PrintPersonArry(MyArray<Person>& arr) {
  for (int i = 0; i < arr.getSize(); i++) {
    cout << "姓名: " << arr[i].m_Name << ", 年龄: " << arr[i].m_Age
         << endl;  // 输出每个 Person 对象的信息
  }
}

// 测试 MyArray 类处理自定义数据类型
void test02() {
  MyArray<Person> arr(10);  // 创建一个容量为 10 的 Person 数组

  Person p1("伞兵1", 21);
  Person p2("伞兵2", 22);
  Person p3("伞兵3", 23);
  Person p4("伞兵4", 24);
  Person p5("伞兵5", 25);

  // 将数据插入到数组中
  arr.PushBack(p1);  // 插入 Person 对象 p1
  arr.PushBack(p2);  // 插入 Person 对象 p2
  arr.PushBack(p3);  // 插入 Person 对象 p3
  arr.PushBack(p4);  // 插入 Person 对象 p4
  arr.PushBack(p5);  // 插入 Person 对象 p5

  // 打印数组
  PrintPersonArry(arr);  // 打印 Person 数组的内容
  // 输出容量
  cout << "arr容量为" << arr.getCapacity() << endl;  // 输出数组的容量
  // 输出大小
  cout << "arr大小为" << arr.getSize() << endl;  // 输出数组的大小
}

int main(void) {
  test01();         // 测试整型数组
  test02();         // 测试自定义数据类型的数组
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}