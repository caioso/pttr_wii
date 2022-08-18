#include <grrlib.h>
#include <wiiuse/wpad.h>

/* Engine Includes */
#include "base/basic_game_object.h"
#include "base/control/scheduler.h"
#include "base/graphics/renderer.h"
#include "game/commons/block.h"
#include "game/commons/matrix.h"
#include "game/red_cursor.h"
#include "utils/draw.h"

using namespace base::control;
using namespace base::graphics;
using namespace game::commons;
using game::RedCursor;
using namespace utils;

int main() {

  GRRLIB_Init();
  WPAD_Init();

  Renderer::initialize();
  Scheduler::initialize();

  /* test only */
  Matrix p1_matrix(30, 30);
  p1_matrix.create_block(0.0f, 0.0f, BlockColor::red);
  p1_matrix.create_block(20.0f, 20.0f, BlockColor::yellow);
  p1_matrix.create_block(100.0f, 100.0f, BlockColor::green);
  p1_matrix.create_block(40.0f, 100.0f, BlockColor::light_blue);
  p1_matrix.create_block(140.0f, 100.0f, BlockColor::dark_blue);
  p1_matrix.create_block(240.0f, 100.0f, BlockColor::orange);
  p1_matrix.create_block(240.0f, 100.0f, BlockColor::purple);

  RedCursor cursor(0, 0);

  /* Setup game object */
  Renderer::add_child_to_stage(&p1_matrix);
  cursor.spawn_cursor();

  while(true) {
    /* Clear screen */
    WPAD_ScanPads();

    Scheduler::execute();
    Renderer::render();
  }

  GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB
  return 0;
}
