#pragma once
#include "Mat2.hpp"
#include "Mat3.hpp"

namespace linear {
// A must be non-singular matrix
template <class T>
Mat2<T> inverse(const Mat2<T>& A) {
  const auto [a, b, c, d] = A.write_down();
  T det = a * d - b * c;
  return Mat2<T>(d, -b, -c, a) / det;
}

template <class T>
Mat3<T> inverse(const Mat3<T>& A) {
  const auto [a11, a12, a13, a21, a22, a23, a31, a32, a33] = A.write_down();
  T det = a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32 -
          a13 * a22 * a31 - a12 * a21 * a33 - a11 * a23 * a32;
  Vec3<T> x(a22 * a33 - a23 * a32, -a12 * a33 + a13 * a32,
            a12 * a23 - a13 * a22);
  Vec3<T> y(-a21 * a33 + a23 * a31, a11 * a33 - a13 * a31,
            -a11 * a23 + a13 * a21);
  Vec3<T> z(a21 * a32 - a22 * a31, -a11 * a32 + a12 * a31,
            a11 * a22 - a12 * a21);
  return Mat3<T>(x, y, z);
}
}  // namespace linear
