#include "student.h"

Student::Student() {}
// 有参构造
Student::Student(int id, string name, string pwd) {
  // 初始化属性
  this->m_Id = id;
  this->m_UserName = name;
  this->m_UserPassword = pwd;

  // 初始化机房信息
  ifstream ifs;
  ifs.open(COMPUTER_FILE, ios::in);

  computerRoom com;
  while (ifs >> com.m_ComId && ifs >> com.m_ManNum) {
    // 将读取的信息放入到容器中
    vCom.push_back(com);
  }

  ifs.close();
}
// 菜单界面
void Student::operMenu() {
  cout << "欢迎学生代表:" << this->m_UserName << "登录!" << endl;
  cout << "——————————" << endl;
  cout << "——1.申请预约——" << endl;
  cout << "——2.查看我的预约—" << endl;
  cout << "——3.查看所有预约—" << endl;
  cout << "——4.取消预约——" << endl;
  cout << "——0.注销登录——" << endl;
  cout << "——————————" << endl;
  cout << "请选择您的操作:" << endl;
}

// 申请预约
void Student::applyOrder() {
  cout << "机房开放时间为周一至周五" << endl;
  cout << "请输入申请预约的时间" << endl;
  cout << "1.周一" << endl;
  cout << "2.周二" << endl;
  cout << "3.周三" << endl;
  cout << "4.周四" << endl;
  cout << "5.周五" << endl;

  // 日期
  int data = 0;
  // 时间段
  int interval = 0;
  // 机房编号
  int room = 0;

  while (1) {
    cin >> data;
    if (data >= 1 && data <= 5) {
      break;
    } else {
      cout << "输入有误，请重新输入。" << endl;
    }
  }
  cout << "请输入申请预约的时间段" << endl;
  cout << "1.上午" << endl;
  cout << "2.下午" << endl;

  while (1) {
    cin >> interval;
    if (interval >= 1 && interval <= 2) {
      break;
    } else {
      cout << "输入有误，请重新输入。" << endl;
    }
  }

  cout << "请选择机房" << endl;
  for (int i = 0; i < vCom.size(); i++) {
    cout << vCom[i].m_ComId << "号机房容量为:" << vCom[i].m_ManNum << endl;
  }

  while (1) {
    cin >> room;
    if (room >= 1 && room <= 3) {
      break;
    } else {
      cout << "输入有误，请重新输入。" << endl;
    }
  }
  cout << "预约成功，审核中！" << endl;

  // 写入文件
  ofstream ofs;
  ofs.open(ORDER_FILE, ios::app);
  ofs << "date:" << data << " ";
  ofs << "interval:" << interval << " ";
  ofs << "stuId:" << this->m_Id << " ";
  ofs << "stuName:" << this->m_UserName << " ";
  ofs << "roomId:" << room << " ";
  ofs << "status:" << 1 << endl;

  ofs.close();

  system("pause");
  system("cls");
}

// 查看自身预约
void Student::showMyOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    cout << "无预约记录" << endl;
    system("pause");
    system("cls");
    return;
  }
  for (int i = 0; i < of.m_Size; i++) {
    // string 转 int
    // string 利用.c_str()转const char *
    // 利用atoi (const char * )转 int
    if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))  // 找到自身预约
    {
      cout << "预约日期:  周" << of.m_orderData[i]["date"];
      cout << " 时间段:  "
           << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
      cout << " 机房号:  " << of.m_orderData[i]["roomId"];
      string status = "状态:	";

      if (of.m_orderData[i]["status"] == "1") {
        status += "审核中";
      } else if (of.m_orderData[i]["status"] == "2") {
        status += "预约成功";
      } else if (of.m_orderData[i]["status"] == "-1") {
        status += "预约失败,审核未通过";
      } else {
        status += "预约已取消";
      }
      cout << status << endl;
    }
  }
  system("pause");
  system("cls");
}

// 查看所有预约
void Student::showAllOrder() {
  OrderFile of;
  if (of.m_Size == 0) {
    cout << "无预约记录" << endl;
    system("pause");
    system("cls");
    return;
  }

  for (int i = 0; i < of.m_Size; i++) {
    cout << i + 1 << "、 ";
    cout << "预约日期:  周" << of.m_orderData[i]["date"];
    cout << " 时间段:  "
         << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
    cout << " 学号:  " << of.m_orderData[i]["stuId"];
    cout << " 姓名:  " << of.m_orderData[i]["stuName"];
    cout << " 机房编号:  " << of.m_orderData[i]["roomId"];

    string status = " 状态: ";

    if (of.m_orderData[i]["status"] == "1") {
      status += "审核中";
    } else if (of.m_orderData[i]["status"] == "2") {
      status += "预约成功";
    } else if (of.m_orderData[i]["status"] == "-1") {
      status += "预约失败,审核未通过";
    } else {
      status += "预约已取消";
    }
    cout << status << endl;
  }
  system("pause");
  system("cls");
}

// 取消预约
void Student::cancelOrder() {
  OrderFile of;

  if (of.m_Size == 0) {
    cout << "无预约记录" << endl;
    system("pause");
    system("cls");
    return;
  }

  cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

  // 存放下标
  vector<int> v;

  int index = 1;
  for (int i = 0; i < of.m_Size; i++) {
    // 找到自身预约的记录
    if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
      // 筛选状态
      // 审核中或预约成功
      if (of.m_orderData[i]["status"] == "1" ||
          of.m_orderData[i]["status"] == "2") {
        v.push_back(i);
        cout << index++ << "、 ";
        cout << "预约时期:  周" << of.m_orderData[i]["date"];
        cout << " 时间段:  "
             << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 机房编号:  " << of.m_orderData[i]["roomId"];
        string status = " 状态:  ";
        if (of.m_orderData[i]["status"] == "1") {
          status += "审核中";
        } else if (of.m_orderData[i]["status"] == "2") {
          status += "预约成功";
        }
        cout << status << endl;
      }
    }
  }
  cout << "请输入取消的记录，0代表返回" << endl;
  int select = 0;
  while (1) {
    cin >> select;
    if (select >= 0 && select <= v.size()) {
      if (select == 0) {
        break;
      } else {
        of.m_orderData[v[select - 1]]["status"] = "0";

        // 更新文件
        of.updateOrder();

        cout << "已取消预约" << endl;
        break;
      }
    }
    cout << "输入有误，请重新输入" << endl;
  }

  system("pause");
  system("cls");
}
