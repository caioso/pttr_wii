#pragma once

/* includes */
#include <stddef.h>

namespace game {
  struct Constants {
    /* Game Matrix Settings */
    static const size_t matrix_width = 10;
    static const size_t matrix_height = 20;
    static const size_t buffer_zone_height = 20;
    static constexpr size_t matrix_full_height =
      matrix_height + buffer_zone_height;

    /* Game Rendering */
    static constexpr float block_width = 18.0f;
    static constexpr float block_height = 18.0f;
  };
}