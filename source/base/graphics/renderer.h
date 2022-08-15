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
    /* private members */
    inline static Stage main_stage;
  };
}