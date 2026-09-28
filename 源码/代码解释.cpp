#include "代码解释.hpp"

#include <string>
#include <vector>

#include "内置函数.hpp"
#include "语法分析.hpp"

代码解释::代码解释(std::vector<语句>&& 语句列表) {
  for (const 语句& 语句单元 : 语句列表) {
    std::visit(
        [](const auto& 节点) {
          using T = std::decay_t<decltype(节点)>;
          if constexpr (std::is_same_v<T, 结构调用>) {
            if (节点.语句 == 语句类型::结构调用) {
              std::string 结构名称 = 节点.名称;

              auto it = 内置函数表().find(结构名称);
              if (it != 内置函数表().end()) {
                std::string 结果 = it->second(节点.参数);
              } else {
              }
            }
          }
        },
        语句单元);
  }
}
