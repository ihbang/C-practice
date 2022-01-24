/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     C++ language practice #3 "Array"
 * @file      array.h
 * @reference https://modoocode.com/198
 */

#ifndef CPP_PRACTICE_ARRAY_H_
#define CPP_PRACTICE_ARRAY_H_

class Array {
 public:
  explicit Array(Array* parent, int val, int idx)
      : arr_(nullptr), parent_(parent), val_(val), depth_(0), idx_(idx) {}
  Array(Array* parent, int* widths, int depth, int idx)
      : parent_(parent), depth_(depth), idx_(idx) {
    for (int i = 0; i < *widths; ++i) {
      arr_ = new Array(this, widths + 1, depth - 1, i);
    }
  }
  Array(int* widths, int depth) : parent_(nullptr), depth_(depth), idx_(-1) {
    for (int i = 0; i < *widths; ++i) {
      arr_ = new Array(this, widths + 1, depth - 1, i);
    }
  }

  Array& operator=(Array* arr);
  Array& operator=(int val);
  void* operator[](int idx);

 private:
  Array* arr_;
  Array* parent_;
  int val_;
  int width_;
  int depth_;
  int idx_;
};

#endif  // CPP_PRACTICE_ARRAY_H_
