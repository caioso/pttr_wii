#pragma once

/* includes */
#include <stddef.h>
#include "utils/point2d.h"

namespace components {
  class Collider {
  public:
    Collider() = default;
    Collider(
      float bounding_box_width, float bounding_box_height,
      utils::Point2D * reference_position);
    virtual ~Collider() = default;

    float bounding_box_width;
    float bounding_box_height;

  private:
    utils::Point2D * ref_pos;
  };
}