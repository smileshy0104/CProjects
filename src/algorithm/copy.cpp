#include <algorithm>   // 提供 copy、for_each 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义打印函数：用于输出每个元素
void myPrint(int val) {
  cout << val << " ";  // 输出当前元素并加空格分隔
}

void test01() {
  // 创建 vector<int> 容器 v1，并插入 0~9
  vector<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);  // 插入元素
  }

  // 创建目标容器 v2，并提前分配与 v1 相同大小的空间
  vector<int> v2;
  v2.resize(v1.size());  // 必须提前分配足够空间，否则 copy 会越界访问

  // 使用 copy 将 v1 的所有元素复制到 v2 中
  copy(v1.begin(), v1.end(), v2.begin());

  // 使用 for_each 遍历并打印 v2 中的元素
  for_each(v2.begin(), v2.end(), myPrint);
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}