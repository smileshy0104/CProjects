#include <iostream>   // 引入输入输出流库
#include <string>     // 引入字符串库
using namespace std;  // 使用标准命名空间

//* 虚析构和纯虚析构

/*
多态使用的时候，如果子类中有属性---开辟到堆区，那么父类指针在释放的时---无法调用到子类的析构代码

**解决方法**:将父类中的----析构函数改为---虚析构或者纯虚析构

虚析构和纯析构共性:
- 可以解决父类指针释放子类对象，
- 都需要有具体的含函数实现

虚析构和纯虚构的区别：
- 如果是---纯虚析构，该类属于抽象类，无法实例化对象
*/

/*
**虚析构语法**;
virtual ~类名(){}     例如：virtual ~Animal(){};

**纯虚析构语法**：
virtual ~类名() = 0;  例如：virtual ~Animal() = 0;
类名::~类名(){}        例如：Cat::~Cat(){}

*/
class Animal {
 public:
  Animal() { cout << "Animal的构造函数调用" << endl; }  // 构造函数

  // 利用虚析构可以解决父类指针释放对象时不干净的问题
  /*
  virtual ~Animal()
  {
          cout << "Animal的析构函数调用" << endl;
  }
  */

  // 纯虚析构，需要声明也需要实现
  //* 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
  virtual ~Animal() = 0;

  // 纯虚函数，不需要实现
  virtual void speak() = 0;
};

// 纯虚析构函数的实现
Animal::~Animal() { cout << "Animal纯析构函数调用" << endl; }

// 子类 Cat 继承自 Animal
class Cat : public Animal {
 public:
  // 构造函数，初始化小猫的名字
  Cat(string name) {
    m_Name = new string(name);  // 在堆区创建名字
  }

  // 重写父类的纯虚函数 speak
  virtual void speak() override {
    cout << "Cat的构造函数调用" << endl;      // 输出提示信息
    cout << *m_Name << "小猫在说话" << endl;  // 输出小猫的名字和说话内容
  }

  // 析构函数，释放堆区资源
  ~Cat() {
    if (m_Name != NULL) {                   // 检查指针是否为空
      cout << "Cat的析构函数调用" << endl;  // 输出提示信息
      delete m_Name;                        // 释放堆区资源
      m_Name = NULL;                        // 将指针置空
    }
  }

  string* m_Name;  // 堆区存储的小猫名字
};

// 测试函数 test01
void test01() {
  Animal* animal = new Cat("Tom");  // 父类指针指向子类对象
  animal->speak();                  // 调用子类的 speak 方法（多态）

  /*
  父类的指针在析构的时候，不会调用子类中的析构函数，
  导致子类如果有堆区属性，会出现内存的泄漏情况。
  解决:将父类的析构函数改为虚析构
  */
  delete animal;  // 释放对象，由于父类有虚析构，会正确调用子类的析构函数
}

int main(void) {
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}