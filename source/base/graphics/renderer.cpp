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
    Renderer::main_stage.render(0.0f, 0.0f);

    for (auto child : Renderer::main_stage.children) {
      child->render(0.0f, 0.0f);
    }

    /* renderer call */
    GRRLIB_Render();
  }
}