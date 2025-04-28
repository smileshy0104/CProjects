#include <iostream>   // 引入输入输出流库
#include <string>     // 引入字符串库
using namespace std;  // 使用标准命名空间

// 公共页面类：定义所有页面共有的功能
class BasePage {
 public:
  void header() { cout << "首页、登录注册" << endl; }      // 页面头部内容
  void footer() { cout << "帮助中心、交流合作" << endl; }  // 页面底部内容
  void left() { cout << "java、python、c++" << endl; }     // 页面左侧导航栏内容
};

// 普通实现页面类：继承自BasePage，添加特定内容
class Common : public BasePage {  // 继承BasePage类
 public:
  void contenet() {
    cout << "普通学科视频" << endl;
  }  // 页面主体内容：普通学科视频
};

// Java页面类：继承自BasePage，添加特定内容
class Java : public BasePage {  // 继承BasePage类
 public:
  void contenet() {
    cout << "java学科视频" << endl;
  }  // 页面主体内容：Java学科视频
};

// Python页面类：继承自BasePage，添加特定内容
class Python : public BasePage {  // 继承BasePage类
 public:
  void contenet() {
    cout << "python学科视频" << endl;
  }  // 页面主体内容：Python学科视频
};

// C++页面类：继承自BasePage，添加特定内容
class Cpp : public BasePage {  // 继承BasePage类
 public:
  void contenet() {
    cout << "c++学科视频" << endl;
  }  // 页面主体内容：C++学科视频
};

void test() {              // 测试函数
  cout << "java" << endl;  // 输出提示信息：当前为Java页面
  Java java;               // 创建Java页面对象
  java.header();           // 调用公共头部内容
  java.footer();           // 调用公共底部内容
  java.left();             // 调用公共左侧导航栏内容
  java.contenet();         // 调用Java页面特定的主体内容

  cout << endl;  // 输出空行，分隔不同页面的输出

  cout << "python" << endl;  // 输出提示信息：当前为Python页面
  Python python;             // 创建Python页面对象
  python.header();           // 调用公共头部内容
  python.footer();           // 调用公共底部内容
  python.left();             // 调用公共左侧导航栏内容
  python.contenet();         // 调用Python页面特定的主体内容

  cout << endl;  // 输出空行，分隔不同页面的输出

  cout << "cpp" << endl;  // 输出提示信息：当前为C++页面
  Cpp cpp;                // 创建C++页面对象
  cpp.header();           // 调用公共头部内容
  cpp.footer();           // 调用公共底部内容
  cpp.left();             // 调用公共左侧导航栏内容
  cpp.contenet();         // 调用C++页面特定的主体内容
}

int main(void) {    // 主函数
  test();           // 调用测试函数
  system("pause");  // 暂停程序，等待用户按键（Windows平台特有）
  return 0;         // 返回0，表示程序正常结束
}