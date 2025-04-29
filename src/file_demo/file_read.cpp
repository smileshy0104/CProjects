#include <fstream>   // 包含文件流库，用于文件操作
#include <iostream>  // 包含输入输出流库，用于控制台输入输出
#include <string>    // 包含字符串库，用于处理字符串
using namespace std;

void test01() {
  // 1. 创建流对象
  ifstream ifs;

  // 2. 打开文件，并且判断是否打开成功
  ifs.open("test.txt", ios::in);  // 以读模式打开文件 "test.txt"
  if (!ifs.is_open()) {
    cout << "文件打开失败了" << endl;  // 如果文件未成功打开，输出错误信息
    return;                            // 返回，结束函数
  }

  // 3. 读数据
  // 第一种方法：使用 >> 运算符逐词读取
  /*
  char buf[1024] = { 0 }; // 定义一个字符数组用于存储读取的数据
  while (ifs >> buf) {
    cout << buf << endl; // 输出读取的内容
  }
  */

  // 第二种方法：使用 getline 函数逐行读取
  /*
  char buf[1024] = { 0 }; // 定义一个字符数组用于存储读取的数据
  while (ifs.getline(buf, sizeof(buf))) {
    cout << buf << endl; // 输出读取的内容
  }
  */

  // 第三种方法：使用 getline 函数和 string 对象逐行读取
  /*
  string buf; // 定义一个字符串对象用于存储读取的数据
  while (getline(ifs, buf)) {
    cout << buf << endl; // 输出读取的内容
  }
  */

  // 第四种方法：逐字符读取（不推荐，因为效率较低）
  char c;
  while ((c = ifs.get()) != EOF) {  // 使用 ifs.get() 逐字符读取，直到文件末尾
    cout << c;                      // 输出读取的字符
  }

  // 4. 关闭文件
  ifs.close();  // 关闭文件，释放资源
}

int main(void) {
  test01();         // 调用 test01 函数进行文件读操作
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}