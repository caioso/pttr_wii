#pragma once

#include <grrlib.h>

class Renderer {
public:
  static void clear_screen(void);
  static void render(void);
  static void render_filled_rectangle(
    float x, float y, float w, float h, uint32_t c);
};