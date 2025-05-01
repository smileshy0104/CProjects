#include <algorithm>  // 提供 sort、find_if 等算法
#include <iostream>   // 输入输出流库
#include <vector>     // 使用 vector 容器
using namespace std;

// 自定义二元谓词类：用于控制排序规则
class MyCompare {
 public:
  // 重载 () 运算符，使其可以像函数一样调用
  // 接收两个 int 参数，返回 bool 值
  bool operator()(int val1, int val2) {
    return val1 > val2;  // 如果 val1 大于 val2，则排在前面，实现降序排序
  }
};

void test01() {
  // 创建一个 vector<int> 容器，并插入一些整数
  vector<int> v;
  v.push_back(10);
  v.push_back(40);
  v.push_back(20);
  v.push_back(30);
  v.push_back(50);

  // 第一次排序：默认升序排序（使用 less<int>()）
  sort(v.begin(), v.end());

  // 打印升序排序结果
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // 第二次排序：使用自定义二元谓词 MyCompare，实现降序排序
  sort(v.begin(), v.end(), MyCompare());

  // 打印降序排序结果
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}