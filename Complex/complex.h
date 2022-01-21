/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     C++ language practice #2 "Complex"
 * @file      complex.h
 * @reference https://modoocode.com/198
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

class Complex {
 public:
  Complex(double real, double img) : real_(real), img_(img) {}

  // init Complex object with string which has "a + bi" form
  explicit Complex(const char* c) : real_(0), img_(0) {
    int16_t pos = INT16_MAX;
    bool has_img = false;
    std::string str(c);

    for (int i = 0; i < str.length(); ++i) {
      switch (str.at(i)) {
        case '+':
        case '-':
          if (i == 0)
            continue;
          else if (pos == INT16_MAX)
            pos = i;
          break;
        case 'i':
          has_img = true;
          if (pos == INT16_MAX) pos = -(i + 1);
          break;
        default:
          continue;
      }
    }

    std::string str1;
    std::string str2;
    if (pos != INT16_MAX) {
      str1 = str.substr(0, std::abs(pos));
      str2 = str.substr(std::abs(pos));
    } else {
      str1 = str;
      str2 = "";
    }

    if (has_img && pos < 0) {
      if (str1 == "i" || str1 == "+i")
        img_ = 1;
      else if (str1 == "-i")
        img_ = -1;
      else
        img_ = std::stod(str1);
      if (str2.length() > 1) real_ = std::stod(str2);
    } else {
      real_ = std::stod(str1);
      if (str2.length() > 1) {
        if (str1 == "i" || str1 == "+i")
          img_ = 1;
        else if (str1 == "-i")
          img_ = -1;
        else
          img_ = std::stod(str2);
      }
    }
  }

  double real() const { return real_; }
  double img() const { return img_; }

  Complex operator+(const Complex& c) const;
  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;
  Complex operator/(const Complex& c) const;

  Complex operator+(const char* c) const;
  Complex operator-(const char* c) const;
  Complex operator*(const char* c) const;
  Complex operator/(const char* c) const;

  Complex& operator+=(const Complex& c);
  Complex& operator-=(const Complex& c);
  Complex& operator*=(const Complex& c);
  Complex& operator/=(const Complex& c);

  Complex& operator+=(const char* c);
  Complex& operator-=(const char* c);
  Complex& operator*=(const char* c);
  Complex& operator/=(const char* c);

  void println() {
    std::cout << "(" << real_ << ", " << img_ << ")" << std::endl;
  }

 private:
  double real_;
  double img_;
};

#endif  // COMPLEX_H_
