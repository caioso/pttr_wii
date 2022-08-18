#pragma once

/* includes */
#include <cstdint>
#include <cstddef>
#include <limits>
#include "base/basic_game_object.h"
#include "components/collider.h"


namespace game::commons {
  enum class BlockColor : uint8_t {
    yellow = 0x01,
    light_blue = 0x02,
    purple = 0x03,
    orange = 0x04,
    dark_blue = 0x05,
    green = 0x06,
    red = 0x07,
    no_color = 0x00
  };

  class Block :
    public base::BasicGameObject,
    public components::Collider {
  public:
    /* public methodss */
    Block(void);
    Block(size_t id, float x, float y, float width, float height,
    float collider_width, float collider_height, BlockColor color);
    ~Block() = default;

    void render(float offset_x, float offset_y) override;
    void run(void) override;
    size_t get_id(void);

    /* helpers */
    static Block make_empty_block(void);

  private:
    /* private methods */
    uint32_t block_color_to_rgba(void);

    /* private attributes */
    size_t id;
    float render_width;
    float render_height;
    BlockColor color;
  };
}