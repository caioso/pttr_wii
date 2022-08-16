#pragma once

/* includes */
#include <array>
#include <cstddef>
#include "basic_game_object.h"
#include "constants.h"

namespace game::commons {
  class Matrix : public base::BasicGameObject {
  public:
    /* public methods */
    Matrix(float x, float y);
    ~Matrix() = default;

    void render(float offset_x, float offset_y) override;
    void run() override;

    void set_block(size_t x, size_t y);
    void reset_block(size_t x, size_t y);

  private:
    /* private methods */
    void initialize_matrix(void);
    void render_empty_block(
      size_t i, size_t j, float offset_x, float offset_y);
    void render_filled_block(
      size_t i, size_t j, float offset_x, float offset_y);
    void render_matrix_background(float offset_x, float offset_y);

    /* From Tetris Design Guidelines */
    std::array<
      std::array<bool, Constants::matrix_width>,
        Constants::matrix_full_height> matrix;
  };
}