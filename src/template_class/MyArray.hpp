// 自己的通用的数组类
#pragma once
#include <iostream>
using namespace std;

// 模板类
template <class T>
class MyArray {
 public:
  // 有参构造函数，参数为容量
  MyArray(int capacity) {
    cout << "MyArray的有参构造调用" << endl;
    this->m_Capacity = capacity;               // 初始化容量
    this->m_Size = 0;                          // 初始化大小为0
    this->pAddress = new T[this->m_Capacity];  // 在堆区分配内存
  }

  // 拷贝构造函数
  MyArray(const MyArray& arr) {
    cout << "MyArray的拷贝构造调用" << endl;

    this->m_Capacity = arr.m_Capacity;  // 复制容量
    this->m_Size = arr.m_Size;          // 复制大小

    // 深拷贝
    this->pAddress = new T[arr.m_Capacity];  // 在堆区分配新的内存
    for (int i = 0; i < this->m_Size; i++) {
      this->pAddress[i] = arr.pAddress[i];  // 复制数据
    }
  }

  // 重载赋值运算符，防止浅拷贝问题
  MyArray& operator=(const MyArray& arr) {
    cout << "MyArray的operator=调用" << endl;

    // 先判断原来堆区是否有数据，如果有先释放
    if (this->pAddress != NULL) {
      delete[] this->pAddress;  // 释放原有内存
      this->pAddress = NULL;    // 将指针置为空
      this->m_Capacity = 0;     // 重置容量
      this->m_Size = 0;         // 重置大小
    }

    // 深拷贝
    this->m_Capacity = arr.m_Capacity;       // 复制容量
    this->m_Size = arr.m_Size;               // 复制大小
    this->pAddress = new T[arr.m_Capacity];  // 在堆区分配新的内存
    for (int i = 0; i < this->m_Size; i++) {
      this->pAddress[i] = arr.pAddress[i];  // 复制数据
    }
    return *this;  // 返回当前对象的引用
  }

  // 尾插法
  void PushBack(const T& val) {
    // 判断容量是否等于大小
    if (this->m_Capacity == this->m_Size) {
      return;  // 如果容量已满，直接返回
    }
    this->pAddress[this->m_Size] = val;  // 在数组末尾插入数据
    this->m_Size++;                      // 更新数组大小
  }

  // 尾删法
  void PopBack() {
    // 让用户访问不到最后一个元素，即为尾删，逻辑删除
    if (this->m_Size == 0) {
      return;  // 如果数组为空，直接返回
    }
    this->m_Size--;  // 减少数组大小
  }

  // 通过下标的方式访问数组中的元素
  T& operator[](int index) {
    return this->pAddress[index];  // 返回指定下标的元素
  }

  // 返回数组容量
  int getCapacity() {
    return this->m_Capacity;  // 返回数组容量
  }

  // 返回数组大小
  int getSize() {
    return this->m_Size;  // 返回数组大小
  }

  // 析构函数
  ~MyArray() {
    if (this->pAddress != NULL) {
      // cout << "MyArray的析构函数调用" << endl;
      delete[] this->pAddress;  // 释放堆区内存
      this->pAddress = NULL;    // 将指针置为空
    }
  }

 private:
  T* pAddress;  // 指针指向堆区开辟的真实数组

  int m_Capacity;  // 数组容量

  int m_Size;  // 数组大小
};