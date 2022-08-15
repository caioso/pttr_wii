#pragma once

namespace interfaces {
  class Runnable {
  public:
    /* public methods */
    Runnable() = default;
    virtual ~Runnable() = default;

    virtual void run(void) = 0;
  };
}