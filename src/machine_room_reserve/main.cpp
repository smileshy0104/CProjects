#include <fstream>
#include <iostream>
#include <string>

#include "globalFile.h"
#include "identity.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"

using namespace std;

// 进入教师子菜单界面
void teacherMenu(Identity*& teacher) {
  while (1) {
    // 调用子菜单界面
    teacher->operMenu();

    // 将教师对象转换为Teacher类型，以便调用特定的成员函数
    Teacher* tea = (Teacher*)teacher;

    // 初始化选择变量
    int select = 0;

    // 从用户获取菜单选择输入
    cin >> select;

    // 根据用户选择执行对应的操作
    if (select == 1)  // 查看所有预约
    {
      tea->showAllOrder();
    } else if (select == 2)  // 审核预约
    {
      tea->validOrder();
    } else {
      // 注销教师对象并返回主菜单
      delete teacher;
      cout << "注销成功" << endl;
      system("pause");
      system("cls");
      return;
    }
  }
}

// 进入学生子菜单界面
void studentMenu(Identity*& student) {
  while (1) {
    // 调用学生子菜单
    student->operMenu();

    // 将学生身份指针转换为学生类指针以访问学生特定方法
    Student* stu = (Student*)student;

    int select = 0;
    cin >> select;  // 接收用户选择

    // 根据用户选择执行对应操作
    if (select == 1)  // 申请预约
    {
      stu->applyOrder();
    } else if (select == 2)  // 查看自身预约
    {
      stu->showMyOrder();
    } else if (select == 3)  // 查看所有人预约
    {
      stu->showAllOrder();
    } else if (select == 4)  // 取消预约
    {
      stu->cancelOrder();
    } else  // 注销登录
    {
      delete student;
      cout << "注销成功!" << endl;

      system("pause");
      system("cls");
      return;
    }
  }
}

// 进入管理员子菜单界面
void managerMenu(Identity*& manager) {
  while (1) {
    // 调用管理员子菜单
    manager->operMenu();

    // 将父类指针转为子类指针，调用子类里其他的接口
    Manager* man = (Manager*)manager;

    int select = 0;
    cin >> select;

    if (select == 1)  // 添加账号
    {
      // cout << "添加账号" << endl;
      man->addPerson();
    } else if (select == 2)  // 查看账号
    {
      // cout << "查看账号" << endl;
      man->showPerson();
    } else if (select == 3)  // 查看机房
    {
      // cout << "查看机房" << endl;
      man->showComputer();
    } else if (select == 4)  // 清空预约
    {
      // cout << "清空预约" << endl;
      man->cleamFile();
    } else {
      // 注销
      delete manager;  // 销毁堆区对象
      cout << "注销成功" << endl;
      system("pause");
      system("cls");
      return;
    }
  }
}

// 登录功能
void LoginIn(string fileName, int type) {
  Identity* person = NULL;  // 父类指针指向子类对象

  // 读文件
  ifstream ifs;
  // 打开文件
  ifs.open(fileName, ios::in);

  // 判断文件是否存在
  if (!ifs.is_open()) {
    cout << "文件不存在" << endl;
    ifs.close();
    return;
  }

  // 准备接受用户的信息
  int id = 0;
  string name;
  string pwd;

  // 判断身份
  if (type == 1) {
    cout << "请输入你的学号:" << endl;
    cin >> id;
  } else if (type == 2) {
    cout << "请输入你的职工号:" << endl;
    cin >> id;
  }

  cout << "请输入用户名:" << endl;
  cin >> name;
  cout << "请输入密码:" << endl;
  cin >> pwd;

  // 根据用户类型进行不同的身份验证
  if (type == 1) {
    // 学生身份验证
    int fId;
    string fName;
    string fPwd;
    // 循环读取文件中的数据
    while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
      // 与用户输入的信息做对比
      if (fId == id && fName == name && fPwd == pwd) {
        cout << "学生验证登录成功" << endl;
        system("pause");
        system("cls");

        person = new Student(id, name, pwd);
        // 进入学生身份的子菜单
        studentMenu(person);
        return;
      }
    }
  } else if (type == 2) {
    // 老师身份验证
    int fId;
    string fName;
    string fPwd;
    // 循环读取文件中的数据
    while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
      // 与用户输入的信息做对比
      if (fId == id && fName == name && fPwd == pwd) {
        cout << "老师验证登录成功" << endl;
        system("pause");
        system("cls");

        person = new Teacher(id, name, pwd);
        // 进入老师身份的子菜单
        teacherMenu(person);
        return;
      }
    }
  } else if (type == 3) {
    // 管理员身份验证
    string fName;
    string fPwd;
    // 循环读取文件中的数据
    while (ifs >> fName && ifs >> fPwd) {
      // 与用户输入的信息做对比
      if (fName == name && fPwd == pwd) {
        cout << "管理员验证登录成功" << endl;
        system("pause");
        system("cls");

        person = new Manager(name, pwd);
        // 进入管理员身份的子菜单
        managerMenu(person);
        return;
      }
    }
  }

  // 如果所有验证均失败
  cout << "验证登录失败！" << endl;
  system("pause");
  system("cls");
  return;
}

// 主函数
int main(void) {
  // 主循环，使程序持续运行直到用户选择退出
  while (1) {
    // 显示系统欢迎界面和选项菜单
    cout << "——————————————" << endl;
    cout << "  欢迎使用机房预约系统系统" << endl;
    cout << "——————————————" << endl;
    cout << "\t1.学生代表" << endl;
    cout << "\t2.老师" << endl;
    cout << "\t3.管理员" << endl;
    cout << "\t0.退出" << endl;
    cout << "——————————————" << endl;
    cout << "请输入您的选择" << endl;

    // 存储用户的选择
    int select = 0;

    // 从用户获取选择输入
    cin >> select;

    // 根据用户选择执行对应的操作
    switch (select) {
      case 1:  // 学生
        LoginIn(STUDENT_FILE, 1);
        break;
      case 2:  // 老师
        LoginIn(TEACHER_FILE, 2);
        break;
      case 3:  // 管理员
        LoginIn(ADMIN_FILE, 3);
        break;
      case 0:  // 退出
        // 用户选择退出，显示告别信息并退出程序
        cout << "欢迎下次使用!" << endl;
        system("pause");
        return 0;
        break;
      default:
        // 如果用户输入无效选择，提示错误并刷新界面
        cout << "输入有误，请重新选择！" << endl;
        system("pause");
        system("cls");
        break;
    }
  }

  // 程序结束前暂停，以便用户查看信息
  system("pause");
  return 0;
}