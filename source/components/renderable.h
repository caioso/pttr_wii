#pragma once

/* includes */
#include <algorithm>
#include <vector>

namespace base::graphics {
  class Renderer;
}

namespace components {
  class Renderable {
  friend base::graphics::Renderer;
  public:
    /* public methods */
    virtual ~Renderable(void) = default;

    /* abstract methods */
    virtual void render(float offset_x, float offset_y) = 0;
  };
}