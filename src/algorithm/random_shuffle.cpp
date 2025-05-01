#include <algorithm>   // 提供 random_shuffle、for_each 等算法
#include <ctime>       // 提供 time 函数，用于生成随机数种子
#include <functional>  // 函数对象支持（可选）
#include <iostream>    // 输入输出流库
#include <vector>      // 使用 vector 容器
using namespace std;

// 自定义打印函数：用于输出每个元素
void myPrint(int val) {
  cout << val << " ";  // 输出当前元素并加空格分隔
}

void test01() {
  // 创建一个 vector<int> 容器，并插入 0~9
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);  // 插入元素
  }

  // 打印原始顺序
  cout << "原始顺序: ";
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;

  // 使用 random_shuffle 对容器中的元素进行随机打乱
  random_shuffle(v.begin(), v.end());

  // 打印打乱后的顺序
  cout << "打乱后顺序: ";
  for_each(v.begin(), v.end(), myPrint);
  cout << endl;
}

int main(void) {
  // 设置随机数种子，确保每次运行结果不同
  srand((unsigned int)time(NULL));

  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}