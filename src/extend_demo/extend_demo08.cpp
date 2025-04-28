#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

class Animal {  // 定义父类Animal
 public:
  int m_Age;  // 成员变量m_Age
};

// 利用虚继承可以解决菱形继承问题
// 在继承之前加上关键字virtual变为虚继承
// 此时，Animal类称为虚基类

// 羊
class Sheep : virtual public Animal {};  // 羊类，虚继承自Animal

// 驼
class Tuo : virtual public Animal {};  // 驼类，虚继承自Animal

// 羊驼
class SheepTuo : public Sheep, public Tuo {};  // 羊驼类，同时继承自Sheep和Tuo

void test01() {
  SheepTuo st;  // 创建羊驼类对象st

  // 如果没有使用虚继承，由于Sheep和Tuo都继承自Animal，
  // 羊驼类SheepTuo中会有两份m_Age成员变量（一份来自Sheep，一份来自Tuo）。
  // 这会导致资源浪费，并且访问m_Age时需要加作用域来区分。

  // 使用虚继承后，Sheep和Tuo共享同一份Animal类的数据成员m_Age，
  // 因此SheepTuo中只有一份m_Age成员变量。

  st.Sheep::m_Age = 18;  // 通过Sheep的作用域设置m_Age为18
  st.Tuo::m_Age = 28;    // 通过Tuo的作用域设置m_Age为28

  // 当存在菱形继承时，如果两个父类拥有相同的数据成员，需要加作用域来区分
  cout << st.Sheep::m_Age << endl;  // 输出通过Sheep作用域设置的m_Age值
  cout << st.Tuo::m_Age << endl;    // 输出通过Tuo作用域设置的m_Age值

  // 由于使用了虚继承，SheepTuo中只有一份m_Age成员变量
  cout << st.m_Age << endl;  // 直接访问m_Age，输出的是同一份数据
}

int main(void) {    // 主函数
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}