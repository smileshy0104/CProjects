#pragma once  // 防止头文件重复包含

#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间
#include <string>     // 引入字符串库

// 职工的抽象类
class Worker {
 public:
  // 显示个人信息
  // 纯虚函数，要求所有派生类必须实现该函数
  virtual void ShowInfo() = 0;

  // 获取岗位名称
  // 纯虚函数，要求所有派生类必须实现该函数
  virtual string GetDeptName() = 0;

  // 职工编号
  int m_Id;

  // 职工姓名
  string m_Name;

  // 部门编号
  int m_DeptId;
};