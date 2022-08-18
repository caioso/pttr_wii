/* includes */
#include "collider.h"

namespace components {
  Collider::Collider(float bounding_box_width, float bounding_box_height) :
    bounding_box_width(bounding_box_width),
    bounding_box_height(bounding_box_height) {
  }
}