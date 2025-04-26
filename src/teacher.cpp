#include <ctime>
#include <iostream>
#include <string>
using namespace std;
struct Student {
  string name;
  int age;
  int score;
};
struct Teacher {
  string name;
  struct Student sArry[5];
};
void inPutInformation(struct Teacher tArry[], int len) {
  string Name = "ABCDE";
  for (int i = 0; i < len; i++) {
    tArry[i].name = "Teacher_";
    tArry[i].name += Name[i];
    for (int j = 0; j < 5; j++) {
      tArry[i].sArry[j].name = "Student_";
      tArry[i].sArry[j].name += Name[j];
      int random = rand() % 60 + 40;
      tArry[i].sArry[j].score = random;
    }
  }
}
void printInformation(struct Teacher tArry[], int len) {
  for (int i = 0; i < len; i++) {
    cout << "老师的姓名：" << tArry[i].name << endl;
    for (int j = 0; j < 5; j++) {
      cout << "\t学生的姓名：" << tArry[i].sArry[j].name << "考试分数："
           << tArry[i].sArry[j].score << endl;
    }
  }
}
int main(void) {
  srand((unsigned int)time(NULL));
  struct Teacher tArry[3];
  int len = sizeof(tArry) / sizeof(tArry[0]);
  inPutInformation(tArry, len);
  printInformation(tArry, len);
  system("pause");
  return 0;
}
