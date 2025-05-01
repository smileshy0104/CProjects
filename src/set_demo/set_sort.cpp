#include <iostream>  // 输入输出流库
#include <set>       // set 容器头文件
using namespace std;

//* 利用仿函数可以指定set容器的排序规则。

// 自定义比较类 MyCompare，用于改变 set 的排序方式
class MyCompare {
 public:
  // 重载 () 运算符，使其可以像函数一样调用
  // 此处为降序排序（从大到小）
  // vs2019 中需要在函数后加上 const，表示不修改类成员变量
  bool operator()(int v1, int v2) const {
    return v1 > v2;  // 如果 v1 大于 v2，则 v1 排在前面，实现降序排列
  }
};

void test01() {
  // 创建一个 set 容器，并传入自定义比较类 MyCompare，表示使用自定义排序规则
  set<int, MyCompare> s1;

  // 在插入数据前，就已经决定了排序方式（由构造时指定的比较函数对象决定）

  // 插入元素到 set 中
  s1.insert(10);
  s1.insert(20);
  s1.insert(30);
  s1.insert(40);

  // 遍历 set 容器并打印元素
  for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++) {
    cout << *it << " ";  // 输出结果应为：40 30 20 10（按照降序排列）
  }

  cout << endl;
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 系统）
  return 0;         // 返回 0 表示程序正常结束
}