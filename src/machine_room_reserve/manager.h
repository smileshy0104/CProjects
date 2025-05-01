#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "computerRoom.h"
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
using namespace std;

class Manager : public Identity {
 public:
  // 默认构造
  Manager();

  // 有参构造
  Manager(string name, string pwd);

  // 菜单
  virtual void operMenu();

  // 添加账号
  void addPerson();

  // 查看账号
  void showPerson();

  // 查看机房信息
  void showComputer();

  // 清空预约记录
  void cleamFile();

  // 初始化容器
  void initVector();

  // 学生容器
  vector<Student> vStu;

  // 教师容器
  vector<Teacher> vTea;

  // 检测重复 学号、职工号  检测类型
  bool checkRepeat(int id, int type);

  // 机房信息
  vector<computerRoom> vCom;
};
