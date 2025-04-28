#include <iostream>
#include <string>
using namespace std;

// 普通实现页面

// java页面
class Java {
 public:
  void header() { cout << "首页、登录注册" << endl; }
  void footer() { cout << "帮助中心、交流合作" << endl; }
  void left() { cout << "java、python、c++" << endl; }
  void contenet() { cout << "java学科视频" << endl; }
};
class Python {
 public:
  void header() { cout << "首页、登录注册" << endl; }
  void footer() { cout << "帮助中心、交流合作" << endl; }
  void left() { cout << "java、python、c++" << endl; }
  void contenet() { cout << "python学科视频" << endl; }
};
class Cpp {
 public:
  void header() { cout << "首页、登录注册" << endl; }
  void footer() { cout << "帮助中心、交流合作" << endl; }
  void left() { cout << "java、python、c++" << endl; }
  void contenet() { cout << "c++学科视频" << endl; }
};
void test() {
  cout << "java" << endl;
  Java java;
  java.header();
  java.footer();
  java.left();
  java.contenet();

  cout << endl;

  cout << "python" << endl;
  Python python;
  python.header();
  python.footer();
  python.left();
  python.contenet();

  cout << endl;

  cout << "cpp" << endl;
  Cpp cpp;
  cpp.header();
  cpp.footer();
  cpp.left();
  cpp.contenet();
}
int main(void) {
  test();
  system("pause");
  return 0;
}