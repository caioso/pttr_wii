#pragma once

#include <cstdint>

class Utils {
public:
  /* constexpr are implicitly inlined, that's why it is defined in header */
  static constexpr uint32_t make_rgba(
    uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
      return (r << 24) | (g << 16) | (b << 8) | a;
    }
};