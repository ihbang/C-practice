/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     C++ language practice #1 "MyString"
 * @file      my_string.h
 * @reference https://modoocode.com/198
 */

#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <cstring>

class MyString {
 public:
  explicit MyString(char c) : length_(1), capacity_(1) {
    c_str_ = new char;
    *c_str_ = c;
  }
  explicit MyString(const char* str) {
    length_ = std::strlen(str);
    capacity_ = length_;
    c_str_ = new char[length_];

    for (int i = 0; i < length_; ++i) {
      c_str_[i] = str[i];
    }
  }
  explicit MyString(const MyString& str) {
    length_ = str.length();
    capacity_ = length_;
    c_str_ = new char[length_];

    for (int i = 0; i < length_; ++i) {
      c_str_[i] = str.at(i);
    }
  }

  size_t length() const;
  size_t capacity() const;
  char at(int n) const;

  MyString& Reserve(size_t cap);
  MyString& Assign(const MyString& str);
  MyString& Assign(const char* str);
  MyString& Insert(int pos, const MyString& str);
  MyString& Insert(int pos, const char* str);
  MyString& Insert(int pos, char c);
  MyString& Erase(int pos, int n);
  size_t Find(int pos, const MyString& str) const;
  size_t Find(int pos, const char* str) const;
  size_t Find(int pos, char c) const;
  int Compare(const MyString& str) const;

 private:
  char* c_str_;
  size_t length_;
  size_t capacity_;
};

#endif  // MY_STRING_H_
