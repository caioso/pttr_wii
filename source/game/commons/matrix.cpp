/* includes */
#include "matrix.h"
#include "draw.h"
#include "physics/collision_detector.h"

using namespace utils;
using namespace base::physics;
using namespace game;
using namespace game::commons;
using namespace std;

namespace game::commons {
  Matrix::Matrix(float x, float y) :
    base::BasicGameObject(x, y),
    block_counter(0llu) {
      this->initialize_matrix();
  }

  void Matrix::render(float offset_x, float offset_y) {
    render_matrix_background(offset_x, offset_y);
  }

  void Matrix::run() {
    /* do nothing for now */
  }

  void Matrix::initialize_matrix(
      std::array<
        std::array<BlockColor, Constants::matrix_height>,
          Constants::matrix_width>& initialization_template) {
    for (auto i = 0llu; i < Constants::matrix_height; ++i) {
      for (auto j = 0llu; j < Constants::matrix_width; ++j) {
        if (initialization_template[i][j] != BlockColor::no_color) {
          create_block(j, i, initialization_template[i][j]);
        }
      }
    }
  }

  void Matrix::create_block(int x, int y, BlockColor color) {
    auto position = this->find_block_allocation_position();

    if (position != numeric_limits<size_t>::max()) {
      this->blocks[position] = Block(
        (this->block_counter++), x * Constants::block_width,
        y * Constants::block_height, Constants::block_width,
        Constants::block_height, Constants::block_width,
        Constants::block_height, color);

      CollisionDetector::register_collider(&this->blocks[position]);
      this->add_child(&this->blocks[position]);
    }
  }

  void Matrix::destroy_block_by_id(size_t id) {
     auto target = std::find_if(begin(this->blocks), end(this->blocks),
     [id](Block b) -> bool { return b.get_id() == id; });

    if (target != end(this->blocks)) {
      auto position = distance(begin(this->blocks), target);
      this->remove_child(&this->blocks[position]);
      this->blocks[position] = Block::make_empty_block();
      /* Remove Colliders Here */
    }
  }

  void Matrix::render_matrix_background(float offset_x, float offset_y) {
    Draw::draw_filled_rectangle(
          this->pos.x + offset_x,
          this->pos.y + offset_y,
          Constants::block_width * Constants::matrix_width,
          Constants::block_height * Constants::matrix_height,
          Draw::make_rgba(0, 0, 0, 12));
  }

  void Matrix::initialize_matrix(void) {
    for (auto i = 0llu; i < Constants::matrix_full_height; ++i) {
      for (auto j = 0llu; j < Constants::matrix_width; ++j) {
        this->logic_matrix[i][j] = false;
      }
    }
  }

  size_t Matrix::find_block_allocation_position(void) {
    auto position = find_if(begin(this->blocks), end(this->blocks),
    [](Block b) -> bool {return b.get_id() == numeric_limits<size_t>::max();});

    if (position == end(this->blocks)) {
      return numeric_limits<size_t>::max();
    } else {
      return distance(begin(this->blocks), position);
    }
  }
}