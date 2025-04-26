#include <iostream>
using namespace std;
class Person {
 public:
  Person() { cout << "构造函数的调用" << endl; }
  ~Person() { cout << "析构函数的调用" << endl; }
  // TODO
  // 构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
};
void test01() {
  Person p;  // 在栈上的数据，test01执行完之后会释放这个对象
}
int main(void) {
  test01();
  // Person p;在main函数中析构函数也会被调用在按完任意键之后
  system("pause");
  return 0;
}
