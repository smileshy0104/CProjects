#include <iostream>   // 引入输入输出流库
using namespace std;  // 使用标准命名空间

// 抽象不同零件类

// 抽象 CPU 类
class CPU {
 public:
  virtual void calculate() = 0;  // 纯虚函数，定义计算功能，子类必须实现
  virtual ~CPU() {
  }  // 虚析构函数，确保通过基类指针删除派生类对象时会调用派生类的析构函数
};

// 抽象显卡类
class VideoCard {
 public:
  virtual void display() = 0;  // 纯虚函数，定义显示功能，子类必须实现
  virtual ~VideoCard() {
  }  // 虚析构函数，确保通过基类指针删除派生类对象时会调用派生类的析构函数
};

// 抽象内存条类
class Memory {
 public:
  virtual void storage() = 0;  // 纯虚函数，定义存储功能，子类必须实现
  virtual ~Memory() {
  }  // 虚析构函数，确保通过基类指针删除派生类对象时会调用派生类的析构函数
};

// 电脑类
class Computer {
 public:
  // 构造函数，初始化 CPU、显卡和内存条指针
  Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
    cout << "电脑类构造函数执行！" << endl;
    m_cpu = cpu;  // 初始化 CPU 指针
    m_vc = vc;    // 初始化显卡指针
    m_mem = mem;  // 初始化内存条指针
  }

  // 提供一个工作的函数，让零件工作起来
  void work() {
    cout << "电脑开始工作了！" << endl;
    m_cpu->calculate();  // 调用 CPU 的计算功能
    m_vc->display();     // 调用显卡的显示功能
    m_mem->storage();    // 调用内存条的存储功能
  }

  // 析构函数，释放 CPU、显卡和内存条指针
  ~Computer() {
    cout << "电脑类析构函数执行！" << endl;
    if (m_cpu != NULL) {  // 释放 CPU 指针
      delete m_cpu;
      m_cpu = NULL;
    }
    if (m_vc != NULL) {  // 释放显卡指针
      delete m_vc;
      m_vc = NULL;
    }
    if (m_mem != NULL) {  // 释放内存条指针
      delete m_mem;
      m_mem = NULL;
    }
  }

 private:
  CPU* m_cpu;       // CPU 零件指针
  VideoCard* m_vc;  // 显卡零件指针
  Memory* m_mem;    // 内存条零件指针
};

// 具体厂商实现

// Intel 厂商
class IntelCPU : public CPU {
 public:
  void calculate() override {
    cout << "Intel的CPU开始计算了" << endl;
  }  // 实现计算功能
};

class IntelVideoCard : public VideoCard {
 public:
  void display() override {
    cout << "Intel的显卡开始显示了" << endl;
  }  // 实现显示功能
};

class IntelMemory : public Memory {
 public:
  void storage() override {
    cout << "Intel的内存条开始存储了" << endl;
  }  // 实现存储功能
};

// Lenovo 厂商
class LenovoCPU : public CPU {
 public:
  void calculate() override {
    cout << "Lenovo的CPU开始计算了" << endl;
  }  // 实现计算功能
};

class LenovoVideoCard : public VideoCard {
 public:
  void display() override {
    cout << "Lenovo的显卡开始显示了" << endl;
  }  // 实现显示功能
};

class LenovoMemory : public Memory {
 public:
  void storage() override {
    cout << "Lenovo的内存条开始存储了" << endl;
  }  // 实现存储功能
};

// 组装电脑测试
void test01() {
  // 第一台电脑：Intel 品牌
  CPU* intelcpu = new IntelCPU;               // 创建 Intel CPU
  VideoCard* videocard = new IntelVideoCard;  // 创建 Intel 显卡
  Memory* memory = new IntelMemory;           // 创建 Intel 内存条
  Computer* computer1 =
      new Computer(intelcpu, videocard, memory);  // 组装第一台电脑
  computer1->work();                              // 让第一台电脑工作
  delete computer1;                               // 删除第一台电脑

  cout << "------我是分割线------" << endl;

  // 第二台电脑：Lenovo 品牌
  Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard,
                                     new LenovoMemory);  // 组装第二台电脑
  computer2->work();                                     // 让第二台电脑工作
  delete computer2;                                      // 删除第二台电脑

  cout << "------我是分割线------" << endl;

  // 第三台电脑：混合品牌（Lenovo CPU + Intel 显卡 + Lenovo 内存条）
  Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard,
                                     new LenovoMemory);  // 组装第三台电脑
  computer3->work();                                     // 让第三台电脑工作
  delete computer3;                                      // 删除第三台电脑
}

int main(void) {
  test01();         // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（便于观察输出）
  return 0;         // 返回 0 表示程序正常结束
}