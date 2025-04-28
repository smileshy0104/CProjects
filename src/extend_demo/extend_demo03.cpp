#include <iostream>
using namespace std;
// 继承中的对象模型
class Base {
 public:
  int m_A;

 protected:
  int m_B;

 private:
  int m_C;
};
class Son : public Base {
 public:
  int m_D;
};
void test01() {
  // 父类中所有的非静态成员属性都会被子类继承下去
  // 父类中私有的成员属性是被编译器给隐藏了，因此访问不到，但是确实被继承下去了
  cout << "sizeof of son:" << sizeof(Son) << endl;  // 结果是16 = 12 + 4
  Son son;
  son.m_A = 10;
  // son.m_B = 20;   // 保护权限的内容在类外无法访问
  // son.m_C = 30;  // 私有权限的内容在类外无法访问
  son.m_D = 40;
}
int main(void) {
  test01();
  system("pause");
  return 0;
}
