#pragma once
#include <cmath>

#include "Mat2.hpp"

namespace linear {
template <class T>
Mat2<T> Rot(T theta) {
  T cos = std::cos(theta);
  T sin = std::sin(theta);

  return Mat2<T>(cos, -sin, sin, cos);
}
}  // namespace linear
