/* includes */
#include "renderer.h"
#include "utils/draw.h"

using namespace utils;

namespace base::graphics {
  void Renderer::initialize(void) {}

  void Renderer::add_child_to_stage(interfaces::Renderable * child) {
    Renderer::main_stage.add_child(child);
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
    interfaces::Renderable * parent, float offset_x, float offset_y) {
    parent->render(offset_x, offset_y);

    for (auto child : parent->children) {
      Renderer::render_parent_and_children(
        child, parent->x, parent->y);
    }
  }
}