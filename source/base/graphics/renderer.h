#pragma once

/* includes */
#include <cstddef>
#include <vector>
#include "interfaces/renderable.h"
#include "stage.h"

namespace base::graphics {
  class Renderer {
  public:
    /* public methods */
    static void initialize(void);
    static void add_child_to_stage(interfaces::Renderable * child);
    static void render(void);

  private:
    /* private methods */
    static void render_parent_and_children(
      interfaces::Renderable * parent, float offset_x, float offset_y);

    /* private attributes */
    inline static Stage main_stage;
  };
}