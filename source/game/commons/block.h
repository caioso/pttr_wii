#pragma once

/* includes */
#include <cstdint>
#include "base/basic_game_object.h"

namespace game::commons {
  class Block : public base::BasicGameObject {
  public:
    /* public methodss */
    Block(float x, float y, float width, float height, uint32_t color);
    ~Block() = default;

    void render(float offset_x, float offset_y) override;
    void run(void) override;

  private:
    /* private attributes */
    float width;
    float height;
    uint32_t color;
  };
}