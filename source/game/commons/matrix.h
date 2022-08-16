#pragma once

/* includes */
#include <algorithm>
#include <array>
#include <cstddef>
#include <limits>
#include "basic_game_object.h"
#include "block.h"
#include "constants.h"

namespace game::commons {
  class Matrix : public base::BasicGameObject {
  public:
    /* public methods */
    Matrix(float x, float y);
    ~Matrix() = default;

    void render(float offset_x, float offset_y) override;
    void run() override;

    void create_block(float x, float y);
    void destroy_block_by_id(size_t id);

  private:
    /* private methods */
    void initialize_matrix(void);
    void render_matrix_background(float offset_x, float offset_y);
    size_t find_block_allocation_position(void);
    /* From Tetris Design Guidelines */
    size_t block_counter;
    std::array<
      std::array<bool, Constants::matrix_width>,
        Constants::matrix_full_height> logic_matrix;
    std::array<Block,
      Constants::matrix_width * Constants::matrix_full_height> blocks;
  };
}