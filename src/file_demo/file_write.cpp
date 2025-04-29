#include <fstream>   // 包含文件流库，用于文件操作
#include <iostream>  // 包含输入输出流库，用于控制台输入输出
using namespace std;

//* 文本文件写文件
/*
- 文件操作必须包含头文件 fstream
- 写文件可以利用 ofstream 类
- 打开文件时需要指定操作文件的路径，以及打开方式
- 利用 << 可以向文件中写数据
- 操作完毕后，要关闭文件
*/

void test01() {
  // 1. 创建 ofstream 对象，用于文件写操作
  ofstream ofs;

  // 2. 打开文件，指定文件路径和打开方式
  //    这里使用 ios::out 表示以写模式打开文件
  //    如果文件不存在，会创建新文件；如果文件存在，会覆盖原有内容
  ofs.open("test.txt", ios::out);

  // 3. 检查文件是否成功打开
  if (!ofs.is_open()) {
    cerr << "无法打开文件 test.txt" << endl;
    return;
  }

  // 4. 向文件中写入内容
  ofs << "姓名:张三2" << endl;  // 写入姓名
  ofs << "性别:男" << endl;     // 写入性别
  ofs << "年龄:18" << endl;     // 写入年龄

  // 5. 关闭文件，释放资源
  ofs.close();
}

int main(void) {
  test01();         // 调用 test01 函数进行文件写操作
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}