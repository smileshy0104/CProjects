#include <fstream>
#include <iostream>
using namespace std;
// 文本文件写文件
void test01() {
  // 1.包含头文件
  // 2.创建流对象
  ofstream ofs;
  // 3.指定打开方式
  ofs.open("test.txt",
           ios::out);  // 如果不指定文件路径，默认和你项目的文件路径一样
  // 4.写内容
  ofs << "姓名:张三" << endl;
  ofs << "性别:男" << endl;
  ofs << "年龄:18" << endl;
  // 5.关闭文件
  ofs.close();
}
int main(void) {
  test01();
  system("pause");
  return 0;
}
