#pragma once

/* includes */
#include <vector>
#include "components/runnable.h"

namespace base::control {
  class Scheduler {
  public:
    static void initialize(void);
    static void schedule(components::Runnable * runnable);
    static void execute(void);

  private:
    inline static std::vector<components::Runnable *> tasks;
  };

}