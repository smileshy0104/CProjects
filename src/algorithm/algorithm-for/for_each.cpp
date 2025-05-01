#include <algorithm>   // 提供 for_each、sort 等算法
#include <functional>  // 提供函数对象相关支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 普通函数：用于打印一个整数
void Print01(int val) {
  cout << val << " ";  // 输出整数并加空格分隔
}

// 自定义仿函数类：用于打印一个整数
class Print02 {
 public:
  // 重载 () 运算符，使其像函数一样调用
  void operator()(int val) {
    cout << val << "-";  // 输出整数并加空格分隔
  }
};

// 测试函数
void test01() {
  // 创建一个 vector<int> 容器，并插入 0~9
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);  // 插入元素
  }

  // 使用 for_each 遍历容器，并对每个元素调用 Print01 函数
  for_each(v.begin(), v.end(), Print01);
  cout << endl;

  // 使用 for_each 遍历容器，并对每个元素调用 Print02 仿函数
  // 注意：Print02() 是临时对象，作为函数对象传入
  for_each(v.begin(), v.end(), Print02());
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}