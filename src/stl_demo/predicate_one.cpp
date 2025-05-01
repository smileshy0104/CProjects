#include <algorithm>  // 提供 find_if 等算法
#include <iostream>   // 输入输出流库
#include <vector>     // 使用 vector 容器
using namespace std;

// 自定义一元谓词类：用于判断一个值是否大于5
class CreaterFive {
 public:
  // 重载 () 运算符，使其可以像函数一样调用
  // 接收一个 int 参数，返回 bool 值
  bool operator()(int val) {
    return val > 5;  // 如果 val 大于5，返回 true
  }
};

void test01() {
  // 创建一个 vector<int> 容器，并插入 0~9
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);  // 插入元素
  }

  // 使用 find_if 查找满足条件的元素（即大于5的数）
  // CreaterFive() 是匿名函数对象（临时对象），作为判断条件传入
  vector<int>::iterator pos = find_if(v.begin(), v.end(), CreaterFive());

  // 判断是否找到符合条件的元素
  if (pos == v.end()) {
    cout << "未找到" << endl;
  } else {
    cout << "找到了，大于5的数字为:" << *pos << endl;
  }
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}