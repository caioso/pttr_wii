/* includes */
#include "scheduler.h"

namespace base::control {
  void Scheduler::initialize(void) { }

  void Scheduler::schedule(components::Runnable * runnable) {
    Scheduler::tasks.push_back(runnable);
  }

  void Scheduler::execute(void) {
    for (auto runnable : Scheduler::tasks) {
      runnable->run();
    }
  }
}