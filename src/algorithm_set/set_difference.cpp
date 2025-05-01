#include <algorithm>  // 提供 set_difference、for_each、max 等算法
#include <iostream>   // 输入输出流库
#include <vector>     // 使用 vector 容器
using namespace std;

// 自定义打印函数：用于输出每个整数
void MyPrint(int val) {
  cout << val << " ";  // 输出当前元素并加空格分隔
}

void test01() {
  // 创建两个 vector<int> 容器 v1 和 v2，并插入数据
  vector<int> v1;
  vector<int> v2;

  for (int i = 0; i < 10; i++) {
    v1.push_back(i);      // v1: 0~9
    v2.push_back(i + 5);  // v2: 5~14
  }

  // 创建目标容器 vTarget，用于保存差集结果
  vector<int> vTarget;

  // 必须提前为目标容器分配足够的空间
  // 最坏情况下两个集合无交集，所以需要较大容器的 size
  vTarget.resize(max(v1.size(), v2.size()));  // max(10, 10) = 10

  // 求 v1 - v2 的差集（即在 v1 中但不在 v2 中的元素）
  cout << "v1和v2的差集" << endl;
  vector<int>::iterator itEnd =
      set_difference(v1.begin(), v1.end(),  // 第一个集合 [0, 1, ..., 9]
                     v2.begin(), v2.end(),  // 第二个集合 [5, 6, ..., 14]
                     vTarget.begin());      // 结果写入 vTarget

  // 打印差集部分的结果（从 begin 到 itEnd）
  for_each(vTarget.begin(), itEnd, MyPrint);
  cout << endl;

  // 求 v2 - v1 的差集（即在 v2 中但不在 v1 中的元素）
  cout << "v2和v1的差集" << endl;
  itEnd = set_difference(v2.begin(), v2.end(),  // 第二个集合 [5, 6, ..., 14]
                         v1.begin(), v1.end(),  // 第一个集合 [0, 1, ..., 9]
                         vTarget.begin());      // 结果写入 vTarget

  // 打印差集部分的结果（从 begin 到 itEnd）
  for_each(vTarget.begin(), itEnd, MyPrint);
  cout << endl;
}
int main(void) {
  test01();
  system("pause");
  return 0;
}