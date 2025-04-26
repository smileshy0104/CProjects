#include <iostream>
using namespace std;
double pi = 3.14;
// class 代表设计一个类，类后面紧跟着的就是类名称
class Circle {
  // 访问权限
  // 公共权限
 public:
  // 属性
  // 半径
  int c_r;
  // 行为
  // 获取圆的周长
  double calculateZC() { return 2 * pi * c_r; }
};
int main(void) {
  // 通过圆类创建具体的圆(对象)
  // 实例化——通过一个类创建一个对象的过程
  Circle c1;
  // 给圆对象的属性进行赋值
  c1.c_r = 10;
  cout << "圆的周长为" << c1.calculateZC() << endl;

  return 0;
}
