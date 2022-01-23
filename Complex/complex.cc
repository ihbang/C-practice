/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     C++ language practice #2 "Complex"
 * @file      complex.cc
 * @reference https://modoocode.com/198
 */

#include "complex.h"

Complex operator+(const Complex& a, const Complex& b) {
  Complex tmp(a.real_ + b.real_, a.img_ + b.img_);
  return tmp;
}

Complex operator-(const Complex& a, const Complex& b) {
  Complex tmp(a.real_ - b.real_, a.img_ - b.img_);
  return tmp;
}

Complex operator*(const Complex& a, const Complex& b) {
  Complex tmp(a.real_ * b.real_ - a.img_ * b.img_,
              a.real_ * b.img_ + a.img_ * b.real_);
  return tmp;
}

Complex operator/(const Complex& a, const Complex& b) {
  Complex tmp((a.real_ * b.real_ + a.img_ * b.img_) /
                  (b.real_ * b.real_ + b.img_ * b.img_),
              (a.img_ * b.real_ - a.real_ * b.img_) /
                  (b.real_ * b.real_ + b.img_ * b.img_));
  return tmp;
}

Complex& Complex::operator+=(const Complex& c) {
  *this = *this + c;
  return *this;
}

Complex& Complex::operator-=(const Complex& c) {
  *this = *this - c;
  return *this;
}

Complex& Complex::operator*=(const Complex& c) {
  *this = *this * c;
  return *this;
}

Complex& Complex::operator/=(const Complex& c) {
  *this = *this / c;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "(" << c.real_ << ", " << c.img_ << ")" << std::endl;
}

int main() {
  Complex c1("i");
  Complex c2("-3+2i");
  Complex c3("-5i+2");
  Complex c4("2i-4");
  Complex c5("2.1");

  std::cout << c1;
  std::cout << c2;
  std::cout << c3;
  std::cout << c4;
  std::cout << c5;

  c2 += "1-4i";
  c3 -= "i+3";
  c4 *= "i";
  c5 /= "2.1i";

  std::cout << c2;
  std::cout << c3;
  std::cout << c4;
  std::cout << c5;
}
