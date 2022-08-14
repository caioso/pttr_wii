#include "renderer.h"

#include "../utils/utils.h"

void Renderer::clear_screen(void) {
  GRRLIB_FillScreen(Utils::make_rgba(255, 255, 255, 255));
}

void Renderer::render(void) {
  GRRLIB_Render();
}

void Renderer::render_filled_rectangle(
    float x, float y, float w, float h, uint32_t c) {
  GRRLIB_Rectangle(x, y, w, h, c, true);
}