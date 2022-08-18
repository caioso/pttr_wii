/* includes */
#include <wiiuse/wpad.h>

#include "graphics/renderer.h"
#include "control/scheduler.h"
#include "game/red_cursor.h"
#include "utils/draw.h"

using namespace base::control;
using namespace base::graphics;
using namespace utils;

namespace game {
  RedCursor::RedCursor(float x, float y)
    : BasicGameObject(x, y)
    , Collider(100, 100) {
  }

  void RedCursor::spawn_cursor(void) {
    Renderer::add_child_to_stage(this);
    Scheduler::schedule(this);
  }

  void RedCursor::render(float offset_x, float offset_y) {
    Draw::draw_filled_rectangle(this->x + offset_x, this->y + offset_y,
    100, 100, Draw::make_rgba(255, 0, 0, 255));
  }

  void RedCursor::run(void) {
     if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_UP) {
      this->y--;
     } else if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_DOWN) {
      this->y++;
     }

     if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_LEFT) {
      this->x--;
     } else if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_RIGHT) {
      this->x++;
     }
  }
}