#pragma once

/* includes */
#include <cstddef>
#include <vector>
#include <tuple>
#include "base/game_object.h"
#include "components/collider.h"
#include "components/renderable.h"
#include "stage.h"

namespace base::graphics {
  class Renderer {
  public:
    /* public methods */
    static void initialize(void);
    static void add_child_to_stage(base::GameObject * child);
    static void render(void);

  private:
    /* private methods */
    static std::tuple<float, float> calculate_position_offset(
      components::Renderable * renderable);
    static void render_parent_and_children(
      base::GameObject * parent, float offset_x, float offset_y);

    /* private attributes */
    inline static Stage main_stage;
  };
}