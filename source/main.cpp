#include <grrlib.h>
#include <wiiuse/wpad.h>

/* Engine Includes */
#include "base/renderer.h"
#include "utils/utils.h"

int main() {

  GRRLIB_Init();
  WPAD_Init();

  auto x_position = 0.0f;
  auto y_position = 0.0f;

  while(true) {
    /* Clear screen */
    Renderer::clear_screen();

    WPAD_ScanPads();

    /* Render Rectangle */
    Renderer::render_filled_rectangle(
      x_position, y_position, 100, 100,
      Utils::make_rgba(255, 0, 0, 255));

    /* Update input */
    if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_LEFT) {
      x_position -= 1.0f;
    } else if (WPAD_ButtonsHeld(0) & WPAD_BUTTON_RIGHT) {
      x_position += 1.0f;
    }

    if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_UP) {
      y_position -= 1.0f;
    } else if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_DOWN) {
      y_position += 1.0f;
    }

    Renderer::render();
  }

  GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB
  return 0;
}
