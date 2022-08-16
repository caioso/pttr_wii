/* includes */
#include "basic_game_object.h"

namespace base {
  BasicGameObject::BasicGameObject(float x, float y) {
    this->x = x;
    this->y = y;
  }

  void BasicGameObject::render(float offset_x, float offset_y) { }
  void BasicGameObject::run(void) { }
}