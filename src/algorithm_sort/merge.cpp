#include <algorithm>   // 提供 merge、for_each 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义打印函数：用于输出每个元素
void myPrint(int val) {
  cout << val << " ";  // 输出当前元素并加空格分隔
}

void test01() {
  // 创建两个 vector<int> 容器 v1 和 v2，并插入数据
  vector<int> v1;
  vector<int> v2;

  for (int i = 0; i < 5; i++) {
    v1.push_back(i);      // v1: 0, 1, 2, 3, 4
    v2.push_back(i + 5);  // v2: 5, 6, 7, 8, 9
  }

  // 创建目标容器 vTarget，用于保存合并后的结果
  vector<int> vTarget;

  // 必须提前为目标容器分配足够的空间
  vTarget.resize(v1.size() + v2.size());  // 分配 v1 和 v2 总长度的空间

  // 使用 merge 合并两个有序容器（v1 和 v2 必须是已排序的）
  merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

  // 使用 for_each 遍历并打印合并后的容器内容
  for_each(vTarget.begin(), vTarget.end(), myPrint);
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}