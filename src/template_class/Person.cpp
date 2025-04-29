#include <iostream>

#include "Person.hpp"
using namespace std;
#include <string>

void test01() {
  Person<string, int> p1("伞兵", 18);
  p1.showPerson();
}
int main(void) {
  test01();
  system("pause");
  return 0;
}
