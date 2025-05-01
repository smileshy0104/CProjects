#include <iostream>  // 标准输入输出流库
#include <string>    // 提供 string 类型支持
using namespace std;

//* pair对组创建
/*
功能描述：
成对出现的数据，利用对组可以返回两个数据。
*/
void test01() {
  // 第一种方式：直接构造一个 pair 对象
  // 创建一个 pair，第一个元素是字符串 "Tom"，第二个是整数 11
  pair<string, int> p("Tom", 11);

  // 输出 pair 中的内容
  // first 是姓名，second 是年龄
  cout << p.first << " " << p.second << endl;
  // 输出结果为: Tom 11

  // 第二种方式：使用 make_pair 函数创建 pair 对象
  // make_pair 自动推导类型并构造 pair
  pair<string, int> p2 = make_pair("Jerry", 12);

  // 输出 p2 的内容
  cout << p2.first << " " << p2.second << endl;  // 输出: Jerry 12
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 系统）
  return 0;         // 程序正常结束
}