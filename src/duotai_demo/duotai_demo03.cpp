#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

// 多态案例-制作饮品

// 定义抽象饮品类 AbstractDrinking
class AbstractDrinking {
 public:
  virtual void Boil() = 0;          // 纯虚函数，煮水操作，子类必须实现
  virtual void Brew() = 0;          // 纯虚函数，冲泡操作，子类必须实现
  virtual void Pour() = 0;          // 纯虚函数，倒入杯中操作，子类必须实现
  virtual void PutSomething() = 0;  // 纯虚函数，加入辅料操作，子类必须实现

  // 制作饮品流程
  void makeDrink() {
    Boil();          // 调用煮水操作
    Brew();          // 调用冲泡操作
    Pour();          // 调用倒入杯中操作
    PutSomething();  // 调用加入辅料操作
  }
};

// 制作咖啡类，继承自 AbstractDrinking
class Coffee : public AbstractDrinking {
 public:
  void Boil() override { cout << "把水煮开" << endl; }  // 实现煮水操作
  void Brew() override { cout << "冲泡咖啡" << endl; }  // 实现冲泡操作
  void Pour() override { cout << "倒入杯中" << endl; }  // 实现倒入杯中操作
  void PutSomething() override {
    cout << "加入糖和牛奶" << endl;
  }  // 实现加入辅料操作
};

// 制作茶水类，继承自 AbstractDrinking
class Tea : public AbstractDrinking {
 public:
  void Boil() override { cout << "把矿泉水煮开" << endl; }  // 实现煮水操作
  void Brew() override { cout << "冲泡茶叶" << endl; }      // 实现冲泡操作
  void Pour() override { cout << "倒入杯中" << endl; }      // 实现倒入杯中操作
  void PutSomething() override {
    cout << "加入柠檬" << endl;
  }  // 实现加入辅料操作
};

// 制作函数，传入抽象类指针
void DoWork(AbstractDrinking* abs) {  // 父类指针指向子类对象
  abs->makeDrink();                   // 调用制作饮品流程
  delete abs;                         // 手动释放堆区内存
}

// 测试函数 test
void test() {
  DoWork(new Coffee);  // 制作咖啡
  cout << "------我是分割线------" << endl;
  DoWork(new Tea);  // 制作茶水
}

int main(void) {
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}