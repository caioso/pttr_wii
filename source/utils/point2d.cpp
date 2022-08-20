/* includes */
#include "point2d.h"

namespace utils {
  Point2D::Point2D(float x, float y) :
   x(x),
   y(y) {
  }

  Point2D Point2D::operator+(Point2D other_point) {
    return make_point2d(this->x + other_point.x, this->y + other_point.y);
  }

  Point2D Point2D::make_point2d(float x, float y) {
    return Point2D(x, y);
  }
}