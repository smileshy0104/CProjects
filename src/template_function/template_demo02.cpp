#include <iostream>
using namespace std;

//* 函数模板案例
/*
自动类型推导，必须推导出一致的数据类型T才能使用
模板必须要确定出T的数据类型，才可以使用
*/

// 实现通用的对数组进行排序的函数
// 排序规则：从大到小
// 排序算法：选择排序
// 测试场景：char 数组、int 数组

// 函数模板：用于交换两个变量的值
// T 是通用数据类型，支持任意类型的变量交换
template <class T>
void mySwap(T& a, T& b) {
  T temp = a;  // 临时变量存储 a 的值
  a = b;       // 将 b 的值赋给 a
  b = temp;    // 将临时变量的值赋给 b
}

// 函数模板：对数组进行选择排序（从大到小）
// 参数：
// - arr: 数组指针，表示需要排序的数组
// - len: 整型，表示数组的长度
template <class T>
void mySort(T arr[], int len) {
  for (int i = 0; i < len; i++) {
    int max = i;  // 假设当前下标为最大值的下标
    for (int j = i + 1; j < len; j++) {
      // 如果发现更大的值，则更新最大值的下标
      if (arr[max] < arr[j]) {
        max = j;
      }
    }
    // 如果最大值的下标不是当前假设的下标，则交换
    if (max != i) {
      mySwap(arr[max], arr[i]);  // 调用交换函数模板
    }
  }
}

// 函数模板：打印数组内容
// 参数：
// - arr: 数组指针，表示需要打印的数组
// - len: 整型，表示数组的长度
template <class T>
void myPrint(T arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << endl;  // 按行输出数组元素
  }
}

// 测试函数：对 char 类型数组进行排序并打印
void test01() {
  char charArr[] = "badcfe";                 // 初始化字符数组
  int num = sizeof(charArr) / sizeof(char);  // 计算数组长度
  mySort(charArr, num);                      // 对字符数组进行排序
  myPrint(charArr, num);                     // 打印排序后的字符数组
}

// 测试函数：对 int 类型数组进行排序并打印
void test02() {
  int intArr[] = {2, 3, 78, 9, 7};         // 初始化整型数组
  int num = sizeof(intArr) / sizeof(int);  // 计算数组长度
  mySort(intArr, num);                     // 对整型数组进行排序
  myPrint(intArr, num);                    // 打印排序后的整型数组
}

int main(void) {
  test01();  // 测试字符数组的排序与打印
  test02();  // 测试整型数组的排序与打印
  return 0;  // 程序正常结束
}