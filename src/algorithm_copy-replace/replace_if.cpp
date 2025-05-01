#include <algorithm>   // 提供 replace_if、for_each 等算法
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义打印函数：用于输出每个元素
void myPrint(int val) {
  cout << val << " ";  // 输出当前元素并加空格分隔
}

// 自定义谓词类：判断整数是否大于30
class Great30 {
 public:
  // 重载 () 运算符，使其可以像函数一样调用
  bool operator()(int val) {
    return val > 30;  // 如果 val 大于30，返回 true
  }
};

void test01() {
  // 创建一个 vector<int> 容器，并插入一些整数
  vector<int> v;
  v.push_back(20);
  v.push_back(10);
  v.push_back(60);
  v.push_back(50);
  v.push_back(30);
  v.push_back(20);

  // 打印替换前的内容
  cout << "替换前" << endl;
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;

  // 使用 replace_if 将所有大于30的元素替换为 3000
  cout << "替换后" << endl;
  replace_if(v.begin(), v.end(), Great30(), 3000);
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}