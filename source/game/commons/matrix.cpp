/* includes */
#include "matrix.h"
#include "draw.h"

using namespace utils;

namespace game::commons {
  Matrix::Matrix(float x, float y) :
    base::BasicGameObject(x, y) {
      this->initialize_matrix();
  }

  void Matrix::render(float offset_x, float offset_y) {
    render_matrix_background(offset_x, offset_y);
    for (auto i = 0llu; i < Constants::matrix_height; ++i) {
      for (auto j = 0llu; j < Constants::matrix_width; ++j) {
        if (this->matrix[i][j] == false) {
          render_empty_block(i, j, offset_x, offset_y);
        } else {
          render_filled_block(i, j, offset_x, offset_y);
        }
      }
    }
  }

  void Matrix::run() {
    /* do nothing for now */
  }

  void Matrix::set_block(size_t x, size_t y) {
    if (x < Constants::matrix_width && y < Constants::matrix_full_height) {
      this->matrix[y][x] = true;
    }
  }

  void Matrix::reset_block(size_t x, size_t y) {
    if (x < Constants::matrix_width && y < Constants::matrix_full_height) {
      this->matrix[y][x] = false;
    }
  }

  /* move these to a 'Matrix renderer class' */
  void Matrix::render_empty_block(
    size_t i, size_t j, float offset_x, float offset_y) {
    if (((j % 2 != 0) && (i % 2 == 0)) ||
        ((j % 2 == 0) && (i % 2 != 0))) {
      return;
    } else {
      Draw::draw_filled_rectangle(
        this->x + offset_x + (j * (Constants::block_width)),
        this->y + offset_y + (i * (Constants::block_height)),
        Constants::block_width, Constants::block_height,
        Draw::make_rgba(0, 0, 0, 64));
    }
  }

  void Matrix::render_filled_block(
    size_t i, size_t j, float offset_x, float offset_y) {
    Draw::draw_filled_rectangle(
      this->x + offset_x + (j * (Constants::block_width)),
      this->y + offset_y + (i * (Constants::block_height)),
      Constants::block_width, Constants::block_height,
      Draw::make_rgba(255, 0, 0, 255));
  }

  void Matrix::render_matrix_background(float offset_x, float offset_y) {
    Draw::draw_filled_rectangle(
          this->x + offset_x,
          this->y + offset_y,
          Constants::block_width * Constants::matrix_width,
          Constants::block_height * Constants::matrix_height,
          Draw::make_rgba(0, 0, 0, 32));
  }
  /* up to therer ^ */

  void Matrix::initialize_matrix(void) {
    for (auto i = 0llu; i < Constants::matrix_full_height; ++i) {
      for (auto j = 0llu; j < Constants::matrix_width; ++j) {
        this->matrix[i][j] = false;
      }
    }
  }
}