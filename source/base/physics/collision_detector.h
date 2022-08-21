#pragma once

/* includes */
#include <algorithm>
#include <optional>
#include <vector>

#include "base/game_object.h"
#include "components/collider.h"
#include "utils/point2d.h"

namespace base::physics {
  class CollisionDetector {
  public:
    static void register_collider(base::GameObject * collider);
    static std::optional<utils::Point2D> detect_collision(
      base::GameObject * target_collider);

  private:
    static utils::Point2D local_to_world_position(
      base::GameObject * game_object);
    inline static std::vector<base::GameObject *> colliders;
  };
}