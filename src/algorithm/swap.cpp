#include <algorithm>   // 提供 swap、for_each 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <string>      // 字符串支持（本例未使用，可省略）
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义打印函数：用于输出每个元素
void MyPrint(int val) {
  cout << val << " ";  // 输出当前整数并加空格分隔
}

void test01() {
  // 创建两个 vector<int> 容器 v1 和 v2
  vector<int> v1;
  vector<int> v2;

  // 向 v1 插入 0~9，v2 插入 100~109
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);        // v1: 0, 1, 2, ..., 9
    v2.push_back(i + 100);  // v2: 100, 101, ..., 109
  }

  // 打印交换前的容器内容
  cout << "交换前" << endl;
  cout << "v1: ";
  for_each(v1.begin(), v1.end(), MyPrint);
  cout << endl;

  cout << "v2: ";
  for_each(v2.begin(), v2.end(), MyPrint);
  cout << endl;

  // 使用 swap 交换两个容器的内容
  cout << "交换后" << endl;
  swap(v1, v2);  // 或 std::swap(v1, v2);

  // 打印交换后的容器内容
  cout << "v1: ";
  for_each(v1.begin(), v1.end(), MyPrint);
  cout << endl;

  cout << "v2: ";
  for_each(v2.begin(), v2.end(), MyPrint);
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}