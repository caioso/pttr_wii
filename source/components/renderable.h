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
    void add_child(Renderable * child);
    void remove_child(Renderable * child);

    /* abstract methods */
    virtual void render(float offset_x, float offset_y) = 0;
    /* Public attributes */
    float x;
    float y;

  private:
    std::vector<Renderable *> children;
  };
}