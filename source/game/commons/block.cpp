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
    color(BlockColor::no_color) {
  }

  Block::Block(
    size_t id, float x, float y, float width, float height, BlockColor color) :
    base::BasicGameObject(x, y),
    id(id),
    width(width),
    height(height),
    color(color) {
  }

  void Block::render(float offset_x, float offset_y) {
    Draw::draw_filled_rectangle(this->x + offset_x, this->y + offset_y,
      this->width, this->height, this->block_color_to_rgba());
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

  uint32_t Block::block_color_to_rgba(void) {
    switch (this->color) {
      case BlockColor::yellow:
        return Draw::make_rgba(255, 245, 110, 255);
      case BlockColor::light_blue:
        return Draw::make_rgba(103, 245, 235, 255);
      case BlockColor::purple:
        return Draw::make_rgba(200, 111, 247, 255);
      case BlockColor::orange:
        return Draw::make_rgba(252, 172, 73, 255);
      case BlockColor::dark_blue:
        return Draw::make_rgba(66, 139, 235, 255);
      case BlockColor::green:
        return Draw::make_rgba(174, 245, 59, 255);
      case BlockColor::red:
        return Draw::make_rgba(245, 102, 59, 255);
      default:
        return Draw::make_rgba(0, 0, 0, 0);
    }
  }
}