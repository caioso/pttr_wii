#pragma once

namespace utils {
  struct Point2D {
    Point2D() = default;
    Point2D(float x, float y);
    Point2D operator+(Point2D other_point);
    static Point2D make_point2d(float x, float y);

    float x;
    float y;
  };
}