#include <iostream>
#include <string>
using namespace std;
/*
访问权限有三种
1、public——公共权限——成员类内可以访问，类外可以访问
2、protected–保护权限——成员类内可以访问，类外不可以访问
3、private——私有权限——成员类内可以访问，类外不可以访问
*/
class Person {
 public:
  string p_name;

 protected:
  string p_car;

 private:
  int p_password;

 public:
  void funcshow() {
    p_name = "张三";
    p_car = "拖拉机";
    p_password = 123456;
    cout << p_name << endl;
    cout << p_car << endl;
    cout << p_password << endl;
  }
};

int main(void) {
  Person p1;
  p1.p_name = "王五";
  p1.funcshow();
  // p1.p_car = "GTR";  // protected类外无法访问
  // p1.p_password = 123;// private类外无法访问
  return 0;
}
