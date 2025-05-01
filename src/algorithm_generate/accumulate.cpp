#include <iostream>  // 输入输出流库
#include <numeric>   // 提供 accumulate 算法
#include <vector>    // 使用 vector 容器
using namespace std;

// 自定义打印函数（本例未使用，可保留用于调试）
void MyPrint(int val) { cout << val << " "; }

void test01() {
  // 创建一个 vector<int> 容器，并插入 0~100 的整数
  vector<int> v;
  for (int i = 0; i <= 100; i++) {
    v.push_back(i);  // 插入元素
  }

  // 使用 accumulate 对容器中所有元素求和
  // 参数说明：
  // - 第一个参数：起始迭代器（v.begin()）
  // - 第二个参数：结束迭代器（v.end()）
  // - 第三个参数：初始累加值（这里是 0）
  int total = accumulate(v.begin(), v.end(), 0);

  // 输出累加结果
  cout << "总和为：" << total << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}