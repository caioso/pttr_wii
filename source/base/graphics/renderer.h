#pragma once

/* includes */
#include <cstddef>
#include <vector>
#include <tuple>
#include "components/collider.h"
#include "components/renderable.h"
#include "stage.h"

namespace base::graphics {
  class Renderer {
  public:
    /* public methods */
    static void initialize(void);
    static void add_child_to_stage(components::Renderable * child);
    static void render(void);
    static void render_bounding_boxes(components::Collider * collider);

  private:
    /* private methods */
    static std::tuple<float, float> calculate_position_offset(
      components::Renderable * renderable);
    static void render_parent_and_children(
      components::Renderable * parent, float offset_x, float offset_y);

    /* private attributes */
    inline static Stage main_stage;
  };
}