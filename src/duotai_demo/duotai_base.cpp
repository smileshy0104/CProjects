#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

/*
多态分为两种
- 静态多态:函数重载和运算符重载属于静态多态，复用函数名
- 动态多态:派生类和虚函数实现运行时多态

静态多态和动态多态的区别
- 静态多态的函数地址早绑定 -  编译阶段确定函数地址
- 动态多态的函数地址晚绑定 - 运行阶段确定函数地址
*/
class Animal {  // 定义父类Animal
 public:
  // 加上virtual变成虚函数，实现地址晚绑定（动态多态）
  virtual void speak() {
    cout << "动物在说话" << endl;
  }  // 虚函数：允许子类重写并实现动态多态

  // 没有加virtual，仍然是普通函数，地址早绑定（静态绑定）
  void play() { cout << "动物在玩耍" << endl; }
};

class Cat : public Animal {  // 定义子类Cat，继承自Animal
 public:
  void speak() { cout << "小猫在说话" << endl; }  // 重写父类的speak()函数

  void play() { cout << "小猫在玩耍" << endl; }  // 重写父类的play()函数
};

class Dog : public Animal {  // 定义子类Dog，继承自Animal
 public:
  void speak() { cout << "小狗在说话" << endl; }  // 重写父类的speak()函数

  void play() { cout << "小狗在玩耍" << endl; }  // 重写父类的play()函数
};

// 执行说话的函数
// 地址早绑定：在编译阶段就确定函数地址。
// 如果想让猫或狗说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定。

// 动态多态满足条件：
/*
1. 有继承关系。
2. 子类重写父类的虚函数。
*/

// 重写要求：
// 函数返回值类型、函数名、参数列表完全相同。

// 动态多态的使用：
/*
父类的指针或者引用指向子类的对象。
例如：Animal &animal = cat;
*/

void doSpeak(Animal &animal) {  // 父类引用指向子类对象
  animal.speak();               // 调用speak()函数
}

void doPlay(Animal &animal) {  // 父类引用指向子类对象
  animal.play();               // 调用speak()函数
}

void test01() {
  Cat cat;       // 创建Cat对象cat
  doSpeak(cat);  // 调用doSpeak()，传入cat对象
                 // 输出：小猫在说话（动态多态生效）
  doPlay(cat);
  Dog dog;       // 创建Dog对象dog
  doSpeak(dog);  // 调用doSpeak()，传入dog对象
                 // 输出：小狗在说话（动态多态生效）
  doPlay(dog);
}

int main(void) {    // 主函数
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}