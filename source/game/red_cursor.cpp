/* includes */
#include <wiiuse/wpad.h>

#include "base/physics/collision_detector.h"
#include "control/scheduler.h"
#include "graphics/renderer.h"
#include "game/red_cursor.h"
#include "utils/draw.h"

using namespace base::control;
using namespace base::physics;
using namespace base::graphics;
using namespace utils;

namespace game {
  RedCursor::RedCursor(float x, float y)
    : BasicGameObject(x, y)
    , Collider(20.0f, 20.0f, &this->pos) {
  }

  void RedCursor::spawn_cursor(void) {
    Renderer::add_child_to_stage(this);
    Scheduler::schedule(this);
  }

  void RedCursor::render(float offset_x, float offset_y) {
    Draw::draw_filled_rectangle(this->pos.x + offset_x, this->pos.y + offset_y,
    20.0f, 20.0f, Draw::make_rgba(255, 255, 255, 127));
  }

  void RedCursor::run(void) {
     if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_UP) {
      this->pos.y--;
      if(CollisionDetector::detect_collision(this) == true) {
        this->pos.y++;
      }
     } else if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_DOWN) {
      this->pos.y++;
      if(CollisionDetector::detect_collision(this) == true) {
        this->pos.y--;
      }
     }

     if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_LEFT) {
      this->pos.x--;
      if(CollisionDetector::detect_collision(this) == true) {
        this->pos.x++;
      }
     } else if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_RIGHT) {
      this->pos.x++;
      if(CollisionDetector::detect_collision(this) == true) {
        this->pos.x--;
      }
     }
  }
}