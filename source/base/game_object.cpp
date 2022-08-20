/* includes */
#include "game_object.h"

using namespace std;

namespace base {
 void GameObject::add_child(GameObject * child) {
    auto target = std::find_if(
      begin(this->children), end(this->children),
      [child](GameObject * r) -> bool { return child == r; });

    if (target == end(this->children)) {
      this->children.push_back(child);
      child->parent = this;
    }
  }

  void GameObject::remove_child(GameObject * child) {
    auto target = std::find_if(
      begin(this->children), end(this->children),
      [child](GameObject * r) -> bool { return child == r; });

    if (target != end(this->children)) {
      this->children.erase(target);
      (*target)->parent = nullptr;
    }
  }
}

