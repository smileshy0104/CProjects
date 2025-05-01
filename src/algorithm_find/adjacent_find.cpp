#include <algorithm>   // 提供 adjacent_find、sort 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 测试函数：演示 adjacent_find 的使用
void test01() {
  // 创建一个 vector<int> 容器，并插入一些整数
  vector<int> v;
  v.push_back(0);
  v.push_back(2);
  v.push_back(1);
  v.push_back(2);
  v.push_back(7);
  v.push_back(3);
  v.push_back(3);  // 这两个 3 是相邻且相等的

  // 使用 adjacent_find 查找第一个相邻且相等的元素对
  // 返回的是第一个重复元素的迭代器
  vector<int>::iterator it = adjacent_find(v.begin(), v.end());

  // 判断是否找到相邻重复元素
  if (it == v.end()) {
    cout << "没找到" << endl;  // 没有相邻重复元素
  } else {
    // 输出第一个重复的值（这里是 3）
    cout << "找到相邻重复元素: " << *it << endl;
  }
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}