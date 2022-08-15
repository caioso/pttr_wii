/* includes */
#include "basic_game_object.h"

namespace base {
  BasicGameObject::BasicGameObject(float x, float y) {
    this->x = 0.0f;
    this->y = 0.0f;
  }

  void BasicGameObject::render(float offset_x, float offset_y) { }
  void BasicGameObject::run(void) { }
}