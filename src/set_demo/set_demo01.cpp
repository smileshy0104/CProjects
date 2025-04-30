#include <iostream>  // 控制台输入输出
#include <set>       // 包含 set 和 multiset 容器
using namespace std;

// 打印 multiset 内容的函数
void PrintMultiSet(multiset<int>& ms) {
  for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
    cout << *it << " ";  // 输出每个元素，空格分隔
  }
  cout << endl;  // 换行
}

void test01() {
  // 创建一个 set 容器（不允许重复元素）
  set<int> s1;

  // 插入第一个元素 10，并通过 pair 接收插入结果
  pair<set<int>::iterator, bool> ret = s1.insert(10);

  if (ret.second) {
    cout << "插入成功" << endl;
  } else {
    cout << "插入失败" << endl;
  }

  // 尝试再次插入相同的元素 10
  ret = s1.insert(10);

  if (ret.second) {
    cout << "插入成功" << endl;
  } else {
    cout << "插入失败" << endl;
  }

  // 创建一个 multiset 容器（允许重复元素）
  multiset<int> ms;

  // 插入两个相同值 10 的元素
  ms.insert(10);
  ms.insert(10);

  // 打印 multiset 中的内容
  PrintMultiSet(ms);
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 系统）
  return 0;         // 程序正常结束
}