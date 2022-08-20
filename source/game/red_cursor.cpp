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
using namespace game::commons;
using namespace utils;

namespace game {
  RedCursor::RedCursor(float x, float y)
    : BasicGameObject(x, y) {
  }

  void RedCursor::spawn_cursor(void) {
    Renderer::add_child_to_stage(this);
    Scheduler::schedule(this);

    /* Test only */
    this->cursor_tetraminoes[0] = Block(
      0, 0.0f, 0.0f, 20.0f, 20.0f, 20.0f, 20.0f, BlockColor::red);
    this->cursor_tetraminoes[1] = Block(
      1, 20.0f, 0.0f, 20.0f, 20.0f, 20.0f, 20.0f, BlockColor::red);
    this->cursor_tetraminoes[2] = Block(
      2, 40.0f, 0.0f, 20.0f, 20.0f, 20.0f, 20.0f, BlockColor::red);
    this->cursor_tetraminoes[3] = Block(
      3, 40.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, BlockColor::red);
    this->add_child(&this->cursor_tetraminoes[0]);
    this->add_child(&this->cursor_tetraminoes[1]);
    this->add_child(&this->cursor_tetraminoes[2]);
    this->add_child(&this->cursor_tetraminoes[3]);
  }

  void RedCursor::render(float offset_x, float offset_y) {
    /* do nothing (for now) */
  }

  void RedCursor::run(void) {
     if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_UP) {
      this->pos.y--;
      if(this->detect_collision() == true) {
        this->pos.y++;
      }
     } else if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_DOWN) {
      this->pos.y++;
      if(this->detect_collision()) {
        this->pos.y--;
      }
     }

     if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_LEFT) {
      this->pos.x--;
      if(this->detect_collision()) {
        this->pos.x++;
      }
     } else if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_RIGHT) {
      this->pos.x++;
      if(this->detect_collision()) {
        this->pos.x--;
      }
     }
  }

  bool RedCursor::detect_collision(void) {
    bool collided = false;
    if(CollisionDetector::detect_collision(
        &this->cursor_tetraminoes[0]) == true ||
       CollisionDetector::detect_collision(
        &this->cursor_tetraminoes[1]) == true ||
       CollisionDetector::detect_collision(
        &this->cursor_tetraminoes[2]) == true ||
       CollisionDetector::detect_collision(
        &this->cursor_tetraminoes[3]) == true) {
      collided = true;
    }
    return collided;
  }
}