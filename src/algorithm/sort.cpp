#include <algorithm>   // 提供 sort、for_each 等算法
#include <functional>  // 提供 greater<int>() 等函数对象
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

  // 第一次排序：使用默认排序规则（升序）
  sort(v.begin(), v.end());

  // 使用 for_each 遍历并打印排序后的元素
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;

  // 第二次排序：使用 greater<int>() 实现降序排序
  sort(v.begin(), v.end(), greater<int>());

  // 再次遍历并打印降序排列结果
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}