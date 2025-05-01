#include <algorithm>  // 提供 set_union、for_each 等算法
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

  // 创建目标容器 vTarget，用于保存并集结果
  vector<int> vTarget;

  // 必须提前为目标容器分配足够的空间
  // 最坏情况下两个容器完全不重合，所以需要两者大小之和
  vTarget.resize(v1.size() + v2.size());

  // 使用 set_union 求两个有序集合的并集
  // 返回值是一个迭代器，指向并集的“尾后”位置
  vector<int>::iterator itEnd =
      set_union(v1.begin(), v1.end(),  // 第一个集合 [0, 1, ..., 9]
                v2.begin(), v2.end(),  // 第二个集合 [5, 6, ..., 14]
                vTarget.begin());      // 结果写入 vTarget

  // 使用 for_each 遍历并打印并集部分的结果
  // 注意：只遍历从 begin 到 itEnd 的区间
  cout << "两个集合的并集为：" << endl;
  for_each(vTarget.begin(), itEnd, MyPrint);
  cout << endl;
}
int main(void) {
  test01();
  system("pause");
  return 0;
}
