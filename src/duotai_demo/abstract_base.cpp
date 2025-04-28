#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

// 纯虚函数和抽象类

class Base {
 public:
  // 只要有一个纯虚函数，这个类就称为抽象类
  // 特点：无法实例化对象
  virtual void func() = 0;  // 纯虚函数，注意不要忘记加 `virtual` 关键字
  // 抽象类的子类必须重写父类中的纯虚函数，否则子类也属于抽象类
};

// 子类 Son 继承自 Base
class Son : public Base {
 public:
  // 重写父类的纯虚函数 func
  void func() override { cout << "func函数调用" << endl; }
};

// 测试函数 test
void test() {
  // Base b1; // 错误：抽象类无法实例化对象
  Son s1;               // 子类重写了父类的纯虚函数，可以实例化对象
  Base* abc = new Son;  // 父类指针指向子类对象
  abc->func();          // 调用子类重写的 func 函数（多态）
  delete abc;           // 手动释放堆区内存
}

int main(void) {
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}