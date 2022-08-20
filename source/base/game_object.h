#pragma once

/* includes */
#include <algorithm>
#include <vector>
#include "utils/point2d.h"

namespace base {
  namespace graphics {
    class Renderer;
  }

  namespace physics {
    class CollisionDetector;
  }
}

namespace base {
  struct GameObject {
    friend base::graphics::Renderer;
    friend base::physics::CollisionDetector;
    GameObject() = default;
    virtual ~GameObject() = default;
    void add_child(GameObject * child);
    void remove_child(GameObject * child);

    utils::Point2D pos;

  private:
    std::vector<GameObject *> children;
    GameObject * parent;
  };
}