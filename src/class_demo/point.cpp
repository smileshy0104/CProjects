#include "point.h"
// Point::告诉编译器这是Point作用域下面的一个成员函数
void Point::setx(int x) { c_x = x; }
int Point::getx() { return c_x; }
void Point::sety(int y) { Point::c_y = y; }
int Point::gety() { return c_y; }
