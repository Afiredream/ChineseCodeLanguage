#include <iostream>
#include "词法分析.hpp"

int main() {
    词法分析 lex("变量 年龄 = 18; 如果 年龄 > 10 函数");
    for (const auto& t : lex.分析()) {
        std::cout << t << "\n";
    }
    return 0;
}