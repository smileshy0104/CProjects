#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

// 定义一个表示立方体的类 Cube
class Cube {
 public:
  // 设置和获取长度的方法
  void setl(int l) { C_L = l; }  // 设置长度
  int getl() { return C_L; }     // 获取长度

  // 设置和获取宽度的方法
  void setw(int w) { C_W = w; }  // 设置宽度
  int getw() { return C_W; }     // 获取宽度

  // 设置和获取高度的方法
  void seth(int h) { C_H = h; }  // 设置高度
  int geth() { return C_H; }     // 获取高度

  // 计算立方体表面积的方法
  int calculateS() {
    return 2 * C_L * C_W + 2 * C_L * C_H + 2 * C_W * C_H;  // 表面积公式
  }

  // 计算立方体体积的方法
  int calculateV() {
    return C_L * C_W * C_H;  // 体积公式
  }

  // 判断两个立方体是否相等的成员函数
  bool issamebyClass(Cube &c) {
    if (C_H == c.geth() && C_L == c.getl() &&
        C_W == c.getw()) {  // 比较三个维度
      return true;
    }
    return false;
  }

 private:
  int C_L;  // 长度
  int C_W;  // 宽度
  int C_H;  // 高度
};

// 全局函数，用于判断两个立方体是否相等
bool issame(Cube &c1, Cube &c2) {
  if (c1.geth() == c2.geth() && c1.getl() == c2.getl() &&
      c1.getw() == c2.getw()) {  // 比较三个维度
    return true;
  }
  return false;
}

int main(void) {
  Cube c1;      // 创建第一个立方体对象
  c1.seth(10);  // 设置高度为10
  c1.setl(10);  // 设置长度为10
  c1.setw(10);  // 设置宽度为10

  cout << c1.calculateS() << endl;  // 输出立方体的表面积
  cout << c1.calculateV() << endl;  // 输出立方体的体积

  Cube c2;      // 创建第二个立方体对象
  c2.seth(10);  // 设置高度为10
  c2.setl(10);  // 设置长度为10
  c2.setw(10);  // 设置宽度为10

  // 使用全局函数判断两个立方体是否相等
  bool ret = issame(c1, c2);
  if (ret) {
    cout << "c1和c2相等" << endl;  // 如果相等，输出提示信息
  } else {
    cout << "c1和c2不相等" << endl;  // 如果不相等，输出提示信息
  }

  // 使用成员函数判断两个立方体是否相等
  bool ret2 = c1.issamebyClass(c2);
  if (ret2) {
    cout << "利用成员函数,c1和c2相等" << endl;  // 如果相等，输出提示信息
  } else {
    cout << "利用成员函数,c1和c2不相等" << endl;  // 如果不相等，输出提示信息
  }

  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回0表示程序正常结束
}