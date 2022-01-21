/**
 * Copyright 2022 Inhyeok Bang
 *
 * @brief     C++ language practice #2 "Complex"
 * @file      complex.cc
 * @reference https://modoocode.com/198
 */

#include "complex.h"

Complex Complex::operator+(const Complex& c) const {
  Complex tmp(real_ + c.real(), img_ + c.img());
  return tmp;
}

Complex Complex::operator-(const Complex& c) const {
  Complex tmp(real_ - c.real(), img_ - c.img());
  return tmp;
}

Complex Complex::operator*(const Complex& c) const {
  Complex tmp(real_ * c.real() - img_ * c.img(),
              real_ * c.img() + img_ * c.real());
  return tmp;
}

Complex Complex::operator/(const Complex& c) const {
  Complex tmp((real_ * c.real() + img_ * c.img()) /
                  (c.real() * c.real() + c.img() * c.img()),
              (img_ * c.real() - real_ * c.img()) /
                  (c.real() * c.real() + c.img() * c.img()));
  return tmp;
}

Complex Complex::operator+(const char* c) const {
  Complex tmp(c);
  return *this + tmp;
}

Complex Complex::operator-(const char* c) const {
  Complex tmp(c);
  return *this - tmp;
}

Complex Complex::operator*(const char* c) const {
  Complex tmp(c);
  return *this * tmp;
}

Complex Complex::operator/(const char* c) const {
  Complex tmp(c);
  return *this / tmp;
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

Complex& Complex::operator+=(const char* c) {
  Complex tmp(c);
  *this = *this + tmp;
  return *this;
}

Complex& Complex::operator-=(const char* c) {
  Complex tmp(c);
  *this = *this - tmp;
  return *this;
}

Complex& Complex::operator*=(const char* c) {
  Complex tmp(c);
  *this = *this * tmp;
  return *this;
}

Complex& Complex::operator/=(const char* c) {
  Complex tmp(c);
  *this = *this / tmp;
  return *this;
}

int main() {
  Complex c1("i");
  Complex c2("-3+2i");
  Complex c3("-5i+2");
  Complex c4("2i-4");
  Complex c5("2.1");

  c1.println();
  c2.println();
  c3.println();
  c4.println();
  c5.println();

  c2 += "1-4i";
  c3 -= "i+3";
  c4 *= "i";
  c5 /= "2.1i";

  c2.println();
  c3.println();
  c4.println();
  c5.println();
}
