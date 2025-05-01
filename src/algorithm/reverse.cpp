#include <algorithm>   // 提供 reverse、for_each 等算法
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
  v.push_back(5);
  v.push_back(30);
  v.push_back(2);

  // 打印原始顺序
  cout << "原始顺序: ";
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;

  // 使用 reverse 反转容器中元素的顺序
  reverse(v.begin(), v.end());

  // 打印反转后的顺序
  cout << "反转后顺序: ";
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}