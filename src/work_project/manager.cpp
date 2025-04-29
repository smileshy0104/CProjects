#include "manager.h"  // 引入Manager类的定义

// 构造函数
Manager::Manager(int id, string name, int deptid) {  // Manager类的构造函数
  this->m_Id = id;                                   // 初始化职工编号
  this->m_Name = name;                               // 初始化职工姓名
  this->m_DeptId = deptid;                           // 初始化部门编号
}

// 显示个人信息
void Manager::ShowInfo() {  // 实现父类中的纯虚函数ShowInfo()
  cout << "职工编号:" << this->m_Id
       << "\t职工姓名:" << this->m_Name     // 输出职工编号和姓名
       << "\t岗位:" << this->GetDeptName()  // 调用GetDeptName()获取岗位名称
       << "\t岗位职责:完成老板交个任务，并且下发任务给普通员工"
       << endl;  // 输出岗位职责
}

// 获取岗位名称
string Manager::GetDeptName() {  // 实现父类中的纯虚函数GetDeptName()
  return string("经理");         // 返回岗位名称为“经理”
}