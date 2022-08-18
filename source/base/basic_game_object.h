#pragma once

/* includes */
#include "components/renderable.h"
#include "components/runnable.h"

namespace base {
  class BasicGameObject :
    public components::Renderable,
    public components::Runnable {
  public:
    /* public methods */
    BasicGameObject(float x, float y);
    ~BasicGameObject(void) = default;

    virtual void render(float offset_x, float offset_y) override;
    virtual void run(void) override;
  };
}