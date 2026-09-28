#pragma once

#include <ostream>

#include "语法类型.hpp"

inline std::ostream& operator<<(std::ostream& 输出, 语句类型 语句) {
  输出 << 语句文本.find(语句)->second;
  return 输出;
}