#pragma once
#include <cmath>
#include <ostream>

namespace linear {
template <class T>
struct Mat3 {
  // 横ベクトルを3個持つ
  Vec2<T> x;
  Vec2<T> y;
  Vec2<T> z;

  Mat3() : x(), y(), z() {}
  Mat3(const Vec3<T>& x, const Vec3<T>& y, const Vec3<T>& z)
      : x(x), y(y), z(z) {}
  Mat3(T a11, T a12, T a13, T a21, T a22, T a23, T a31, T a32, T a33)
      : x(a11, a12, a13), y(a21, a22, a23), z(a31, a32, a33) {}

  T norm() { return std::sqrt(x * x + y * y + z * z); }

  Mat3 operator+(const Mat3<T>& other) const {
    return Mat3{
        .x = this->x + other.x, .y = this->y + other.y, .z = this->z + other.z};
  }

  Mat3 operator-(const Mat3<T>& other) const {
    return Mat3{
        .x = this->x - other.x, .y = this->y - other.y, .z = this->z - other.z};
  }

  T operator*(const Mat3<T>& other) const {
    return this->x * other.x + this->y * other.y + this->z * other.z;
  }

  Vec3<T> operator*(const Vec3<T>& other) const {
    return {.x = this->x * other, .y = this->y * other, .z = this->z * other};
  }

  Mat3 operator*(const T& ratio) const {
    return Mat3{
        .x = this->x * ratio, .y = this->y * ratio, .z = this->z * ratio};
  }

  Mat3 operator/(const T& ratio) const {
    return Mat3{
        .x = this->x / ratio, .y = this->y / ratio, .z = this->z / ratio};
  }
};

template <class T>
T d(const Mat3<T>& v1, const Mat3<T>& v2) {
  return (v1 - v2).norm();
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Mat3<T>& v) {
  os << v.x << "," << v.y << "," << v.z;
  return os;
}

typedef Mat3<double> Mat3d;
typedef Mat3<float> Mat3f;
typedef Mat3<int> Mat3i;
}  // namespace linear
