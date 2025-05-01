#include "teacher.h"

// 无参构造
Teacher::Teacher() {}

// 有参构造
Teacher::Teacher(int empId, string name, string pwd) {
  // 初始化属性
  this->m_EmpId = empId;       // 设置教师工号
  this->m_UserName = name;     // 设置教师姓名
  this->m_UserPassword = pwd;  // 设置教师密码
}

// 菜单
void Teacher::operMenu() {
  cout << "欢迎教师: " << this->m_UserName << "登录! " << endl;
  cout << "——————————" << endl;
  cout << "——1.查看所有预约——" << endl;
  cout << "——2.审核预约————" << endl;
  cout << "——0.注销登录———" << endl;
  cout << "——————————" << endl;
  cout << "请选择你的操作" << endl;
}

// 显示所有预约记录
void Teacher::showAllOrder() {
  // 创建OrderFile对象，用于操作预约文件
  OrderFile of;

  // 检查是否有预约记录
  if (of.m_Size == 0) {
    // 如果没有预约记录，输出提示信息并返回
    cout << "无预约记录" << endl;
    system("pause");
    system("cls");
    return;
  }

  // 遍历所有预约记录并显示
  for (int i = 0; i < of.m_Size; i++) {
    // 输出预约序号
    cout << i + 1 << "、 ";
    // 输出预约日期和时间段
    cout << "预约日期: 周" << of.m_orderData[i]["date"];
    cout << " 时间段:  "
         << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
    // 输出学号和姓名
    cout << " 学号:  " << of.m_orderData[i]["stuId"];
    cout << " 姓名:  " << of.m_orderData[i]["stuName"];
    // 输出机房编号
    cout << " 机房编号:  " << of.m_orderData[i]["roomId"];
    // 初始化状态字符串
    string status = " 状态: ";

    // 根据预约状态码更新状态字符串
    if (of.m_orderData[i]["status"] == "1") {
      status += "审核中";
    } else if (of.m_orderData[i]["status"] == "2") {
      status += "预约成功";
    } else if (of.m_orderData[i]["status"] == "-1") {
      status += "预约失败，审核未通过";
    } else {
      status += "预约已取消";
    }

    // 输出预约状态
    cout << status << endl;
  }

  // 暂停并清屏
  system("pause");
  system("cls");
}

// 审核预约记录的功能函数
void Teacher::validOrder() {
  // 创建OrderFile对象，用于操作预约文件
  OrderFile of;
  // 如果预约记录为空，则提示无预约记录并返回
  if (of.m_Size == 0) {
    cout << "无预约记录" << endl;
    system("pause");
    system("cls");
    return;
  }

  // 输出待审核的预约记录
  cout << "待审核的预约记录如下:" << endl;

  // 存储待审核预约记录的索引
  vector<int> v;

  // 用于显示预约记录的序号
  int index = 0;
  // 遍历所有预约记录，查找状态为"1"（即待审核）的记录
  for (int i = 0; i < of.m_Size; i++) {
    if (of.m_orderData[i]["status"] == "1") {
      v.push_back(i);
      cout << ++index << "、 ";
      // 输出预约记录的详细信息
      cout << "预约日期: 周" << of.m_orderData[i]["date"];
      cout << " 时间段: "
           << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
      cout << "学生编号: " << of.m_orderData[i]["stuId"];
      cout << "学生姓名: " << of.m_orderData[i]["stuName"];
      cout << "机房编号: " << of.m_orderData[i]["roomId"];
      cout << "状态: 审核中 " << endl;
    }
  }
  // 提示用户输入要审核的预约记录
  cout << "请输入要审核的预约记录,0代表返回" << endl;
  int select = 0;  // 接收用户选择的预约记录
  int ret = 0;     // 接收预约结果记录
  // 循环直到用户选择有效的预约记录或输入0返回
  while (1) {
    cin >> select;
    if (select >= 0 && select <= v.size()) {
      if (select == 0) {
        break;
      } else {
        // 提示用户输入审核结果
        cout << "请输入审核结果" << endl;
        cout << "1.通过" << endl;
        cout << "2.不通过" << endl;
        cin >> ret;
        // 根据用户输入更新预约记录的状态
        if (ret == 1) {
          // 通过
          of.m_orderData[v[select - 1]]["status"] =
              "2";  //-1是因为vector容器下标是从0开始的
        } else {
          // 不通过
          of.m_orderData[v[select - 1]]["status"] = "-1";
        }
        // 更新预约记录
        of.updateOrder();
        cout << "审核完毕" << endl;
        break;
      }
    }
    // 如果用户输入无效，提示错误
    cout << "输入有误，请重新输入" << endl;
  }
  // 暂停并清屏
  system("pause");
  system("cls");
}