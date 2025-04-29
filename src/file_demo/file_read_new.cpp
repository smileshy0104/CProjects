#include <fstream>   // 包含文件流库，用于文件操作
#include <iostream>  // 包含输入输出流库，用于控制台输入输出
using namespace std;

// 定义一个 Person 类，包含姓名和年龄
class Person {
 public:
  char m_Name[64];  // 姓名，使用字符数组存储
  int m_Age;        // 年龄，使用整数存储
};

void test01() {
  // 1. 包含头文件
  // 2. 创建文件流对象
  ifstream ifs;

  // 3. 打开文件，并判断文件是否打开成功
  ifs.open("person.txt",
           ios::in | ios::binary);  // 以二进制模式打开文件 "person.txt"
  if (!(ifs.is_open())) {
    cout << "打开失败" << endl;  // 如果文件未成功打开，输出错误信息
    return;                      // 返回，结束函数
  }

  // 4. 读文件
  Person p;  // 创建一个 Person 对象用于存储读取的数据
  ifs.read((char*)&p,
           sizeof(Person));  // 从文件中读取二进制数据到 Person 对象中
  cout << "姓名:" << p.m_Name << " " << "年龄:" << p.m_Age
       << endl;  // 输出读取的内容

  // 5. 关闭文件
  ifs.close();  // 关闭文件，释放资源
}

int main(void) {
  test01();         // 调用 test01 函数进行二进制文件读操作
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}