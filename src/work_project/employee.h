#pragma once
#include <iostream>

#include "worker.h"
using namespace std;

// 普通职工类
class Employee : public Worker {  // 定义普通职工类Employee，继承自Worker抽象类
  // 子类重写父类的虚函数或纯虚函数时，注意区分函数的声明和定义
 public:
  // 构造函数   // 声明构造函数，用于初始化职工的属性
  Employee(int id, string name, int deptid);

  // 显示个人信息   // 子类重写父类的虚函数或纯虚函数，virtual关键字可加可不加
  virtual void ShowInfo();

  // 获取岗位名称  // 子类重写父类的虚函数或纯虚函数，virtual关键字可加可不加
  virtual string GetDeptName();
};