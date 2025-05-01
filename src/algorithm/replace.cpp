#include <algorithm>   // 提供 replace、for_each 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义打印函数：用于输出每个元素
void myPrint(int val) {
  cout << val << " ";  // 输出当前元素并加空格分隔
}

void test01() {
  // 创建一个 vector<int> 容器，并插入一些整数
  vector<int> v;
  v.push_back(20);
  v.push_back(10);
  v.push_back(60);
  v.push_back(50);
  v.push_back(30);
  v.push_back(20);  // 注意：20 出现了两次

  // 打印替换前的内容
  cout << "替换前" << endl;
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;

  // 使用 replace 将所有等于 20 的元素替换为 2000
  replace(v.begin(), v.end(), 20, 2000);

  // 打印替换后的内容
  cout << "替换后" << endl;
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}