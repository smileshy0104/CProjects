#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

// 公共继承示例
class Base1 {  // 定义父类Base1
 public:
  int m_A;  // 公有成员变量m_A

 protected:
  int m_B;  // 保护成员变量m_B

 private:
  int m_C;  // 私有成员变量m_C
};

class Son1 : public Base1 {  // 子类Son1，公共继承自Base1
 public:
  void func() {
    m_A = 10;  // 父类中的公有权限成员，在子类中依然是公有权限，可以访问
    m_B = 20;  // 父类中的保护权限成员，在子类中依然是保护权限，可以访问
    // m_C = 10; // 父类中的私有权限成员，子类无法访问
  }
};

void test01() {
  Son1 son1;
  son1.m_A = 100;  // 子类中的公有成员（从父类继承而来）可以在类外访问
  // son1.m_B = 100; // 保护权限的内容在类外无法访问
}

// 保护继承示例
class Base2 {  // 定义父类Base2
 public:
  int m_A;  // 公有成员变量m_A

 protected:
  int m_B;  // 保护成员变量m_B

 private:
  int m_C;  // 私有成员变量m_C
};

class Son2 : protected Base2 {  // 子类Son2，保护继承自Base2
 public:
  void func() {
    // 父类中公有权限的成员，因为是保护继承，到子类中变为保护权限，可以访问
    m_A = 100;
    // 父类中保护权限的成员，保护继承后到了子类还是保护权限，可以访问
    m_B = 100;
    // m_C = 100; // 父类中的私有成员子类无法访问
  }
};

void test02() {
  Son2 son2;
  // 保护权限的内容在类外无法访问，所以在son2中m_A也访问不到了
}

// 私有继承示例
class Base3 {  // 定义父类Base3
 public:
  int m_A;  // 公有成员变量m_A

 protected:
  int m_B;  // 保护成员变量m_B

 private:
  int m_C;  // 私有成员变量m_C
};

class Son3 : private Base3 {  // 子类Son3，私有继承自Base3
 public:
  void func() {
    m_A = 100;  // 父类中公有成员，私有继承后，到了子类变为私有成员，可以访问
    m_B = 100;  // 父类中保护成员，私有继承后，到了子类变为私有成员，可以访问
    // m_C = 100; // 父类的私有权限成员仍然无法访问
  }
};

void test03() {
  Son3 son3;
  // 私有成员在类外无法访问
}

// 验证Son3私有继承后成员是否变成了私有属性
class GrandSon3 : public Son3 {  // 子类GrandSon3，公共继承自Son3
 public:
  void func() {
    // 到了Son3中，m_A、m_B、m_C全是私有成员，子类GrandSon3无法访问
  }
};

int main(void) {    // 主函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}