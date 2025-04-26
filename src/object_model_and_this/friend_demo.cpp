#include <iostream>
#include <string>
using namespace std;

//* 全局函数做友元
// **就是将此函数在类的最上面写一个声明，前面加一个friend。**
/*
在程序中，**有些私有属性也想让类外特殊的一些函数或者类进行访问**，就需要用到友元技术。
友元的目的就是**让一个函数或者类 访问另一个类中的私有元素。**
*/
// 定义一个类 Building，表示一栋房子
class Building {
  // 声明全局函数 goodgay 是 Building 类的好友（friend）
  // 这意味着 goodgay 函数可以访问 Building 类的私有成员
  friend void goodgay(Building* building);

 public:
  // 构造函数，初始化房子的公共区域（客厅）和私密区域（卧室）
  Building() {
    m_SittingRoom = "客厅";  // 初始化公共区域为“客厅”
    m_BedRoom = "卧室";      // 初始化私密区域为“卧室”
  }

 public:
  // 公共成员变量，表示房子的公共区域（客厅）
  string m_SittingRoom;

 private:
  // 私有成员变量，表示房子的私密区域（卧室）
  // 只能通过好友函数或类内部的方法访问
  string m_BedRoom;
};

// 定义全局函数 goodgay，作为 Building 类的好友函数
void goodgay(Building* building) {
  // 访问并输出房子的公共区域（客厅）
  cout << "好基友全局函数正在访问你的" << building->m_SittingRoom << endl;

  // 访问并输出房子的私密区域（卧室）
  // 由于 goodgay 是 Building 的好友函数，因此可以访问私有成员 m_BedRoom
  cout << "好基友全局函数正在访问你的" << building->m_BedRoom << endl;
}

// 测试函数，用于创建 Building 对象并调用好友函数 goodgay
void test() {
  Building building;   // 创建一个 Building 对象
  goodgay(&building);  // 调用好友函数 goodgay，传入 Building 对象的指针
}

int main(void) {
  test();           // 调用测试函数 test
  system("pause");  // 暂停程序，等待用户按键
  return 0;         // 返回 0 表示程序正常结束
}