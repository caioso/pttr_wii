#include "renderable.h"

namespace interfaces {
  void Renderable::add_child(Renderable * child) {
    this->children.push_back(child);
  }
}