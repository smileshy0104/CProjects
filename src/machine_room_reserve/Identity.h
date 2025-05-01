#pragma once
// 防止头文件被重复包含

#include <iostream>
#include <string>
using namespace std;

// 身份抽象基类
class Identity {
 public:
  // 操作菜单——纯虚函数
  virtual void operMenu() = 0;

  // 用户名属性
  string m_UserName;

  // 用户密码属性
  string m_UserPassword;
};