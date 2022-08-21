/* includes */
#include <math.h>
#include <optional>
#include <wiiuse/wpad.h>

#include "base/physics/collision_detector.h"
#include "control/scheduler.h"
#include "graphics/renderer.h"
#include "game/red_cursor.h"
#include "game/constants.h"
#include "utils/draw.h"

using namespace base::control;
using namespace base::physics;
using namespace base::graphics;
using namespace game::commons;
using namespace utils;
using namespace std;

namespace game {
  RedCursor::RedCursor(float x, float y) :
    BasicGameObject(x, y),
    cursor_speed(1.0f) {
  }

  void RedCursor::spawn_cursor(void) {
    Renderer::add_child_to_stage(this);
    Scheduler::schedule(this);

    /* Test only */
    this->cursor_tetraminoes[0] = Block(
      0, 0.0f, 0.0f, Constants::block_width, Constants::block_height,
      Constants::block_width, Constants::block_height, BlockColor::red);
    this->cursor_tetraminoes[1] = Block(
      1, Constants::block_width, 0.0f,  Constants::block_width,
      Constants::block_height, Constants::block_width,
      Constants::block_height, BlockColor::red);
    this->cursor_tetraminoes[2] = Block(
      2, 2 * Constants::block_width, 0.0f, Constants::block_width,
      Constants::block_height, Constants::block_width,
      Constants::block_height, BlockColor::red);
    this->cursor_tetraminoes[3] = Block(
      3, 2 * Constants::block_width, Constants::block_height,
      Constants::block_width, Constants::block_height,
      Constants::block_width, Constants::block_height,
      BlockColor::red);
    this->add_child(&this->cursor_tetraminoes[0]);
    this->add_child(&this->cursor_tetraminoes[1]);
    this->add_child(&this->cursor_tetraminoes[2]);
    this->add_child(&this->cursor_tetraminoes[3]);
  }

  void RedCursor::render(float offset_x, float offset_y) {
    /* do nothing (for now) */
  }

  void RedCursor::run(void) {
    if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_A) {
      if (this->cursor_speed <= 10.0f) {
        this->cursor_speed++;
      }
    }

    if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_B) {
      if (this->cursor_speed > 1.0f) {
        this->cursor_speed--;
      }
    }

    if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_UP) {
      this->move_cursor_with_collisions(
        CursorMovementDirection::up, -this->cursor_speed);
    } else if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_DOWN) {
      this->move_cursor_with_collisions(
        CursorMovementDirection::down, this->cursor_speed);
    }

    if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_LEFT) {
      this->move_cursor_with_collisions(
        CursorMovementDirection::left, -this->cursor_speed);
    } else if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_RIGHT) {
      this->move_cursor_with_collisions(
        CursorMovementDirection::right, this->cursor_speed);
    }
  }

  void RedCursor::move_cursor_with_collisions(
      CursorMovementDirection direction, float amount) {
    optional<Point2D> correction_offset = nullopt;
    this->perform_pre_movement(direction, amount);
    correction_offset = this->detect_potential_collisions();
    this->perform_post_movement(direction, correction_offset);
  }

  void RedCursor::perform_pre_movement(
    CursorMovementDirection direction, float amount) {
    if ((direction == CursorMovementDirection::up) ||
      (direction == CursorMovementDirection::down)) {
      move_cursor_vertically(amount);
    } else if ((direction == CursorMovementDirection::left) ||
      (direction == CursorMovementDirection::right)) {
      move_cursor_horizontally(amount);
    }
  }

  optional<Point2D> RedCursor::detect_potential_collisions(void) {
    optional<Point2D> correction_offset = nullopt;
    auto collision_offset_0 = CollisionDetector::detect_collision(
        &this->cursor_tetraminoes[0]);
    auto collision_offset_1 = CollisionDetector::detect_collision(
        &this->cursor_tetraminoes[1]);
    auto collision_offset_2 = CollisionDetector::detect_collision(
        &this->cursor_tetraminoes[2]);
    auto collision_offset_3 = CollisionDetector::detect_collision(
        &this->cursor_tetraminoes[3]);

    /* Simplistic approach: return the first collision detected (out of 4) */
    if(collision_offset_0 != nullopt) {
      correction_offset = collision_offset_0;
    } else if(collision_offset_1 != nullopt) {
      correction_offset = collision_offset_1;
    } else if(collision_offset_2 != nullopt) {
      correction_offset = collision_offset_2;
    } else if (collision_offset_3 != nullopt) {
      correction_offset = collision_offset_3;
    }

    return correction_offset;
  }

  void RedCursor::perform_post_movement(
    CursorMovementDirection direction, optional<Point2D> correction_offset) {
    if (correction_offset != nullopt) {
      if (direction == CursorMovementDirection::up) {
        move_cursor_vertically(
          -((*correction_offset).y - Constants::block_height));
      } else if (direction == CursorMovementDirection::down) {
        move_cursor_vertically(
          ((*correction_offset).y - Constants::block_height));
      } else if (direction == CursorMovementDirection::left) {
        move_cursor_horizontally(
          -((*correction_offset).x - Constants::block_width));
      } else if (direction == CursorMovementDirection::right) {
        move_cursor_horizontally(
          ((*correction_offset).x - Constants::block_width));
      }
    }
  }

  void RedCursor::move_cursor_horizontally(float amount) {
    this->pos.x += amount;
  }

  void RedCursor::move_cursor_vertically(float amount) {
    this->pos.y += amount;
  }
}