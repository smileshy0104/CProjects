#include <algorithm>  // 提供排序算法 sort
#include <ctime>      // 提供时间相关函数，用于随机数种子
#include <deque>      // 使用 deque 容器存储评委打分
#include <iostream>   // 控制台输入输出
#include <string>     // 字符串处理
#include <vector>     // 使用 vector 存储选手信息
using namespace std;

// 定义一个 Person 类，表示选手
class Person {
 public:
  Person(string name, int score) {
    this->m_Name = name;    // 初始化姓名
    this->m_Score = score;  // 初始化得分
  }

  string m_Name;  // 姓名
  int m_Score;    // 最终得分
};

// vector赋值
void PrintVector(vector<Person>& v) {
  for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
    cout << "姓名:" << it->m_Name << " 得分:" << it->m_Score << endl;
  }
  cout << endl;
}

// 创建5名选手并加入 vector 容器中
void CreatPerson(vector<Person>& v) {
  string nameSeed = "ABCDE";  // 名字后缀
  for (int i = 0; i < 5; i++) {
    string name = "选手";  // 基础名字
    name += nameSeed[i];   // 拼接为完整名字如“选手A”

    int score = 0;          // 初始得分为0
    Person p(name, score);  // 创建选手对象
    v.push_back(p);         // 添加到 vector 中
  }
}

// 给每位选手打分（模拟10个评委打分、去掉最高最低、求平均）
void setScroe(vector<Person>& v) {
  // 遍历所有选手
  for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
    // 创建一个双端队列来保存10个分数
    deque<int> d;
    for (int i = 0; i < 10; i++) {
      int score = rand() % 41 + 60;  // 生成 [60, 100] 范围内的随机分数
      d.push_back(score);            // 加入 deque
    }

    // 对分数进行排序
    sort(d.begin(), d.end());

    // 去掉最低分和最高分
    d.pop_front();  // 去掉最小值
    d.pop_back();   // 去掉最大值

    // 计算剩余分数的总和
    int sum = 0;
    for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
      sum += *dit;  // 累加所有有效分数
    }

    // 计算平均分
    int avg = sum / d.size();  // 取整数平均分
    it->m_Score = avg;         // 将平均分赋给当前选手
  }
}

// 显示所有选手的最终得分
void showScore(vector<Person>& v) {
  // 遍历 vector 中的所有选手
  for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
    cout << "姓名:" << it->m_Name << " 得分:" << it->m_Score << endl;
  }
}

int main(void) {
  // 设置随机数种子，确保每次运行生成不同的随机数
  srand((unsigned int)time(NULL));

  // 创建一个 vector 容器，用于存放选手对象
  cout << "创建5名选手..." << endl;
  vector<Person> v;
  CreatPerson(v);  // 创建5名选手
  PrintVector(v);  // 打印所有选手

  cout << "给每位选手打分..." << endl;
  // 给每位选手打分
  setScroe(v);

  cout << "最终得分..." << endl;
  // 显示最终得分
  showScore(v);

  system("pause");  // 暂停程序（Windows下可用）
  return 0;         // 程序正常结束
}