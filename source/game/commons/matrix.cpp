/* includes */
#include "matrix.h"
#include "draw.h"

using namespace utils;
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

  void Matrix::create_block(float x, float y, BlockColor color) {
    auto position = this->find_block_allocation_position();

    if (position != numeric_limits<size_t>::max()) {
      this->blocks[position] = Block(
        (this->block_counter++), x, y,
        Constants::block_width, Constants::block_height,
        color);

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
    }
  }

  void Matrix::render_matrix_background(float offset_x, float offset_y) {
    Draw::draw_filled_rectangle(
          this->x + offset_x,
          this->y + offset_y,
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