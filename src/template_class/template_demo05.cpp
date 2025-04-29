#include <iostream>
using namespace std;

//* 类模板与继承的关系演示
/*
当类模板碰到继承时，需要注意一下几点：
  - 当子类继承的父类是一个类模板时，----子类在声明的时候，要指定出父类中T的类型
  - 如果不想指定，编译器无法给子类分配内存‘
  - 如果----想灵活指定出父类中T的类型，子类也需要变为类模板
*/

// 基类模板 Base，包含一个泛型成员变量 m
template <class T>
class Base {
  T m;  // 成员变量，类型由模板参数决定
};

// 派生类 Son 继承自 Base<int>
// 注意：必须显式指定父类模板的具体类型，不能保留模板参数 T
class Son : public Base<int> {
  // Son 类继承了 Base<int>，即 Base 中的 T 被具体化为 int
};

void test01() {
  Son s1;  // 创建 Son 对象，此时其父类是 Base<int>
}

// 如果希望子类----在继承时灵活指定父类模板的类型，则子类也必须是一个类模板
template <class T1, class T2>

// Son2 的模板参数 T2 用于指定父类 Base 的模板类型
class Son2 : public Base<T2> {
 public:
  Son2() {
    // 构造函数中输出 T1 和 T2 的类型名称（用于演示）
    cout << "T1的数据类型为: " << typeid(T1).name()
         << endl;  // 输出 T1 的类型名称
    cout << "T2的数据类型为: " << typeid(T2).name()
         << endl;  // 输出 T2 的类型名称
  }

  T1 obj;  // 子类中定义一个 T1 类型的成员变量
};

void test02() {
  // 实例化 Son2 类模板，指定 T1 为 int，T2 为 char
  // 这样 Son2 的父类就是 Base<char>
  Son2<int, char> s2;
}

int main(void) {
  test02();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回程序执行状态
}