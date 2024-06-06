#pragma once

#include <stdint.h>

struct record_s {
  char name[80];
  char address[80];
  uint8_t semester;
};