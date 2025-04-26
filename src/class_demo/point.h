#pragma once
#include <iostream>
using namespace std;
class Point {
 public:
  void setx(int x);
  int getx();
  void sety(int y);
  int gety();

 private:
  int c_x;
  int c_y;
};
