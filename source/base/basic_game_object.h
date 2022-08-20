#pragma once

/* includes */
#include "game_object.h"
#include "components/renderable.h"
#include "components/runnable.h"
#include "utils/point2d.h"

namespace base {
  class BasicGameObject :
    public GameObject,
    public components::Renderable,
    public components::Runnable {
  public:
    /* public methods */
    BasicGameObject(float x, float y);
    BasicGameObject(utils::Point2D position);
    ~BasicGameObject(void) = default;

    virtual void render(float offset_x, float offset_y) override;
    virtual void run(void) override;
  };
}