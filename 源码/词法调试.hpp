#pragma once

#include <ostream>

#include "词法分析.hpp"

inline std::ostream& operator<<(std::ostream& 输出, 词元类型 类型) {
  输出 << 类型文本.find(类型)->second;
  return 输出;
}

inline std::ostream& operator<<(std::ostream& 输出, const 词元结构& 词元) {
  输出 << "( 行:" << 词元.行号 << " 列:" << 词元.列号 << " ) " << 词元.类型 << " " << 词元.文本;
  return 输出;
}