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

// if a capacity of string is larger than requested length, do nothing
// else reallocate memory fit to len
MyString& MyString::Reserve(size_t cap) {
  if (capacity_ < cap) {
    char* prev_c_str = c_str_;
    cap = std::max(cap, 2 * capacity_);
    c_str_ = new char[cap];

    for (int i = 0; i < length_; ++i) {
      c_str_[i] = prev_c_str[i];
    }
    delete[] prev_c_str;
  }
  return *this;
}

MyString& MyString::Assign(const MyString& str) {
  size_t len = str.length();

  if (capacity_ < len) {
    size_t cap = std::max(len, 2 * capacity_);
    delete[] c_str_;
    c_str_ = new char[cap];
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

MyString& MyString::Insert(int pos, const MyString& str) {
  char* prev_c_str = c_str_;
  size_t len = length_ + str.length();

  if (capacity_ < len) {
    size_t cap = std::max(len, 2 * capacity_);
    c_str_ = new char[cap];
  }

  for (int i = length_ - 1; i >= pos; --i) {
    c_str_[i + str.length()] = prev_c_str[i];
  }
  for (int i = 0; i < str.length(); ++i) {
    c_str_[pos + i] = str.at(i);
  }
  delete[] prev_c_str;

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

MyString& MyString::Erase(int pos, int n) {}

size_t MyString::Find(int pos, const MyString& str) const {}

size_t MyString::Find(int pos, const char* str) const {}

size_t MyString::Find(int pos, char c) const {}

int MyString::Compare(const MyString& str) const {}
