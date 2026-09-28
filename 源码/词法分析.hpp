#pragma once

#include <string>
#include <vector>

#include "词法类型.hpp"

struct 词元结构 {
  词元类型 类型;
  std::string 文本;
  int 行号 = 0;
  int 列号 = 0;
};

class 词法分析 {
 public:
  explicit 词法分析(std::string 源码);
  std::vector<词元结构> 代码分析();

 private:
  std::string 源码_;
  size_t 位置_ = 0;
  int 行号_ = 1;
  int 列号_ = 1;
  std::string 当前字符() const;
  std::string 前进字符();
  void 跳过空白();
  词元结构 构造词元(词元类型 类型, const std::string& 文本);
};

inline size_t 索引字符长度(unsigned char 首位字节) {
  if ((首位字节 & 0x80) == 0x00) return 1;
  if ((首位字节 & 0xE0) == 0xC0) return 2;
  if ((首位字节 & 0xF0) == 0xE0) return 3;
  if ((首位字节 & 0xF8) == 0xF0) return 4;
  return 0;
}