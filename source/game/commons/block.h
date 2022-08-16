#pragma once

/* includes */
#include <cstdint>
#include <cstddef>
#include <limits>
#include "base/basic_game_object.h"

namespace game::commons {
  class Block : public base::BasicGameObject {
  public:
    /* public methodss */
    Block(void);
    Block(
      size_t id, float x, float y, float width, float height, uint32_t color);
    ~Block() = default;

    void render(float offset_x, float offset_y) override;
    void run(void) override;
    size_t get_id(void);

    /* helpers */
    static Block make_empty_block(void);

  private:
    /* private attributes */
    size_t id;
    float width;
    float height;
    uint32_t color;
  };
}