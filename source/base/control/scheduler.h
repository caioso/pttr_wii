#pragma once

/* includes */
#include <vector>
#include "interfaces/runnable.h"

namespace base::control {
  class Scheduler {
  public:
    static void initialize(void);
    static void schedule(interfaces::Runnable * runnable);
    static void execute(void);

  private:
    inline static std::vector<interfaces::Runnable *> tasks;
  };

}