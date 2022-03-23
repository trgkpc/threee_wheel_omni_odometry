#pragma once
#include <cmath>
#include <ostream>

namespace linear {
template <class T>
struct Vec3 {
  T x;
  T y;
  T z;

  Vec3() : x(0), y(0), z(0) {}
  Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

  T norm() { return std::sqrt(x * x + y * y + z * z); }

  Vec3 operator+(const Vec3<T>& other) const {
    return Vec3{
        .x = this->x + other.x, .y = this->y + other.y, .z = this->z + other.z};
  }

  Vec3 operator-(const Vec3<T>& other) const {
    return Vec3{
        .x = this->x - other.x, .y = this->y - other.y, .z = this->z - other.z};
  }

  T operator*(const Vec3<T>& other) const {
    return this->x * other.x + this->y * other.y + this->z * other.z;
  }

  Vec3 operator*(const T& ratio) const {
    return Vec3{
        .x = this->x * ratio, .y = this->y * ratio, .z = this->z * ratio};
  }

  Vec3 operator/(const T& ratio) const {
    return Vec3{
        .x = this->x / ratio, .y = this->y / ratio, .z = this->z / ratio};
  }
};

template <class T>
T d(const Vec3<T>& v1, const Vec3<T>& v2) {
  return (v1 - v2).norm();
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Vec3<T>& v) {
  os << v.x << "," << v.y << "," << v.z;
  return os;
}

typedef Vec3<double> Vec3d;
typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;
}  // namespace linear
