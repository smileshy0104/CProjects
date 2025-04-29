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
  // 2. 创建文件流对象，并以二进制模式打开文件
  ofstream ofs("person.txt", ios::out | ios::binary);
  // 3. 打开文件
  // ofs.open("person.txt", ios::out | ios::binary); // 另一种打开文件的方式

  // 4. 写文件
  Person p = {"张三", 18};  // 创建一个 Person 对象，初始化姓名和年龄
  ofs.write((const char*)&p,
            sizeof(Person));  // 将 Person 对象以二进制形式写入文件

  // 5. 关闭文件
  ofs.close();  // 关闭文件，释放资源
}

int main(void) {
  test01();         // 调用 test01 函数进行二进制文件写操作
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}