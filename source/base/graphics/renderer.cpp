/* includes */
#include "renderer.h"
#include "utils/draw.h"

using namespace base;
using namespace components;
using namespace utils;

namespace base::graphics {
  void Renderer::initialize(void) {}

  void Renderer::add_child_to_stage(GameObject * child) {
    if (child != nullptr) {
      Renderer::main_stage.add_child(child);
    }
  }

  void Renderer::render(void) {
    /* clear screen */
    Draw::clear_screen();

    /* render stage elements */
    /* @TODO: Detect loops in the children lists */
    Renderer::render_parent_and_children(&Renderer::main_stage, 0.0f, 0.0f);

    /* renderer call */
    GRRLIB_Render();
  }

  void Renderer::render_parent_and_children(
    GameObject * parent, float offset_x, float offset_y) {

    auto renderable_parent = dynamic_cast<Renderable*>(parent);
    renderable_parent->render(offset_x, offset_y);

    for (auto child : parent->children) {
      if (child != nullptr) {
        Renderer::render_parent_and_children(
          child, parent->pos.x, parent->pos.y);
      }
    }
  }
}