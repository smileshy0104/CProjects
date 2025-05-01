#include <iostream>  // 输入输出流库
#include <map>       // map 容器头文件
using namespace std;

// 打印 map 内容的辅助函数
void PrintMap(map<int, int>& m) {
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << "key=" << it->first << " value=" << it->second << endl;
  }
  cout << endl;
}

void test01() {
  // 创建一个空的 map 容器，键值对类型为 <int, int>
  map<int, int> m1;

  // 插入元素的四种方式

  // 第一种：使用 pair 构造插入
  m1.insert(pair<int, int>(1, 10));

  // 第二种：使用 make_pair 插入
  m1.insert(make_pair(2, 20));

  // 第三种：使用 map::value_type 插入
  m1.insert(map<int, int>::value_type(3, 30));

  // 第四种：通过 [] 操作符赋值（不推荐用于插入，适用于修改或访问已知 key）
  // 注意：如果 key 不存在，会自动创建一个默认值为 0 的键值对，然后赋值为 40
  m1[4] = 40;

  // 验证 key=4 的值是否插入成功
  cout << m1[4] << endl;  // 输出 40

  // 打印当前 map 内容
  PrintMap(m1);

  // 删除第一个元素（迭代器指向的位置）
  m1.erase(m1.begin());
  PrintMap(m1);

  // 删除 key 为 3 的元素
  m1.erase(3);
  PrintMap(m1);

  // 清空所有元素（方式一：指定区间）
  m1.erase(m1.begin(), m1.end());
  PrintMap(m1);

  // 清空 map（方式二：clear）
  m1.clear();
  PrintMap(m1);
}

int main(void) {
  test01();  // 调用测试函数

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 程序正常结束
}