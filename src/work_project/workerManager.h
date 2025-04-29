#pragma once  // 防止头文件重复包含

#include <fstream>   // 引入文件流库，用于文件操作
#include <iostream>  // 引入输入输出流库
#include <string>    // 引入字符串库

#include "boss.h"      // 引入Boss类的定义
#include "employee.h"  // 引入Employee类的定义
#include "manager.h"   // 引入Manager类的定义
#include "worker.h"    // 引入Worker类的定义

#define FILENAME "test.txt"  // 定义文件名常量

using namespace std;  // 使用标准命名空间

class WorkerManager {
 public:
  // 构造函数
  WorkerManager();  // 初始化管理器对象

  // 展示菜单
  void Show_Menu();  // 显示系统菜单

  // 退出程序
  void ExitSystem();  // 退出系统并保存数据

  // 记录职工人数
  int m_EmpNum;  // 当前职工人数

  // 职工数组指针
  Worker** m_EmpArray;  // 动态数组，存储所有职工对象的指针

  // 添加职工
  void AddEmp();  // 添加新职工

  // 保存文件
  void SaveFile();  // 将职工信息保存到文件中

  // 判断文件是否为空标志
  bool m_FileIsEmpty;  // 标识文件是否为空

  // 统计文件中的人数
  int Get_EmpNum();  // 获取文件中记录的职工人数

  // 初始化职工
  void Init_Emp();  // 初始化职工信息

  // 显示职工
  void Show_Emp();  // 显示所有职工的信息

  // 判断职工是否存在
  int IsExist(int id);  // 判断指定ID的职工是否存在

  // 删除职工
  void Del_Emp();  // 删除指定ID的职工

  // 修改职工
  void Mod_Emp();  // 修改指定ID的职工信息

  // 查找职工
  void Find_Emp();  // 查找指定条件的职工

  // 员工排序
  void Sort_Emp();  // 按照指定条件对职工进行排序

  // 清空数据
  void Clean_File();  // 清空文件中的所有数据

  // 析构函数
  ~WorkerManager();  // 释放资源并清理动态分配的内存
};