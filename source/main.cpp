#include <grrlib.h>
#include <wiiuse/wpad.h>

/* Engine Includes */
#include "base/basic_game_object.h"
#include "base/control/scheduler.h"
#include "base/graphics/renderer.h"
#include "game/commons/block.h"
#include "utils/draw.h"

using namespace base::control;
using namespace base::graphics;
using namespace game::commons;
using namespace utils;

int main() {

  GRRLIB_Init();
  WPAD_Init();

  auto x_position = 0.0f;
  auto y_position = 0.0f;

  Renderer::initialize();
  Scheduler::initialize();

  /* test only */
  Block test_block(10.0f, 10.0f, 20.0f, 20.0f, Draw::make_rgba(255, 0, 0, 255));

  /* Setup gameobject */
  Renderer::add_child_to_stage(&test_block);
  Scheduler::schedule(&test_block);

  while(true) {
    /* Clear screen */
    WPAD_ScanPads();

    Scheduler::execute();
    Renderer::render();

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
  }

  GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB
  return 0;
}
