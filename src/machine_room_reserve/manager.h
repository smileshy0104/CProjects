#pragma once
// 防止头文件重复包含

#include <algorithm>  // 提供 find、sort 等算法支持
#include <fstream>    // 文件流支持（读写文件）
#include <iostream>   // 输入输出流库
#include <string>     // 字符串支持
#include <vector>     // 使用 vector 容器

// 引入自定义头文件
#include "computerRoom.h"  // 机房信息类
#include "globalFile.h"    // 全局常量文件（如文件名、状态常量等）
#include "identity.h"      // 身份抽象基类
#include "student.h"       // 学生类
#include "teacher.h"       // 教师类
using namespace std;

// 管理员类，继承自身份抽象基类 Identity
class Manager : public Identity {
 public:
  // 默认构造函数（用于创建无初始数据的管理员对象）
  Manager();

  // 有参构造函数（用于初始化用户名和密码）
  Manager(string name, string pwd);

  // 菜单操作接口（重写父类纯虚函数）
  virtual void operMenu();

  // 添加账号（学生或教师）
  void addPerson();

  // 查看所有账号（学生和教师）
  void showPerson();

  // 查看机房信息
  void showComputer();

  // 清空预约记录（用于每月或学期初重置系统）
  void cleamFile();

  // 初始化容器（从文件加载学生、教师、机房信息到内存）
  void initVector();

  // 学生容器：存储系统中的所有学生信息
  vector<Student> vStu;

  // 教师容器：存储系统中的所有教师信息
  vector<Teacher> vTea;

  // 检测重复 ID（学号或职工号）并判断是否已存在
  // type: 1 表示学生，2 表示教师
  bool checkRepeat(int id, int type);

  // 机房信息容器：存储可用的机房信息
  vector<computerRoom> vCom;
};