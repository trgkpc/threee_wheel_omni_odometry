#pragma once
#include "Vec2.hpp"

namespace linear {
template <class T>
struct Mat2 {
  // 横ベクトルを2個持つ
  Vec2<T> x;
  Vec2<T> y;

  Mat2() : x(), y() {}
  Mat2(const Vec2<T>& x, const Vec2<T>& y) : x(x), y(y) {}
  Mat2(T a11, T a12, T a21, T a22) : x(a11, a12), y(a21, a22) {}

  T norm() { return std::sqrt(x * x + y * y); }

  Mat2 operator+(const Mat2<T>& other) const {
    return Mat2{.x = this->x + other.x, .y = this->y + other.y};
  }

  Mat2 operator-(const Mat2<T>& other) const {
    return Mat2{.x = this->x - other.x, .y = this->y - other.y};
  }

  T operator*(const Mat2<T>& other) const {
    return this->x * other.x + this->y * other.y;
  }

  Vec2<T> operator*(const Vec2<T>& other) const {
    return {.x = this->x * other, .y = this->y * other};
  }

  Mat2 operator*(const T& ratio) const {
    return Mat2{.x = this->x * ratio, .y = this->y * ratio};
  }

  Mat2 operator/(const T& ratio) const {
    return Mat2{.x = this->x / ratio, .y = this->y / ratio};
  }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Mat2<T>& v) {
  os << v.x << std::endl << v.y;
  return os;
}

typedef Mat2<double> Mat2d;
typedef Mat2<float> Mat2f;
typedef Mat2<int> Mat2i;
}  // namespace linear
