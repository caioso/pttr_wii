/* includes */
#include "basic_game_object.h"

namespace base {
  BasicGameObject::BasicGameObject(float x, float y) {
    this->x = x;
    this->y = y;
  }

  void BasicGameObject::render([[maybe_unused]] float offset_x,
                               [[maybe_unused]] float offset_y) { }
  void BasicGameObject::run(void) { }
}