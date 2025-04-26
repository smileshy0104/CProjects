#include <iostream>
#include <string>
using namespace std;

//* 类做友元
//** 一个类在另一个中friend class xx。**
// 前向声明 Building 类，告诉编译器 Building 类会在后面定义
class Building;

// 定义 GoodGay 类，表示一个“好基友”
class GoodGay {
 public:
  // 构造函数，用于初始化对象
  GoodGay();

 public:
  // visit 方法，用于访问 Building 对象的属性（包括私有成员）
  void visit();

  // 指向 Building 对象的指针，GoodGay 可以通过这个指针访问 Building 的成员
  Building* building;
};

// 定义 Building 类，表示一栋房子
class Building {
  // 声明 GoodGay 是 Building 类的好友（friend）
  // 这意味着 GoodGay 类可以访问 Building 类的私有成员
  friend class GoodGay;

 public:
  // 构造函数，用于初始化房子的公共区域和私密区域
  Building();

 public:
  // 公共成员变量，表示房子的公共区域（客厅）
  string m_SittingRoom;

 private:
  // 私有成员变量，表示房子的私密区域（卧室）
  // 只能通过好友类或类内部的方法访问
  string m_BedRoom;
};

// 在类外定义 Building 的构造函数
Building::Building() {
  m_SittingRoom = "客厅";  // 初始化公共区域为“客厅”
  m_BedRoom = "卧室";      // 初始化私密区域为“卧室”
}

// 在类外定义 GoodGay 的构造函数
GoodGay::GoodGay() {
  // 创建一个 Building 对象，并将其地址赋值给 building 指针
  building = new Building;
}

// 在类外定义 GoodGay 的 visit 方法
void GoodGay::visit() {
  // 访问并输出房子的公共区域（客厅）
  cout << "好基友正在访问你的" << building->m_SittingRoom << endl;

  // 访问并输出房子的私密区域（卧室）
  // 由于 GoodGay 是 Building 的好友类，因此可以访问私有成员 m_BedRoom
  cout << "好基友正在访问你的" << building->m_BedRoom << endl;
}

// 测试函数，用于创建 GoodGay 对象并调用其方法
void test() {
  GoodGay gy;  // 创建一个 GoodGay 对象
  gy.visit();  // 调用 visit 方法访问 Building 对象的属性
}

int main(void) {
  test();           // 调用测试函数 test
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回 0 表示程序正常结束
}