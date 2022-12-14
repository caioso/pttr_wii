/* includes */
#include <math.h>
#include "collision_detector.h"
#include "base/basic_game_object.h"
#include "game/constants.h"

using namespace base;
using namespace components;
using namespace game;
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

  optional<Point2D> CollisionDetector::detect_collision(GameObject * target) {
    optional<Point2D> collision_information = nullopt;
    auto target_position = CollisionDetector::local_to_world_position(target);

    for (auto candidate : CollisionDetector::colliders) {
      if (target != candidate) {
        auto candidate_position =
          CollisionDetector::local_to_world_position(candidate);
        if ((target_position.x < candidate_position.x + Constants::block_width) &&
            (target_position.x + Constants::block_width > candidate_position.x) &&
            (target_position.y < candidate_position.y + Constants::block_height) &&
            (target_position.y + Constants::block_height > candidate_position.y)){
          collision_information.emplace(
            abs(target_position.x - candidate_position.x),
            abs(target_position.y - candidate_position.y));
          break;
        }
      }
    }

    return collision_information;
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