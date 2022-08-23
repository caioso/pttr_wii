#include <grrlib.h>
#include <array>
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
using game::Constants;
using namespace utils;

int main() {

  GRRLIB_Init();
  WPAD_Init();

  Renderer::initialize();
  Scheduler::initialize();

  /* test only */
  std::array<
      std::array<BlockColor, Constants::matrix_height>,
        Constants::matrix_width> matrix_template = {};

  for (size_t i = 0; i < Constants::matrix_height; i++) {
    for (size_t j = 0; j < Constants::matrix_width; j++) {
      matrix_template[i][j] = BlockColor::no_color;
    }
  }

  matrix_template[0][0] = BlockColor::red;
  matrix_template[0][9] = BlockColor::yellow;
  matrix_template[19][0] = BlockColor::green;
  matrix_template[19][9] = BlockColor::light_blue;

  Matrix p1_matrix(30, 30);
  p1_matrix.initialize_matrix(matrix_template);

  RedCursor cursor(200, 60);

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
