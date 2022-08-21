/* includes */
#include "block.h"
#include "game/constants.h"
#include "utils/draw.h"

using namespace base;
using namespace components;
using namespace utils;

namespace game::commons {
  void BlockRenderer::render_block(Point2D pos, float width, float height,
    float offset_x, float offset_y, BlockColor color) {
      Draw::draw_filled_rectangle(pos.x + offset_x, pos.y + offset_y,
      width, height, this->block_color_to_rgba(color));
  }

  uint32_t BlockRenderer::block_color_to_rgba(BlockColor color) {
    switch (color) {
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


  Block::Block(void) :
    BasicGameObject(0, 0),
    Collider(Constants::block_width, Constants::block_height, &this->pos),
    id(std::numeric_limits<size_t>::max()),
    color(BlockColor::no_color) {
  }

  Block::Block(
    size_t id, float x, float y, float width, float height,
    float collider_width, float collider_height, BlockColor color) :
    BasicGameObject(x, y),
    Collider(collider_width, collider_height, &this->pos),
    id(id),
    render_width(width),
    render_height(height),
    color(color) {
  }

  void Block::render(float offset_x, float offset_y) {
    this->block_renderer.render_block(
      this->pos, this->render_width,
      this->render_height, offset_x, offset_y, this->color);
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