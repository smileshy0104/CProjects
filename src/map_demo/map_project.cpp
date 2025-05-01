#include <ctime>     // 时间函数头文件，用于随机数种子
#include <iostream>  // 输入输出流库
#include <map>       // 使用 multimap 容器进行分组管理
#include <string>    // 字符串处理
#include <vector>    // 使用 vector 存储员工信息
using namespace std;

// 部门编号宏定义（部门常量）
#define CEHUA 0   // 策划部门
#define MEISHU 1  // 美术部门
#define YANFA 2   // 研发部门

// 员工类
class Worker {
 public:
  string m_Name;  // 员工姓名
  int m_Salary;   // 员工工资
};

// 打印 vector 容器中的员工信息
void PrintVector(vector<Worker>& v) {
  for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
    cout << "姓名:" << it->m_Name << "  工资:" << it->m_Salary << endl;
  }
}

// 创建10名员工，并初始化工资和姓名
void CreatWorker(vector<Worker>& v) {
  string NameSeed = "ABCDEFGHIJ";  // 姓名后缀字母 A~J

  for (int i = 0; i < 10; i++) {
    Worker worker;
    worker.m_Name = "员工";        // 基础名字
    worker.m_Name += NameSeed[i];  // 拼接为完整姓名如“员工A”

    worker.m_Salary = rand() % 10000 + 10000;  // 工资范围：[10000, 19999]

    v.push_back(worker);  // 将员工加入 vector 容器
  }
}

// 将员工按照随机部门编号分配到 multimap 中
void SetGroup(vector<Worker>& v, multimap<int, Worker>& m) {
  // 遍历vector 容器
  for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
    int deptId = rand() % 3;           // 随机生成部门编号：0、1、2
    m.insert(make_pair(deptId, *it));  // 将员工插入到对应部门中
  }
}

// 按照部门显示员工信息
void ShowWorkerByGroup(multimap<int, Worker>& m) {
  // 显示策划部门员工
  cout << "策划部门:" << endl;
  multimap<int, Worker>::iterator pos = m.find(CEHUA);  // 找到第一个策划员工
  int count = m.count(CEHUA);                           // 获取策划部门人数
  int index = 0;
  for (; pos != m.end() && index < count; pos++, index++) {
    cout << "姓名:" << pos->second.m_Name << "  工资:" << pos->second.m_Salary
         << endl;
  }

  // 显示美术部门员工
  cout << "美术部门:" << endl;
  pos = m.find(MEISHU);
  count = m.count(MEISHU);
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++) {
    cout << "姓名:" << pos->second.m_Name << "  工资:" << pos->second.m_Salary
         << endl;
  }

  // 显示研发部门员工
  cout << "研发部门:" << endl;
  pos = m.find(YANFA);
  count = m.count(YANFA);
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++) {
    cout << "姓名:" << pos->second.m_Name << "  工资:" << pos->second.m_Salary
         << endl;
  }
}

int main(void) {
  srand((unsigned int)time(NULL));  // 设置随机数种子

  // 创建员工容器并生成10名员工
  vector<Worker> vWorker;
  CreatWorker(vWorker);
  cout << "员工信息如下：" << endl;
  PrintVector(vWorker);

  // 分组管理：使用 multimap 进行部门分类
  multimap<int, Worker> mWorker;
  SetGroup(vWorker, mWorker);

  // 显示每个部门的员工信息
  ShowWorkerByGroup(mWorker);

  system("pause");  // 暂停程序（仅限 Windows 平台）
  return 0;         // 返回 0 表示程序正常结束
}