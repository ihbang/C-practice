/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     C++ language practice #3 "Array"
 * @file      array.h
 * @reference https://modoocode.com/204
 */

#ifndef CPP_PRACTICE_ARRAY_H_
#define CPP_PRACTICE_ARRAY_H_

class Array {
 public:
  Array(int* size, int dim) : dimension_(dim) {
    size_ = new int[dim];
    for (int i = 0; i < dim; ++i) {
      size_[i] = size[i];
    }
    head_ = new Node;
    InitNode(head_);
  }
  Array(const Array& arr) : dimension_(arr.dimension_) {
    size_ = new int[dimension_];
    for (int i = 0; i < dimension_; ++i) {
      size_[i] = arr.size_[i];
    }
    head_ = new Node;
    CopyNode(head_, arr.head_);
  }
  ~Array() {
    DelNode(head_);
    delete[] size_;
  }

  void* operator[](int idx);

 private:
  class Node {
   public:
    int data_;
    int level_;
    void* next_;

    Node() : data_(0), level_(0), next_(nullptr) {}
    Node(int n) : data_(n), level_(-1), next_(nullptr) {}

    operator int() { return data_; }
  };
  Node* head_;
  int dimension_;
  int* size_;

  void InitNode(Node* cur);
  void CopyNode(Node* dst, Node* src);
  void DelNode(Node* cur);
};

#endif  // CPP_PRACTICE_ARRAY_H_
