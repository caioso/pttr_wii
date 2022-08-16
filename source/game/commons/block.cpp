/* includes */
#include "block.h"
#include "utils/draw.h"

using namespace utils;

namespace game::commons {
  Block::Block(void) :
    base::BasicGameObject(0, 0),
    id(std::numeric_limits<size_t>::max()),
    width(0),
    height(0),
    color(0) {
  }

  Block::Block(
    size_t id, float x, float y, float width, float height, uint32_t color) :
    base::BasicGameObject(x, y),
    id(id),
    width(width),
    height(height),
    color(color) {
  }

  void Block::render(float offset_x, float offset_y) {
    Draw::draw_filled_rectangle(this->x + offset_x, this->y + offset_y,
      this->width, this->height, this->color);
  }

  void Block::run(void) {
    /* do nothing */
  }

  size_t Block::get_id(void) {
    return this->id;
  }

  Block Block::make_empty_block(void) {
    return Block();
  }
}