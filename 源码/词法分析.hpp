#pragma once
#include <string>
#include <vector>
#include <ostream>

enum class 词元类型 {
    如果, 或者, 函数, 返回,
    常量, 变量, 容量, 类型,
    数字, 文本, 名称,
    加号, 减号, 星号, 斜杠, 百分号,
    等号, 大于号, 小于号,
    和号, 竖线, 脱字符, 波浪号,
    分号, 逗号, 点号, 冒号,
    左圆括号, 右圆括号,
    左花括号, 右花括号,
    左方括号, 右方括号,
    叹号, 问号, 井号, 美元符, 下划线
};

inline std::string 类型文本(词元类型 类型) {
    switch (类型) {
        case 词元类型::如果: return "如果";
        case 词元类型::或者: return "或者";
        case 词元类型::函数: return "函数";
        case 词元类型::返回: return "返回";
        case 词元类型::常量: return "常量";
        case 词元类型::变量: return "变量";
        case 词元类型::容量: return "容量";
        case 词元类型::类型: return "类型";
        case 词元类型::数字: return "数字";
        case 词元类型::文本: return "文本";
        case 词元类型::名称: return "名称";
        case 词元类型::加号: return "加号";
        case 词元类型::减号: return "减号";
        case 词元类型::星号: return "星号";
        case 词元类型::斜杠: return "斜杠";
        case 词元类型::和号: return "和号";
        case 词元类型::竖线: return "竖线";
        case 词元类型::等号: return "等号";
        case 词元类型::分号: return "分号";
        case 词元类型::逗号: return "逗号";
        case 词元类型::点号: return "点号";
        case 词元类型::冒号: return "冒号";
        case 词元类型::叹号: return "叹号";
        case 词元类型::问号: return "问号";
        case 词元类型::井号: return "井号";
        case 词元类型::脱字符: return "脱字符";
        case 词元类型::波浪号: return "波浪号";
        case 词元类型::百分号: return "百分号";
        case 词元类型::大于号: return "大于号";
        case 词元类型::小于号: return "小于号";
        case 词元类型::美元符: return "美元符";
        case 词元类型::下划线: return "下划线";
        case 词元类型::左圆括号: return "左圆括号";
        case 词元类型::右圆括号: return "右圆括号";
        case 词元类型::左花括号: return "左花括号";
        case 词元类型::右花括号: return "右花括号";
        case 词元类型::左方括号: return "左方括号";
        case 词元类型::右方括号: return "右方括号";
    }
    return "";
}

struct 词元结构 {
    词元类型 类型;
    std::string 文本;
    int 行号;
    int 列号;
};

inline std::ostream& operator<<(std::ostream& os, 词元类型 类型) {
    return os << 类型文本(类型);
}

inline std::ostream& operator<<(std::ostream& os, const 词元结构& t) {
    os << "[" << t.类型 << "] " << t.文本
       << " (行" << t.行号 << " 列" << t.列号 << ")";
    return os;
}

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
}