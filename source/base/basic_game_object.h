#pragma once

/* includes */
#include "../interfaces/renderable.h"
#include "../interfaces/runnable.h"

namespace base {
  class BasicGameObject :
    public interfaces::Renderable,
    public interfaces::Runnable {
  public:
    /* public methods */
    BasicGameObject(float x, float y);
    ~BasicGameObject(void) = default;

    virtual void render(float offset_x, float offset_y) override;
    virtual void run(void) override;
  };
}