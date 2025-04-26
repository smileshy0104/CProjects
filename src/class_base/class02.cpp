#include <iostream>
#include <string>
using namespace std;
/*
类中的属性和行为，我们统称为成员
1、属性-成员属性-成员变量
2、行为-成员函数-成员方法
*/
class Student {
 public:
  string s_Name;
  int s_Id;
  void showStudent() { cout << "姓名： " << s_Name << "ID：" << s_Id << endl; }
  // 赋值
  void inputName(string name) { s_Name = name; }
};

int main(void) {
  Student s1;
  // s1.s_Name = "张三";
  s1.inputName("赵六");
  s1.s_Id = 123456;
  s1.showStudent();
  return 0;
}
