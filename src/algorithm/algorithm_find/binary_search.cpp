#include <algorithm>   // 提供 binary_search 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 测试函数：演示 binary_search 的使用
void test01() {
  // 创建一个 vector<int> 容器，并插入有序数据 0~9
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);  // 插入元素，v 中的数据是已排序的
  }

  // 注意：binary_search 要求容器必须是有序的
  // 如果容器无序，结果不可预测，必须先排序后再使用 binary_search

  // 使用 binary_search 查找值为 9 的元素是否存在
  bool ret = binary_search(v.begin(), v.end(), 9);

  // 判断是否找到目标值
  if (ret) {
    cout << "找到了" << endl;
  } else {
    cout << "没找到" << endl;
  }
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}