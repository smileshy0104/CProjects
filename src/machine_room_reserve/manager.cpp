#include "manager.h"

// 默认构造
Manager::Manager() {}

// 有参构造
Manager::Manager(string name, string pwd) {
  this->m_UserName = name;
  this->m_UserPassword = pwd;

  // 初识化容器 获取到所有文件中 学生、老师、信息
  this->initVector();

  // 初始化机房信息
  ifstream ifs;
  ifs.open(COMPUTER_FILE, ios::in);

  computerRoom com;
  while (ifs >> com.m_ComId && ifs >> com.m_ManNum) {
    vCom.push_back(com);
  }
  ifs.close();
}

// 菜单
void Manager::operMenu() {
  cout << "欢迎管理员:" << this->m_UserName << "登录!" << endl;
  cout << "——————————" << endl;
  cout << "——1.添加账号——" << endl;
  cout << "——2.查看账号——" << endl;
  cout << "——3.查看机房——" << endl;
  cout << "——4.清空预约——" << endl;
  cout << "——0.注销登录——" << endl;
  cout << "——————————" << endl;
  cout << "——————————" << endl;
  cout << "当前学生数量:" << vStu.size() << endl;
  cout << "当前老师数量:" << vTea.size() << endl;
  cout << "机房数量为:" << vCom.size() << endl;
  cout << "——————————" << endl;
  cout << "请选择您的操作:" << endl;
}

// 添加人员函数
void Manager::addPerson() {
  // 提示用户选择添加账号的类型
  cout << "请输入添加账号的类型" << endl;
  cout << "1.添加学生" << endl;
  cout << "2.添加老师" << endl;

  // 定义变量用于操作文件名、提示信息和文件操作对象
  string fileName;  // 操作文件名
  string tip;       // 提示id号
  ofstream ofs;     // 文件操作对象

  // 定义错误提示信息
  string errorTip;

  // 获取用户选择
  int select = 0;
  cin >> select;

  // 根据用户选择设置相关参数
  if (select == 1) {
    fileName = STUDENT_FILE;
    tip = "请输入学号";
    errorTip = "学号重复,重新输入!";
  } else {
    fileName = TEACHER_FILE;
    tip = "请输入职工编号";
    errorTip = "职工号重复,重新输入!";
  }

  // 打开对应文件以添加数据
  ofs.open(fileName, ios::out | ios::app);

  // 定义变量存储id、姓名和密码
  int id;
  string name;
  string pwd;

  // 提示用户输入id
  cout << tip << endl;

  // 循环直到用户输入的id不重复
  while (1) {
    cin >> id;
    bool ret = checkRepeat(id, select);
    if (ret)  // 有重复
    {
      cout << errorTip << endl;
    } else {
      break;
    }
  }

  // 提示用户输入姓名和密码
  cout << "请输入姓名" << endl;
  cin >> name;

  cout << "请输入密码" << endl;
  cin >> pwd;

  // 向文件添加数据
  ofs << id << " " << name << " " << pwd << " " << endl;
  cout << "添加成功" << endl;

  // 添加成功后，将内容同步到当前容器中，以解决添加一人，人数翻倍的bug
  if (select == 1) {
    // 添加学生——同步到当前容器中
    Student s;
    s.m_Id = id;
    s.m_UserName = name;
    s.m_UserPassword = pwd;
    vStu.push_back(s);
  } else if (select == 2) {
    // 添加老师——同步到当前容器中
    Teacher t;
    t.m_EmpId = id;
    t.m_UserName = name;
    t.m_UserPassword = pwd;
    vTea.push_back(t);
  }

  // 暂停并清屏
  system("pause");
  system("cls");

  // 关闭文件
  ofs.close();

  // 调用初始化容器接口（已注释掉）
  // this->initVector();

  /*以下为开发者对代码的额外说明：
  不知道是我漏掉了代码，还是代码本身的小漏洞，连续添加账号会出现显示bug和人员统计数量bug
  我认为是重复的vector存储，读取，本人有两种解决方法

  1.如上，去掉结尾的初始化容器，在上面的添加成功后，直接将当前的成员读进vector容器中
  2.理论可行，但是我没去实现，在原来的代码基础上，结尾调用初始化容器接口前，清理一下当前容器,vStu.clear();vTea.clear();

  这样解决了bug，并且保留了即时同步。:)
  */
}

// 打印学生信息
void printStudent(Student& s) {
  cout << "学号:" << s.m_Id << " 姓名:" << s.m_UserName
       << " 密码:" << s.m_UserPassword << endl;
}

// 打印老师信息
void printTeacher(Teacher& s) {
  cout << "职工号:" << s.m_EmpId << " 姓名:" << s.m_UserName
       << " 密码:" << s.m_UserPassword << endl;
}

// 显示人员信息函数
void Manager::showPerson() {
  // 提示用户选择查看内容
  cout << "请选择查看内容" << endl;
  cout << "1.查看所有学生" << endl;
  cout << "2.查看所有老师" << endl;

  // 获取用户选择
  int select = 0;
  cin >> select;

  // 根据用户选择显示相应信息
  if (select == 1) {
    // 显示所有学生信息
    cout << "所有学生信息如下:" << endl;
    for_each(vStu.begin(), vStu.end(), printStudent);
  } else {
    // 显示所有老师信息
    cout << "所老师生信息如下:" << endl;
    for_each(vTea.begin(), vTea.end(), printTeacher);
  }

  // 暂停以供用户查看信息
  system("pause");
  // 清屏为下一步操作做准备
  system("cls");
}

// 显示所有机房的信息
void Manager::showComputer() {
  // 输出机房信息的标题
  cout << "机房信息如下" << endl;

  // 遍历机房信息容器
  for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end();
       it++) {
    // 输出单个机房的编号和最大容量
    cout << "机房编号:" << it->m_ComId << " 机房最大容量:" << it->m_ManNum
         << endl;
  }

  // 暂停屏幕以便用户查看信息
  system("pause");
  // 清屏，为下一次操作做准备
  system("cls");
}

// 清空预约记录
void Manager::cleamFile() {
  ofstream ofs(ORDER_FILE, ios::trunc);
  ofs.close();

  cout << "清空成功" << endl;
  system("pause");
  system("cls");
}

// 初始化向量，从文件中读取学生和老师的信息
void Manager::initVector() {
  // 读取学生信息
  ifstream ifs;
  ifs.open(STUDENT_FILE, ios::in);
  if (!ifs.is_open()) {
    cout << "文件读取失败" << endl;
    return;
  }
  Student s;
  // 读取并存储学生信息，直到文件结束
  while (ifs >> s.m_Id && ifs >> s.m_UserName && ifs >> s.m_UserPassword) {
    vStu.push_back(s);
  }

  ifs.close();

  // 读取老师信息
  ifs.open(TEACHER_FILE, ios::in);
  Teacher t;
  // 读取并存储老师信息，直到文件结束
  while (ifs >> t.m_EmpId && ifs >> t.m_UserName && ifs >> t.m_UserPassword) {
    vTea.push_back(t);
  }
  ifs.close();
}

// 检测重复
bool Manager::checkRepeat(int id, int type) {
  if (type == 1) {
    for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
      if (id == it->m_Id) {
        return true;
      }
    }
  } else {
    for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
      if (id == it->m_EmpId) {
        return true;
      }
    }
  }

  return false;
}
