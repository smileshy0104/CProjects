#pragma once
// 防止头文件被重复包含

#include <fstream>   // 文件流支持（读写文件）
#include <iostream>  // 输入输出流库
#include <string>    // 字符串支持
#include <vector>    // 使用 vector 容器

// 引入自定义头文件
#include "computerRoom.h"  // 机房信息类
#include "globalFile.h"    // 全局常量文件（如文件名、状态常量等）
#include "identity.h"      // 身份抽象基类
#include "orderFile.h"     // 预约记录类
using namespace std;

// 学生类，继承自身份抽象基类 Identity
class Student : public Identity {
 public:
  // 默认构造函数（用于创建无初始数据的学生对象）
  Student();

  // 有参构造函数（用于初始化学号、姓名、密码）
  Student(int id, string name, string pwd);

  // 菜单操作接口（重写父类纯虚函数）
  virtual void operMenu();

  // 申请预约（向系统提交预约请求）
  void applyOrder();

  // 查看自己的预约记录
  void showMyOrder();

  // 查看所有预约记录（可能包括其他学生的预约）
  void showAllOrder();

  // 取消已提交的预约（在审核前）
  void cancelOrder();

  // 学号属性
  int m_Id;

  // 机房容器：存储可用的机房信息
  vector<computerRoom> vCom;
};