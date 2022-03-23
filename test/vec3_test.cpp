#include <iostream>

#include <linear_algebra/Vec3.hpp>
#include <util/print.hpp>

using linear::Vec3d;
using std::cout, std::cin, std::endl;

int main() {
  auto v = Vec3d(3, 0, 4);
  auto p = Vec3d(4, 0, 3);

  print(v);
  print(p);

  print(v + p);
  print(v - p);
  print(v * p);
  print(v / 2);
  print(v.norm());
  print(d(v, p));
}
