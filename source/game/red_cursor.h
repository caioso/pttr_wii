#pragma once

/* includes */
#include <array>
#include <optional>

#include "base/basic_game_object.h"
#include "components/collider.h"
#include "game/commons/block.h"
#include "utils/point2d.h"

namespace game {
  enum class CursorMovementDirection {
    up = 0,
    down = 1,
    left = 2,
    right = 3
  };

  class RedCursor :
    public base::BasicGameObject {
  public:
    RedCursor(float x, float y);
    ~RedCursor() = default;

    void spawn_cursor(void);
    void render(float offset_x, float offset_y) override;
    void run(void) override;

  private:
    float cursor_speed;
    std::array<game::commons::Block, 4> cursor_tetraminoes;
    void move_cursor_with_collisions(
      CursorMovementDirection direction, float amount);
    void move_cursor_horizontally(float amount);
    void move_cursor_vertically(float amount);
    void perform_pre_movement(CursorMovementDirection direction, float amount);
    std::optional<utils::Point2D> detect_potential_collisions(void);
    void perform_post_movement(
      CursorMovementDirection direction,
      std::optional<utils::Point2D> correction_offset);
  };
}