#include <algorithm>   // 提供 transform、for_each 等算法
#include <functional>  // 提供函数对象相关支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义仿函数类：用于将元素值加100
class TransForm {
 public:
  // 重载 () 运算符，实现对每个元素的操作
  int operator()(int val) {
    return val + 100;  // 将传入的整数值加100
  }
};

// 自定义仿函数类：用于打印整数
class MyPrint {
 public:
  // 重载 () 运算符，使其可以像函数一样调用
  void operator()(int val) {
    cout << val << " ";  // 输出整数并加空格分隔
  }
};

void test01() {
  // 创建一个 vector<int> 容器，并插入 0~9
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);  // 插入元素
  }

  // 创建目标容器 vTarget，用于保存转换后的数据
  vector<int> vTarget;

  // 注意：必须提前为目标容器分配足够的空间，否则 transform 可能导致未定义行为
  vTarget.resize(v.size());  // 根据源容器大小调整目标容器容量

  // 使用 transform 对 v 容器中的每个元素应用 TransForm 操作，并存入 vTarget
  transform(v.begin(), v.end(), vTarget.begin(), TransForm());

  // 使用 for_each 遍历 vTarget 容器，并打印所有元素
  for_each(vTarget.begin(), vTarget.end(), MyPrint());
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}