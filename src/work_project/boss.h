#pragma once  // 防止头文件重复包含

#include <iostream>  // 引入输入输出流库
#include <string>    // 引入字符串库

#include "worker.h"   // 引入Worker类的定义
using namespace std;  // 使用标准命名空间

// 老板类
class Boss : public Worker {  // 定义老板类Boss，继承自Worker抽象类
 public:
  // 构造函数
  Boss(int id, string name, int deptid);  // 声明构造函数，用于初始化老板的属性

  // 显示个人信息    // 子类重写父类的虚函数或纯虚函数，virtual关键字可加可不加
  virtual void ShowInfo();

  // 获取岗位名称     // 子类重写父类的虚函数或纯虚函数，virtual关键字可加可不加
  virtual string GetDeptName();
};