#include <functional>
#include <iostream>
#include <string>

inline void 输出(const std::string& 文本) { std::cout << 文本 << std::endl; }

inline std::string 输入() {
  std::string 文本;
  std::getline(std::cin, 文本);
  return 文本;
}

// 函数表
using 内置函数类型 = std::function<std::string(const std::vector<std::string>&)>;

inline const std::unordered_map<std::string, 内置函数类型>& 内置函数表() {
  static const std::unordered_map<std::string, 内置函数类型> 表 = {
      {"输出",
       [](const std::vector<std::string>& 参数) {
         输出(参数.empty() ? "" : 参数[0]);
         return std::string{};
       }},
      {"输入", [](const std::vector<std::string>&) { return 输入(); }},
  };
  return 表;
}