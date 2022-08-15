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
}