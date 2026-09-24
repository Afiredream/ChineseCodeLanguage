
#include <cctype>
#include <unordered_map>

#include "词法分析.hpp"

static const std::unordered_map<std::string, 词元类型> 关键词语 = {
    {"如果", 词元类型::如果},
    {"或者", 词元类型::或者},
    {"函数", 词元类型::函数},
    {"返回", 词元类型::返回},
    {"常量", 词元类型::常量},
    {"变量", 词元类型::变量},
    {"容量", 词元类型::容量},
    {"类型", 词元类型::类型},
};

词法分析::词法分析(std::string 源码) : 源码_(std::move(源码)) {}

char 词法分析::当前字符() const {
    return 位置_ < 源码_.size() ? 源码_[位置_] : '\0';
}

char 词法分析::前进字符() {
    char c = 源码_[位置_++];
    if (c == '\n') { 行号_++; 列号_ = 1; }
    else           { 列号_++; }
    return c;
}

void 词法分析::跳过空白() {
    while (位置_ < 源码_.size() &&
           std::isspace((unsigned char)当前字符())) {
        前进字符();
    }
}

词元结构 词法分析::造词元(词元类型 类型, const std::string& 文本) {
    return 词元结构{类型, 文本, 行号_, 列号_};
}

std::vector<词元结构> 词法分析::分析() {
    std::vector<词元结构> 分析结果;

    while (位置_ < 源码_.size()) {
        跳过空白();
        if (位置_ >= 源码_.size()) break;



        char 字符单元 = 当前字符();
        int 行号 = 行号_, 列号 = 列号_;

        if (std::isdigit((unsigned char)字符单元)) {
            std::string 数字;
            while (std::isdigit((unsigned char)当前字符()))
                数字 += 前进字符();
            分析结果.push_back({词元类型::数字, 数字, 行号, 列号});
            continue;
        }

        if (字符单元 == '"') {
            前进字符();
            std::string 文本;
            while (当前字符() != '"')
                文本 += 前进字符();
            前进字符();
            分析结果.push_back({词元类型::文本, 文本, 行号, 列号});
            continue;
        }



        switch (字符单元) {
            case '+': 前进字符(); 分析结果.push_back({词元类型::加号, "+", 行号, 列号}); continue;
            case '-': 前进字符(); 分析结果.push_back({词元类型::减号, "-", 行号, 列号}); continue;
            case '*': 前进字符(); 分析结果.push_back({词元类型::星号, "*", 行号, 列号}); continue;
            case '/': 前进字符(); 分析结果.push_back({词元类型::斜杠, "/", 行号, 列号}); continue;
            case '=': 前进字符(); 分析结果.push_back({词元类型::等号, "=", 行号, 列号}); continue;
            case '&': 前进字符(); 分析结果.push_back({词元类型::和号, "&", 行号, 列号}); continue;
            case '|': 前进字符(); 分析结果.push_back({词元类型::竖线, "|", 行号, 列号}); continue;
            case ';': 前进字符(); 分析结果.push_back({词元类型::分号, ";", 行号, 列号}); continue;
            case ',': 前进字符(); 分析结果.push_back({词元类型::逗号, ",", 行号, 列号}); continue;
            case '.': 前进字符(); 分析结果.push_back({词元类型::点号, ".", 行号, 列号}); continue;
            case ':': 前进字符(); 分析结果.push_back({词元类型::冒号, ":", 行号, 列号}); continue;
            case '!': 前进字符(); 分析结果.push_back({词元类型::叹号, "!", 行号, 列号}); continue;
            case '?': 前进字符(); 分析结果.push_back({词元类型::问号, "?", 行号, 列号}); continue;
            case '#': 前进字符(); 分析结果.push_back({词元类型::井号, "#", 行号, 列号}); continue;
            case '$': 前进字符(); 分析结果.push_back({词元类型::美元符, "$", 行号, 列号}); continue;
            case '^': 前进字符(); 分析结果.push_back({词元类型::脱字符, "^", 行号, 列号}); continue;
            case '~': 前进字符(); 分析结果.push_back({词元类型::波浪号, "~", 行号, 列号}); continue;
            case '>': 前进字符(); 分析结果.push_back({词元类型::大于号, ">", 行号, 列号}); continue;
            case '<': 前进字符(); 分析结果.push_back({词元类型::小于号, "<", 行号, 列号}); continue;
            case '%': 前进字符(); 分析结果.push_back({词元类型::百分号, "%", 行号, 列号}); continue;
            case '(': 前进字符(); 分析结果.push_back({词元类型::左圆括号, "(", 行号, 列号}); continue;
            case ')': 前进字符(); 分析结果.push_back({词元类型::右圆括号, ")", 行号, 列号}); continue;
            case '{': 前进字符(); 分析结果.push_back({词元类型::左花括号, "{", 行号, 列号}); continue;
            case '}': 前进字符(); 分析结果.push_back({词元类型::右花括号, "}", 行号, 列号}); continue;
            case '[': 前进字符(); 分析结果.push_back({词元类型::左方括号, "[", 行号, 列号}); continue;
            case ']': 前进字符(); 分析结果.push_back({词元类型::右方括号, "]", 行号, 列号}); continue;
            default: break;
        }

        std::string 词语;
        while (位置_ < 源码_.size()) {
            unsigned char 字符 = (unsigned char)当前字符();
            if (std::isspace(字符)) break;
            if (字符=='('||字符==')'||字符=='{'||字符=='}'||字符=='['||字符==']'||
                字符=='+'||字符=='-'||字符=='*'||字符=='/'||
                字符==';'||字符=='='||字符=='"') break;
            词语 += 前进字符();
        }
        if (词语.empty()) { 前进字符(); continue; }

        auto it = 关键词语.find(词语);
        if (it != 关键词语.end()) {
            分析结果.push_back({it->second, 词语, 行号, 列号});
        } else {
            分析结果.push_back({词元类型::名称, 词语, 行号, 列号});
        }
    }
    
    return 分析结果;
}