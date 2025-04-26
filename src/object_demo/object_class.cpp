#include <iostream>   // 引入输入输出流库
#include <string>     // 引入字符串处理库
using namespace std;  // 使用标准命名空间

//* 类对象作为类成员
/*
**当其他类的对象作为本类的成员时，构造时先构造其他类的对象，再构造自身。**

析构呢？**与构造函数相反。**
**自身的析构函数先进行，之后其它类再进行。**
*/
// 定义一个表示手机的类 Phone
class Phone {
 public:
  // 构造函数，接受一个字符串参数 p 表示手机名称
  Phone(string p) {
    Phonename = p;                          // 初始化手机名称
    cout << "Phone的构造函数调用" << endl;  // 输出构造函数调用信息
  }

  // 析构函数
  ~Phone() {
    cout << "Phone的析构函数调用" << endl;  // 输出析构函数调用信息
  }

  string Phonename;  // 手机名称
};

// 定义一个表示人的类 Person
class Person {
 public:
  // 构造函数，接受两个字符串参数 name 和 pname 分别表示人名和手机名称
  // 使用——初始化列表进行成员变量的初始化
  Person(string name, string pname) : Personname(name), Personphone(pname) {
    cout << "Person的构造函数调用" << endl;  // 输出构造函数调用信息
  }

  // 析构函数
  ~Person() {
    cout << "Person的析构函数调用" << endl;  // 输出析构函数调用信息
  }

  string Personname;  // 人名
  Phone Personphone;  // 手机对象（会先调用 Phone 的构造函数）
};

// 测试函数
void test() {
  // 创建一个 Person 对象 p，名字为 "张三"，手机品牌为 "华为"
  Person p("张三", "华为");

  // 输出该人的名字
  cout << p.Personname << endl;

  // 输出该人所拥有的手机的品牌
  cout << p.Personphone.Phonename << endl;
}

int main(void) {
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回0表示程序正常结束
}