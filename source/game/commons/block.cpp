/* includes */
#include "block.h"
#include "utils/draw.h"

using namespace utils;

namespace game::commons {
  Block::Block(float x, float y, float width, float height, uint32_t color) :
    base::BasicGameObject(x, y),
    width(width),
    height(height),
    color(color) {
  }

  void Block::render(float offset_x, float offset_y) {
    Draw::draw_filled_rectangle(this->x + offset_x, this->y + offset_y,
      this->width, this->height, this->color);
  }

  void Block::run(void) {
    this->x++;
  }
}