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
  Array(int* size, int dim) : size_(size), dimension_(dim) {
    head_ = new Node;
    InitNode(head_);
  }

 private:
  struct Node {
    int level_;
    void* next_;
  };
  Node* head_;
  int dimension_;
  int* size_;

  void InitNode(Node* cur) {
    int size = *(size_ + dimension_ - cur->level_);
    if (cur->level_ == 1) {
      cur->next_ = new int[size];
    } else {
      cur->next_ = new Node[size];
      for (int i = 0; i < size; ++i) {
        static_cast<Node*>(cur->next_ + i)->level_ = cur->level_ - 1;
        InitNode(static_cast<Node*>(cur->next_ + i));
      }
    }
  }
};

#endif  // CPP_PRACTICE_ARRAY_H_
