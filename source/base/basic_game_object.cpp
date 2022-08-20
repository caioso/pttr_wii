/* includes */
#include "basic_game_object.h"

using namespace utils;

namespace base {
  BasicGameObject::BasicGameObject(float x, float y) {
    this->pos = Point2D::make_point2d(x, y);
  }

  BasicGameObject::BasicGameObject(Point2D position) {
    this->pos = position;
  }

  void BasicGameObject::render([[maybe_unused]] float offset_x,
                               [[maybe_unused]] float offset_y) { }
  void BasicGameObject::run(void) { }
}