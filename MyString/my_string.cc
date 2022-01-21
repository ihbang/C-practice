/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     C++ language practice #1 "MyString"
 * @file      my_string.h
 * @reference https://modoocode.com/198
 */

// Self header
#include "my_string.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <new>

// return string length
size_t MyString::length() const { return length_; }

// return a size of allocated memory for string
size_t MyString::capacity() const { return capacity_; }

// return N-th character of the string
char MyString::at(int n) const {
  if (n < 0 || n >= length_)
    return NULL;
  else
    return c_str_[n];
}

void MyString::print() const {
  for (int i = 0; i < length_; ++i) {
    std::cout << c_str_[i];
  }
}

void MyString::println() const {
  for (int i = 0; i < length_; ++i) {
    std::cout << c_str_[i];
  }
  std::cout << std::endl;
}

// if a capacity of string is larger than requested length, do nothing
// else reallocate memory fit to len
MyString& MyString::Reserve(size_t cap) {
  if (capacity_ < cap) {
    char* prev_c_str = c_str_;
    c_str_ = new char[cap];
    capacity_ = cap;

    for (int i = 0; i < length_; ++i) {
      c_str_[i] = prev_c_str[i];
    }
    delete[] prev_c_str;
  }
  return *this;
}

// replace string with new string
MyString& MyString::Assign(const MyString& str) {
  size_t len = str.length();

  if (capacity_ < len) {
    size_t cap = std::max(len, 2 * capacity_);
    delete[] c_str_;
    c_str_ = new char[cap];
    capacity_ = cap;
  }

  for (int i = 0; i < len; ++i) {
    c_str_[i] = str.at(i);
  }
  length_ = len;

  return *this;
}

MyString& MyString::Assign(const char* str) {
  MyString tmp(str);

  return Assign(tmp);
}

// insert characters into middle of the string
MyString& MyString::Insert(int pos, const MyString& str) {
  char* prev_c_str = c_str_;
  size_t len = length_ + str.length();
  bool realloced = false;

  if (capacity_ < len) {
    size_t cap = std::max(len, 2 * capacity_);
    c_str_ = new char[cap];
    capacity_ = cap;
    realloced = true;
  }

  for (int i = length_ - 1; i >= pos; --i) {
    c_str_[i + str.length()] = prev_c_str[i];
  }
  for (int i = 0; i < str.length(); ++i) {
    c_str_[pos + i] = str.at(i);
  }
  length_ = len;
  if (realloced) delete[] prev_c_str;

  return *this;
}

MyString& MyString::Insert(int pos, const char* str) {
  MyString tmp(str);

  return Insert(pos, tmp);
}

MyString& MyString::Insert(int pos, char c) {
  MyString tmp(c);

  return Insert(pos, c);
}

// erase n characters from pos
MyString& MyString::Erase(int pos, int n) {
  if (pos < 0 || n < 1 || pos + n > length_) {
    std::cout << "ERROR: Invalid position or length (MyString::Erase), pos="
              << pos << "length=" << n << std::endl;
  } else {
    for (int i = pos + n; i < length_; ++i) {
      c_str_[i - n] = c_str_[i];
    }
    length_ -= n;
  }
  return *this;
}

// maximum length of prefix equivalent to suffix
int* KmpFailFunc(const MyString& str) {
  int i = 1, j = 0;
  size_t len = str.length();
  int* fail_func = new int[len];

  fail_func[0] = 0;
  while (i < len) {
    if (j == 0 && str.at(i) != str.at(j)) {
      fail_func[i++] = 0;
    } else if (str.at(i) != str.at(j)) {
      j = fail_func[j - 1];
    } else {
      fail_func[i++] = ++j;
    }
  }
  fail_func[0] = -1;
  return fail_func;
}

// find substring with KMP algorithm
int MyString::Find(const int pos, const MyString& str) const {
  if (pos < 0 || pos >= length_) {
    std::cout << "ERROR: Invalid position (MyString::Find), pos=" << pos
              << std::endl;
    return -1;
  }
  int* fail_func = KmpFailFunc(str);
  int i = pos, j = 0;

  while (c_str_[i] != str.at(0)) i++;

  while (i < length_) {
    while (j > 0 && c_str_[i] != str.at(j)) {
      j = fail_func[j - 1];
    }
    if (c_str_[i] == str.at(j)) {
      if (j == str.length() - 1) {
        return i - str.length() + 1;
      } else {
        i++;
        j++;
      }
    } else {
      i++;
    }
  }
  return -1;
}

int MyString::Find(int pos, const char* str) const {
  MyString tmp(str);

  return Find(pos, tmp);
}

int MyString::Find(int pos, char c) const {
  MyString tmp(c);

  return Find(pos, tmp);
}

int MyString::Compare(const MyString& str) const {
  for (int i = 0; i < std::min(length_, str.length()); ++i) {
    if (c_str_[i] != str.at(i)) return c_str_[i] - str.at(i);
  }
  return length_ - str.length();
}

int main() {
  std::cout << "Test case #1" << std::endl;
  MyString str1("hello world!");
  MyString str2(str1);

  str1.println();
  str2.println();

  std::cout << "\nTest case #2" << std::endl;
  str1.Reserve(20);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  std::cout << "\nTest case #3" << std::endl;
  str1.Assign("very very very long string");

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  std::cout << "\nTest case #4" << std::endl;
  str1.Insert(5, "long but not ");

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  std::cout << "\nTest case #5" << std::endl;
  str1.Erase(18, 5);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  std::cout << "\nTest case #6" << std::endl;
  int idx1 = str1.Find(0, "very");
  int idx2 = str1.Find(idx1 + 1, "very");
  int idx3 = str1.Find(idx2 + 1, "very");

  std::cout << idx1 << " " << idx2 << " " << idx3 << std::endl;

  std::cout << "\nTest case #7" << std::endl;
  MyString str3(str1);
  MyString str4("very very very very");

  std::cout << str1.Compare(str2) << " " << str1.Compare(str3) << " "
            << str1.Compare(str4) << std::endl;
}
