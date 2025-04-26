#include <ctime>
#include <iostream>
#include <string>
using namespace std;
struct Hero {
  string name;
  int age;
  string categories;
};
int main(void) {
  struct Hero heroArry[5] = {
      {"欣南", 20, "火"}, {"东杉", 24, "木"}, {"北淼", 23, "水"},
      {"坤中", 18, "土"}, {"西昭", 22, "金"},
  };
  int len = sizeof(heroArry) / sizeof(heroArry[0]);
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1 - i; j++) {
      Hero temp;
      if (heroArry[j].age > heroArry[j + 1].age) {
        temp = heroArry[j];
        heroArry[j] = heroArry[j + 1];
        heroArry[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < len; i++) {
    cout << heroArry[i].name << heroArry[i].age << heroArry[i].categories
         << endl;
  }
  system("pause");
  return 0;
}
