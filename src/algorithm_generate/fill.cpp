#include <algorithm>  // 提供 fill、for_each 等算法
#include <iostream>   // 输入输出流库
#include <numeric>    // 本例未使用，可省略
#include <vector>     // 使用 vector 容器
using namespace std;

// 自定义打印函数：用于输出每个元素
void MyPrint(int val) {
  cout << val << " ";  // 输出当前整数并加空格分隔
}

void test01() {
  // 创建一个 vector<int> 容器，并设置大小为 10
  vector<int> v;
  v.resize(10);  // 分配 10 个 int 空间，默认初始化为 0

  // 使用 fill 将 [begin, end) 区间内的所有元素设置为 100
  fill(v.begin(), v.end(), 100);

  // 使用 for_each 遍历并打印容器内容
  for_each(v.begin(), v.end(), MyPrint);
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}