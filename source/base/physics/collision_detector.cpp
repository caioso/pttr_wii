/* includes */
#include "collision_detector.h"
#include "base/basic_game_object.h"

using namespace base;
using namespace components;
using namespace utils;
using namespace std;

namespace base::physics {
  void CollisionDetector::register_collider(GameObject * collider) {
    if (auto collider_component = dynamic_cast<Collider*>(collider);
        collider_component != nullptr) {
      auto target = std::find_if(
        begin(CollisionDetector::colliders), end(CollisionDetector::colliders),
        [collider](GameObject * r) -> bool { return collider == r; });

      if (target == end(CollisionDetector::colliders)) {
        CollisionDetector::colliders.push_back(collider);
      }
    }
  }

  bool CollisionDetector::detect_collision(GameObject * target) {
    auto collided = false;

    if (auto target_collider = dynamic_cast<Collider*>(target);
        target_collider != nullptr) {
      auto target_position = CollisionDetector::local_to_world_position(target);

      for (auto candidate : CollisionDetector::colliders) {
        if (target != candidate) {
          auto candidate_collider = dynamic_cast<Collider*>(candidate);
          auto candidate_position =
            CollisionDetector::local_to_world_position(candidate);

          if ((target_position.x <
              candidate_position.x + candidate_collider->bounding_box_width) &&
              (target_position.x + target_collider->bounding_box_width >
              candidate_position.x) &&
              (target_position.y <
              candidate_position.y + candidate_collider->bounding_box_height) &&
              (target_position.y + target_collider->bounding_box_height >
               candidate_position.y)) {
            collided = true;
            break;
          }
        }
      }
    }

    return collided;
  }

  Point2D CollisionDetector::local_to_world_position(GameObject * game_object) {
      if (game_object == nullptr) {
        return Point2D::make_point2d(0.0f, 0.0f);
      } else {
        return Point2D::make_point2d(game_object->pos.x, game_object->pos.y) +
          local_to_world_position(game_object->parent);
      }
  }
}