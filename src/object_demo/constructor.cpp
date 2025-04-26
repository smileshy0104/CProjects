#include <iostream>
using namespace std;
class Person {
 public:
  Person() {
    // 不写的也会自动创建一个，只不过里面是空的
    cout << "构造函数的调用" << endl;
  }
};
void test01() {
  Person p;  // 创建了一个对象但是没有调用这个函数
}
int main(void) {
  test01();
  system("pause");
  return 0;
}