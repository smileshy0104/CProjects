#include <iostream>
using namespace std;
class Person {
 public:
  // 构造函数
  // 构造函数-无参构造-编译器提供的就是无参的
  Person() { cout << "Person的无参构造函数调用" << endl; }
  // 构造函数-有参构造
  Person(int a) {
    // 将传入的人身上的所有属性，拷贝到我身上。
    age = a;
    cout << "Person的有参构造函数调用" << endl;
  }
  // 析构函数
  ~Person() { cout << "Person的析构函数调用" << endl; }
  //////////////
  // 拷贝构造函数
  Person(const Person &p) {
    age = p.age;
    cout << "拷贝构造函数调用" << endl;
  }
  int age;
};
int main(void) {
  Person p;  // 默认构造函数调用  // 无参构造函数调用(不用家括号)
  ///*注意：使用默认构造函数的时候，不要加(),编译器会认为这是一个函数的声明
  // 例如：Person p1();不会认为在创建对象*/
  Person p2(10);  // 有参构造函数调用
  Person p3(p2);  // 拷贝构造函数调用
  cout << "p2的年龄为" << p2.age << endl;
  cout << "p3的年龄为" << p3.age << endl;

  cout << "---------------------------显示法-----------------------------------"
       << endl;
  // 显示法
  // Person p1;               // 无参
  // Person p2 = Person(10);  // 有参
  // Person p3 = Person(p2);  // 拷贝
  // 如果把等号右边的式子单独拿出来
  // Person(10)这是一个匿名对象-特点——当前行执行结束后，系统会立即回收掉匿名对象
  // 注意：不要利用拷贝函数初始化匿名对象-编译器会认为Person(p3) == Person p3
  /// 编译器会认为是对象的声明 /Person(p3)

  cout << "---------------------------隐式转换法-------------------------------"
       << endl;
  // 隐式转换法
  Person p4 = 10;  // 相当与Person p4 = Person(10);
  Person p5 = p4;  // 拷贝构造
  system("pause");
  return 0;
}