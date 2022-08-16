/* includes */
#include "renderable.h"

using namespace std;

namespace interfaces {
  void Renderable::add_child(Renderable * child) {
    auto target = std::find_if(
      begin(this->children), end(this->children),
      [child](Renderable * r) -> bool { return child == r; });

    if (target == end(this->children)) {
      this->children.push_back(child);
    }
  }

  void Renderable::remove_child(Renderable * child) {
    auto target = std::find_if(
      begin(this->children), end(this->children),
      [child](Renderable * r) -> bool { return child == r; });

    if (target != end(this->children)) {
      this->children.erase(target);
    }
  }
}