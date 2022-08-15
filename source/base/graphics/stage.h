#pragma once

/* includes */
#include "basic_game_object.h"

namespace base::graphics {
  class Stage : public BasicGameObject {
  public:
    Stage(void);
    ~Stage(void) = default;
  };
}