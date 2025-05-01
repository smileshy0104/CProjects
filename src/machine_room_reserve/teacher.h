#pragma once
// 防止头文件被重复包含

#include <iostream>
#include <string>
#include <vector>

// 引入自定义头文件
#include "identity.h"   // 基类 Identity 的定义
#include "orderFile.h"  // 预约记录相关类
using namespace std;

// 教师类，继承自身份抽象基类 Identity
class Teacher : public Identity {
 public:
  // 默认构造函数（用于创建无初始数据的教师对象）
  Teacher();

  // 有参构造函数（用于初始化职工号、姓名、密码）
  Teacher(int empId, string name, string pwd);

  // 菜单操作接口（重写父类纯虚函数）
  virtual void operMenu();

  // 查看所有预约记录
  void showAllOrder();

  // 审核预约（批准或拒绝学生提交的预约申请）
  void validOrder();

  // 教师职工号属性
  int m_EmpId;
};