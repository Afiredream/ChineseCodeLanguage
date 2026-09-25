#pragma once

#include <memory>
#include <string>
#include <vector>

enum class 语句种类 {
    定义语句,
    结构语句,
    模块语句,
    赋值语句,
    控制语句,
    访问语句
};

struct 语句节点 {
    语句种类 种类;
    std::string 文本;
    int 行号;
    int 列号;
};

class 语法分析 {
public:
    explicit 语法分析(std::string 源码);
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


// 定义语句

enum class 定义语句类型 {
    变量定义,
    常量定义,
    容量定义,
    属性定义,
    方法定义
};

struct 变量定义 {
    定义语句类型 种类 = 定义语句类型::变量定义;
    std::string 名称;
    std::string 类型;
    std::string 量值;
    int 行号 = 0;
    int 列号 = 0;
};

struct 常量定义 {
    定义语句类型 种类 = 定义语句类型::常量定义;
    std::string 名称;
    std::string 类型;
    std::string 量值;
    int 行号 = 0;
    int 列号 = 0;
};

struct 容量定义 {
    定义语句类型 种类 = 定义语句类型::容量定义;
    std::string 名称;
    std::string 类型;
    std::string 量值;
    int 行号 = 0;
    int 列号 = 0;
};

struct 属性定义 {
    定义语句类型 种类 = 定义语句类型::属性定义;
    std::string 名称;
    std::string 类型;
    std::string 量值;
    int 行号 = 0;
    int 列号 = 0;
};

struct 方法定义 {
    定义语句类型 种类 = 定义语句类型::方法定义;
    std::string 名称;
    std::string 类型;
    std::string 量值;
    int 行号 = 0;
    int 列号 = 0;
};


// 结构语句

struct 结构语句参数 {
    std::string 类型;
    std::string 名称;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

enum class 结构语句类型 {
    函数定义,
    函数调用,
    结构定义,
    结构调用
};

struct 函数定义 {
    结构语句类型 种类 = 结构语句类型::函数定义;
    std::string 类型;
    std::string 名称;
    std::vector<结构语句参数> 参数;
    std::string 子块;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 函数调用 {
    结构语句类型 种类 = 结构语句类型::函数调用;
    std::string 名称;
    std::vector<std::string> 参数;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 结构定义 {
    结构语句类型 种类 = 结构语句类型::结构定义;
    std::string 类型;
    std::string 名称;
    std::vector<结构语句参数> 参数;
    std::string 子块;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 结构调用 {
    结构语句类型 种类 = 结构语句类型::结构调用;
    std::string 名称;
    std::vector<std::string> 参数;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

// 模块语句

enum class 模块语句类型 {
    导出模块,
    导入模块
};

struct 导出模块 {
    模块语句类型 种类 = 模块语句类型::导出模块;
    std::vector<std::string> 列表;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 导入模块 {
    模块语句类型 种类 = 模块语句类型::导入模块;
    std::string 名称,
    std::vector<std::string> 列表;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

// 赋值语句

enum class 赋值语句类型 {
    直接赋值, // 甲 = 乙
    复合赋值, // 甲 += 乙, 甲 -= 乙 ...
    自增赋值, // 甲++
    自减赋值, // 甲--
    混合赋值 // 甲, 乙 = 丙, 丁
};

struct 简单赋值 {
    赋值语句类型 种类 = 赋值语句类型::简单赋值;
    std::string 目标;            // 左值文本
    std::string 值;              // 右值文本
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 复合赋值 {
    赋值语句类型 种类 = 赋值语句类型::复合赋值;
    std::string 目标;            // 左值
    std::string 运算符;          // "+=", "-=", "*=", "/=" ...
    std::string 值;              // 右值
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 自增语句 {
    赋值语句类型 种类 = 赋值语句类型::自增;
    std::string 目标;
    bool 是前缀 = false;         // ++a 为 true，a++ 为 false
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 自减语句 {
    赋值语句类型 种类 = 赋值语句类型::自减;
    std::string 目标;
    bool 是前缀 = false;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 混合赋值 {
    赋值语句类型 种类 = 赋值语句类型::多重赋值;
    std::vector<std::string> 目标列表;   // 左边多个
    std::vector<std::string> 值列表;     // 右边多个
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

// 控制语句

enum class 控制语句类型 {
    如果语句,
    循环语句,
    遍历语句,
    分支语句,
    跳转语句,
    返回语句,
    异常语句,
    代码语句
};

struct 如果语句 {
    控制语句类型 种类 = 控制语句类型::如果语句;
    std::string 条件;            // 条件文本
    std::string 则分支;          // 子块文本
    std::string 否则分支;        // 可空
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 循环语句 {
    控制语句类型 种类 = 控制语句类型::循环语句;
    std::string 循环方式;        // "while" / "do-while" / "loop"
    std::string 条件;            // 条件，可空（loop 无条件）
    std::string 循环体;          // 子块文本
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 遍历语句 {
    控制语句类型 种类 = 控制语句类型::遍历语句;
    std::string 迭代变量;        // for x in ...
    std::string 可迭代对象;      // 被遍历的对象
    std::string 循环体;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 分支语句 {
    控制语句类型 种类 = 控制语句类型::分支语句;
    std::string 被匹配值;        // switch / match 的目标
    std::vector<std::string> 分支值列表;   // 每个分支的值
    std::vector<std::string> 分支体列表;   // 与分支值一一对应
    std::string 默认分支;        // 可空
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 跳转语句 {
    控制语句类型 种类 = 控制语句类型::跳转语句;
    std::string 跳转方式;        // "break" / "continue" / "goto"
    std::string 目标标签;        // goto 用，可空
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 返回语句 {
    控制语句类型 种类 = 控制语句类型::返回语句;
    std::string 返回值;          // 可空
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 异常语句 {
    控制语句类型 种类 = 控制语句类型::异常语句;
    std::string 异常方式;        // "try" / "throw"
    std::string 异常体;          // try 块
    std::string 捕获变量;        // catch(e) 里的 e，可空
    std::string 捕获体;          // catch 块，可空
    std::string 最终体;          // finally 块，可空
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 代码块 {
    控制语句类型 种类 = 控制语句类型::代码块;
    std::vector<std::string> 语句列表;   // 子语句文本
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

// 访问语句

enum class 访问语句类型 {
    成员访问,
    索引访问,
    属性获取,
    属性设置,
    方法调用
};

struct 成员访问 {
    访问语句类型 种类 = 访问语句类型::成员访问;
    std::string 对象;            // 被访问对象
    std::string 成员;            // 成员名
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 索引访问 {
    访问语句类型 种类 = 访问语句类型::索引访问;
    std::string 对象;            // 被索引对象
    std::string 下标;            // 索引值
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 属性获取 {
    访问语句类型 种类 = 访问语句类型::属性获取;
    std::string 对象;
    std::string 属性名;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 属性设置 {
    访问语句类型 种类 = 访问语句类型::属性设置;
    std::string 对象;
    std::string 属性名;
    std::string 新值;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

struct 方法调用 {
    访问语句类型 种类 = 访问语句类型::方法调用;
    std::string 对象;            // 接收者
    std::string 方法名;
    std::vector<std::string> 参数;
    std::string 文本;
    int 行号 = 0;
    int 列号 = 0;
};

