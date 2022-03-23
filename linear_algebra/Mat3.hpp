#pragma once
#include <array>
#include <cmath>
#include <ostream>

#include "Vec3.hpp"

namespace linear {
template <class T>
struct Mat3 {
  // 横ベクトルを3個持つ
  Vec3<T> x;
  Vec3<T> y;
  Vec3<T> z;

  Mat3() : x(), y(), z() {}
  Mat3(const Vec3<T>& x, const Vec3<T>& y, const Vec3<T>& z)
      : x(x), y(y), z(z) {}
  Mat3(T a11, T a12, T a13, T a21, T a22, T a23, T a31, T a32, T a33)
      : x(a11, a12, a13), y(a21, a22, a23), z(a31, a32, a33) {}

  T norm() { return std::sqrt(x * x + y * y + z * z); }

  Mat3 transpose() const {
    return Mat3{.x = Vec3<T>{.x = this->x.x, .y = this->y.x, .z = this->z.x},
                .y = Vec3<T>{.x = this->x.y, .y = this->y.y, .z = this->z.y},
                .z = Vec3<T>{.x = this->x.z, .y = this->y.z, .z = this->z.z}};
  }

  Mat3 operator+(const Mat3<T>& other) const {
    return Mat3{
        .x = this->x + other.x, .y = this->y + other.y, .z = this->z + other.z};
  }

  Mat3 operator-(const Mat3<T>& other) const {
    return Mat3{
        .x = this->x - other.x, .y = this->y - other.y, .z = this->z - other.z};
  }

  Vec3<T> operator*(const Vec3<T>& other) const {
    return {.x = this->x * other, .y = this->y * other, .z = this->z * other};
  }

  Mat3 operator*(const Mat3<T>& other) const {
    Mat3<T> other_T = other.transpose();
    Mat3<T> ans_T = {.x = (*this) * other_T.x,
                     .y = (*this) * other_T.y,
                     .z = (*this) * other_T.z};
    return ans_T.transpose();
  }

  Mat3 operator*(const T& ratio) const {
    return Mat3{
        .x = this->x * ratio, .y = this->y * ratio, .z = this->z * ratio};
  }

  Mat3 operator/(const T& ratio) const {
    return Mat3{
        .x = this->x / ratio, .y = this->y / ratio, .z = this->z / ratio};
  }

  std::array<T, 9> write_down() const {
    return std::array<T, 9>{this->x.x, this->x.y, this->x.z,
                            this->y.x, this->y.y, this->y.z,
                            this->z.x, this->z.y, this->z.z};
  }

  std::array<std::array<T, 3>, 3> make_array() const {
    return std::array<std::array<T, 3>, 3>{
        std::array<T, 3>{this->x.x, this->x.y, this->x.z},
        std::array<T, 3>{this->y.x, this->y.y, this->y.z},
        std::array<T, 3>{this->z.x, this->z.y, this->z.z}};
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
