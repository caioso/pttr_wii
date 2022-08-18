#pragma once

/* includes */
#include <stddef.h>

namespace components {
  class Collider {
  public:
    Collider() = default;
    Collider(float bounding_box_width, float bounding_box_height);
    virtual ~Collider() = default;

    float bounding_box_width;
    float bounding_box_height;
  };
}