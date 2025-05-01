#include "orderFile.h"

// 构造函数：OrderFile
// 描述：读取订单文件并解析订单信息到内存中
OrderFile::OrderFile() {
  // 创建ifstream对象以读取文件
  ifstream ifs;
  // 打开订单文件
  ifs.open(ORDER_FILE, ios::in);

  // 定义字符串变量以存储文件中的订单信息
  string date;
  string interval;  // 时间段
  string stuId;
  string stuName;
  string roomId;
  string status;  // 状态

  // 初始化订单记录条数为0
  this->m_Size = 0;  // 记录条数

  // 读取文件中的订单信息，直到文件结束
  while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName &&
         ifs >> roomId && ifs >> status) {
    // 以下代码被注释掉，用于调试输出读取的信息
    /*	cout << date << endl;
            cout << interval << endl;
            cout << stuId << endl;
            cout << stuName << endl;
            cout << roomId << endl;
            cout<<status << endl;*/

    // 定义键值对变量以解析订单信息
    string key;
    string value;
    // 创建map容器以存储解析后的订单信息
    map<string, string> m;

    // 解析日期信息
    int pos = date.find(":");
    if (pos != -1) {
      key = date.substr(0, pos);
      value = date.substr(pos + 1, date.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    // 解析时间段信息
    pos = interval.find(":");
    if (pos != -1) {
      key = interval.substr(0, pos);
      value = interval.substr(pos + 1, interval.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    // 解析学生ID信息
    pos = stuId.find(":");
    if (pos != -1) {
      key = stuId.substr(0, pos);
      value = stuId.substr(pos + 1, stuId.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    // 解析学生姓名信息
    pos = stuName.find(":");
    if (pos != -1) {
      key = stuName.substr(0, pos);
      value = stuName.substr(pos + 1, stuName.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    // 解析房间ID信息
    pos = roomId.find(":");
    if (pos != -1) {
      key = roomId.substr(0, pos);
      value = roomId.substr(pos + 1, roomId.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    // 解析状态信息
    pos = status.find(":");
    if (pos != -1) {
      key = status.substr(0, pos);
      value = status.substr(pos + 1, status.size() - pos - 1);
      m.insert(make_pair(key, value));
    }

    // 将解析后的订单信息插入到大的map容器中
    this->m_orderData.insert(make_pair(this->m_Size, m));
    // 增加订单记录条数
    this->m_Size++;
  }

  // 关闭文件
  ifs.close();

  // 以下代码被注释掉，用于调试输出解析后的订单信息
  /*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it !=
  m_orderData.end(); it++)
  {
          cout << it->first << endl;
          for (map<string, string>::iterator mit = (*it).second.begin(); mit !=
  (*it).second.end(); mit++)
          {
                  cout << mit->first << " " << mit->second << " ";
          }
          cout << endl;
  }*/

  // 暂停以查看输出，然后清屏
  system("pause");
  system("cls");
}

// 更新订单信息到文件中
void OrderFile::updateOrder() {
  // 如果订单数量为0，则不进行任何操作并直接返回
  if (this->m_Size == 0) {
    return;
  }

  // 打开订单文件，以写入模式并清空原有内容
  ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

  // 遍历所有订单数据
  for (int i = 0; i < this->m_Size; i++) {
    // 写入日期信息
    ofs << "date:" << this->m_orderData[i]["date"] << " ";
    // 写入时间间隔信息
    ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
    // 写入学生ID信息
    ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
    // 写入学生姓名信息
    ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
    // 写入房间ID信息
    ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
    // 写入订单状态信息，并换行
    ofs << "status:" << this->m_orderData[i]["status"] << endl;
  }

  // 关闭文件流
  ofs.close();
}
