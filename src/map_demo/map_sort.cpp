#include <iostream>  // 输入输出流库
#include <map>       // map 容器头文件
using namespace std;

// 自定义比较类 MyCompare，用于改变 map 的排序规则
class MyCompare {
 public:
  // 重载 () 运算符，使其可以作为排序依据
  // 此处实现的是：按键（key）从大到小排序（降序）
  bool operator()(int v1, int v2) const {
    return v1 > v2;  // 如果 v1 大于 v2，则 v1 排在前面
  }
};

// 打印 map 内容的辅助函数
void PrintMap(map<int, int, MyCompare>& m) {
  for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
    cout << "key=" << it->first << " value=" << it->second << endl;
  }
  cout << endl;
}

void test01() {
  // 创建一个 map 容器，并使用自定义比较类 MyCompare 设置排序规则
  // 键值对类型为 <int, int>，排序方式为 key 降序
  map<int, int, MyCompare> m1;

  // 插入几组键值对
  m1.insert(make_pair(1, 10));
  m1.insert(make_pair(2, 20));
  m1.insert(make_pair(3, 30));
  m1.insert(make_pair(4, 40));
  m1.insert(make_pair(5, 50));

  // 打印 map 内容
  // 输出顺序应为 key 从大到小：5、4、3、2、1
  PrintMap(m1);
}
int main(void) {
  test01();
  system("pause");
  return 0;
}
