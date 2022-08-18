#pragma once

/* includes */
#include "base/basic_game_object.h"
#include "components/collider.h"

namespace game {
  class RedCursor :
    public base::BasicGameObject,
    public components::Collider {
  public:
    RedCursor(float x, float y);
    ~RedCursor() = default;

    void spawn_cursor(void);
    void render(float offset_x, float offset_y) override;
    void run(void) override;
  };
}