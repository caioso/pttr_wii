#pragma once

/* includes */
#include <grrlib.h>

namespace utils {
  class Draw {
  /* public methods */
  public:
    static void clear_screen(void);
    static void draw_filled_rectangle(
      float x, float y, float w, float h, uint32_t c);
    static constexpr uint32_t make_rgba(
      uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        return (r << 24) | (g << 16) | (b << 8) | a;
      }
  };
}