/* includes */
#include "draw.h"

namespace utils {
  void Draw::clear_screen(void) {
    GRRLIB_FillScreen(make_rgba(255, 255, 255, 255));
  }

  void Draw::draw_filled_rectangle(
      float x, float y, float w, float h, uint32_t c) {
    GRRLIB_Rectangle(x, y, w, h, c, true);
  }

  void Draw::draw_rectangle_outline(
      float x, float y, float w, float h, uint32_t c) {
    GRRLIB_Rectangle(x, y, w, h, c, false);
  }

  void Draw::draw_polygon(float x, float y) {
    guVector point[] = {{0, 0, 0}, {100, 0, 0}, {100, 100, 0}, {0, 100, 0}};
    uint32_t color[] = {make_rgba(128, 128, 128, 128), make_rgba(128, 128, 128, 128), make_rgba(128, 128, 128, 128), make_rgba(128, 128, 128, 128)};
    GRRLIB_NGoneFilled(point, color, 4);
  }
}