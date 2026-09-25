
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "词法分析.hpp"
#include "语法分析.hpp"
#include "语义分析.hpp"

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


    语法分析 解析器(std::move(词元流));
    程序 ast = 解析器.解析();

    return 0;
}