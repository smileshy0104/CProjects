#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

// 定义一个表示点的类 Point
class Point {
 public:
  void setx(int x) { c_x = x; }  // 设置点的 x 坐标
  int getx() { return c_x; }     // 获取点的 x 坐标
  void sety(int y) { c_y = y; }  // 设置点的 y 坐标
  int gety() { return c_y; }     // 获取点的 y 坐标

 private:
  int c_x;  // 点的 x 坐标
  int c_y;  // 点的 y 坐标
};

// 定义一个表示圆的类 Circle
class Circle {
 public:
  void setr(int r) { c_R = r; }                        // 设置圆的半径
  int getr() { return c_R; }                           // 获取圆的半径
  void setcenter(Point center) { c_center = center; }  // 设置圆的中心点
  Point getcenter() { return c_center; }               // 获取圆的中心点

 private:
  int c_R;         // 圆的半径
  Point c_center;  // 圆的中心点
};

// 判断点是否在圆内、圆上或圆外的函数
void isInCircle(Circle &c, Point &p) {
  // 计算点到圆心的距离平方
  int distance =
      (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
      (c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());
  // 计算圆的半径平方
  int rdistance = c.getr() * c.getr();

  // 根据距离平方与半径平方的关系判断点的位置
  if (distance == rdistance) {
    cout << "点在圆上" << endl;  // 如果相等，则点在圆上
  } else if (distance > rdistance) {
    cout << "点在圆外" << endl;  // 如果大于，则点在圆外
  } else {
    cout << "点在圆内" << endl;  // 如果小于，则点在圆内
  }
}

int main(void) {
  Circle c1;    // 创建一个圆对象
  c1.setr(10);  // 设置圆的半径为 10

  Point center;          // 创建一个点对象作为圆心
  center.setx(10);       // 设置圆心的 x 坐标为 10
  center.sety(10);       // 设置圆心的 y 坐标为 10
  c1.setcenter(center);  // 将点设置为圆的中心

  Point p1;    // 创建一个点对象
  p1.setx(3);  // 设置点的 x 坐标为 3
  p1.sety(4);  // 设置点的 y 坐标为 4

  // 调用函数判断点是否在圆内、圆上或圆外
  isInCircle(c1, p1);

  return 0;  // 程序正常结束
}