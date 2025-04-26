#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

//* this指针指向被调用的成员函数所属的对象
/*
**this指针的用途**

- **当形参和成员变量同名时，可用this指针来区分**
- **在类的非静态成员函数中返回对象本身，可使用return *thi
*/
class Person {
 public:
  // 构造函数，接受一个整型参数 age
  Person(int age) {
    // this指针指向的是被调用函数的成员函数所属的对象
    // 这里指向的就是当前创建的对象 p
    this->age = age;  // 使用 this 指针区分成员变量 age 和构造函数参数 age
  }

  // 返回对象本身的方法
  // 注意：返回值如果是Person，就会创建一个新的对象并返回，而不是返回当前对象本身。
  // 使用引用返回(*this)，可以避免创建新对象，————直接返回当前对象的引用。
  Person& PersonAddPerson(Person& p) {
    this->age += p.age;  // 将传入对象 p 的 age 值加到当前对象的 age 上
    return *this;        // 返回当前对象的引用，支持链式调用
  }

  int age;  // 成员变量 age，注意命名规范也可以解决名字冲突的问题
};

// 测试解决对象冲突
void test() {
  Person p(18);           // 创建一个 Person 对象 p，初始化年龄为 18
  cout << p.age << endl;  // 输出 p 的年龄
}

// 测试返回对象本身用 *this
void test01() {
  Person p1(10);  // 创建一个 Person 对象 p1，初始化年龄为 10
  Person p2(10);  // 创建一个 Person 对象 p2，初始化年龄为 10

  // 调用 PersonAddPerson 方法，将 p1 的年龄加到 p2 上
  p2.PersonAddPerson(p1);

  cout << p2.age << endl;  // 输出 p2 的年龄
  // 链式编程思想：通过返回当前对象的引用 (*this)，可以连续调用方法
  // 将 p1 的年龄再次加到 p2 上
  p2.PersonAddPerson(p1).PersonAddPerson(p1);

  cout << p2.age << endl;  // 输出最终 p2 的年龄
}

int main(void) {
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回0表示程序正常结束
}