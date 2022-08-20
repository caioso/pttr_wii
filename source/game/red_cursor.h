#pragma once

/* includes */
#include <array>

#include "base/basic_game_object.h"
#include "components/collider.h"
#include "game/commons/block.h"

namespace game {
  class RedCursor :
    public base::BasicGameObject {
  public:
    RedCursor(float x, float y);
    ~RedCursor() = default;

    void spawn_cursor(void);
    void render(float offset_x, float offset_y) override;
    void run(void) override;

  private:
    std::array<game::commons::Block, 4> cursor_tetraminoes;
    bool detect_collision(void);
  };
}