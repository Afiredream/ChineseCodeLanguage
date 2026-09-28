
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "代码解释.hpp"
#include "内置函数.hpp"
#include "词法分析.hpp"
#include "词法调试.hpp"
#include "语义分析.hpp"
#include "语法分析.hpp"
#include "语法调试.hpp"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "用法: " << argv[0] << " <源文件路径>\n";
    return 1;
  }

  std::string 文件路径 = argv[1];
  std::ifstream 输入文件(文件路径);
  if (!输入文件.is_open()) {
    std::cerr << "无法打开文件: " << 文件路径 << "\n";
    return 1;
  }

  std::ostringstream 缓冲;
  缓冲 << 输入文件.rdbuf();
  std::string 源码 = 缓冲.str();
  输入文件.close();

  词法分析 lex(源码);
  auto 词元流 = lex.代码分析();

  for (const auto& 词元 : 词元流) {
    std::cout << 词元 << "\n";
  }

  auto 语句流 = 语法分析{}.代码分析(std::move(词元流));
  for (const auto& 节点 : 语句流) {
    std::visit([](const auto& 实际语句) { std::cout << 实际语句.语句 << "\n"; }, 节点);
  };

  std::cout << "========输出内容=========" << std::endl;
  代码解释 运行流(std::move(语句流));
  std::cout << "========输出内容=========" << std::endl;

  return 0;
}