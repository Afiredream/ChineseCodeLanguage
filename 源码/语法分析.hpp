#pragma once

#include <string>
#include <vector>

#include "词法分析.hpp"
#include "语法类型.hpp"

struct 语句节点 {
  int 行号 = 0;
  int 列号 = 0;
};

struct 变量定义 : 语句节点 {
  语句类型 语句 = 语句类型::变量定义;
  std::string 名称;
  std::string 类型;
  std::string 数据;
  std::string 文本;
};

struct 常量定义 : 语句节点 {
  语句类型 语句 = 语句类型::常量定义;
  std::string 名称;
  std::string 类型;
  std::string 量值;
  std::string 文本;
};

struct 容量定义 : 语句节点 {
  语句类型 语句 = 语句类型::容量定义;
  std::string 名称;
  std::string 类型;
  std::string 量值;
  std::string 文本;
};

struct 属性定义 : 语句节点 {
  语句类型 语句 = 语句类型::属性定义;
  std::string 名称;
  std::string 类型;
  std::string 量值;
  std::string 文本;
};

struct 方法定义 : 语句节点 {
  语句类型 语句 = 语句类型::方法定义;
  std::string 名称;
  std::string 类型;
  std::string 量值;
  std::string 文本;
};

// ============================================================
// 结构语句
// ============================================================
struct 参数 : 语句节点 {
  std::string 名称;
  std::string 类型;
  std::string 文本;
};

struct 函数定义 : 语句节点 {
  语句类型 语句 = 语句类型::函数定义;
  std::string 名称;
  std::string 类型;
  std::vector<参数> 参数;
  std::string 子块;
  std::string 文本;
};

struct 函数调用 : 语句节点 {
  语句类型 语句 = 语句类型::函数调用;
  std::string 名称;
  std::vector<std::string> 参数;
  std::string 文本;
};

struct 结构定义 : 语句节点 {
  语句类型 语句 = 语句类型::模板定义;
  std::string 名称;
  std::string 类型;
  std::vector<参数> 参数;
  std::string 子块;
  std::string 文本;
};

struct 结构调用 : 语句节点 {
  语句类型 语句 = 语句类型::模板调用;
  std::string 名称;
  std::vector<std::string> 参数;
  std::string 文本;
};

// ============================================================
// 模块语句
// ============================================================
struct 导出模块 : 语句节点 {
  语句类型 语句 = 语句类型::导出模块;
  std::vector<std::string> 列表;
  std::string 文本;
};

struct 导入模块 : 语句节点 {
  语句类型 语句 = 语句类型::导入模块;
  std::string 名称;
  std::string 文本;
};

// ============================================================
// 赋值语句
// ============================================================
struct 直接赋值 : 语句节点 {
  语句类型 语句 = 语句类型::直接赋值;
  std::string 名称;
  std::string 量值;
  std::string 文本;
};

struct 复合赋值 : 语句节点 {
  语句类型 语句 = 语句类型::复合赋值;
  std::string 名称;
  std::string 符号;
  std::string 量值;
  std::string 文本;
};

struct 自增赋值 : 语句节点 {
  语句类型 语句 = 语句类型::自增赋值;
  std::string 名称;
  std::string 文本;
};

struct 自减语句 : 语句节点 {
  语句类型 语句 = 语句类型::自减赋值;
  std::string 名称;
  std::string 文本;
};

struct 混合赋值 : 语句节点 {
  语句类型 语句 = 语句类型::混合赋值;
  std::vector<std::string> 名称列表;
  std::vector<std::string> 量值列表;
  std::string 文本;
};

// ============================================================
// 控制语句
// ============================================================
struct 循环语句 : 语句节点 {
  语句类型 语句 = 语句类型::循环语句;
  std::string 循环方式;
  std::string 条件;
  std::string 循环体;
  std::string 文本;
};

struct 分支语句 : 语句节点 {
  语句类型 语句 = 语句类型::条件语句;
  std::string 被匹配值;
  std::vector<std::string> 分支值列表;
  std::vector<std::string> 分支体列表;
  std::string 默认分支;
  std::string 文本;
};

struct 跳转语句 : 语句节点 {
  语句类型 语句 = 语句类型::跳转语句;
  std::string 跳转方式;
  std::string 目标标签;
  std::string 文本;
};

struct 返回语句 : 语句节点 {
  语句类型 语句 = 语句类型::返回语句;
  std::string 返回值;
  std::string 文本;
};

struct 代码子块 : 语句节点 {
  语句类型 语句 = 语句类型::代码子块;
  std::vector<std::string> 语句列表;
  std::string 文本;
};

// ============================================================
// 访问语句
// ============================================================
struct 索引访问 : 语句节点 {
  语句类型 语句 = 语句类型::索引访问;
  std::string 对象;  // 被索引对象
  std::string 下标;  // 索引值
  std::string 文本;
};

struct 属性访问 : 语句节点 {
  语句类型 语句 = 语句类型::属性访问;
  std::string 对象;
  std::string 属性名;
  std::string 文本;
};

struct 方法访问 : 语句节点 {
  语句类型 语句 = 语句类型::方法访问;
  std::string 对象;
  std::string 方法名;
  std::vector<std::string> 参数;
  std::string 文本;
};

struct 管道访问 : 语句节点 {
  语句类型 语句 = 语句类型::管道访问;
  std::string 对象;
  std::string 属性名;
  std::string 文本;
};

class 语法分析 {
 public:
  explicit 语法分析(词元结构 词元);
  std::vector<语句节点> 代码分析();

 private:
  std::vector<语句节点> 列表_;
  int 序号_ = 0;
  int 行号_ = 1;
  int 列号_ = 1;
  std::string 当前词元();
  std::string 下个词元();
  词元结构 构造词元(词元类型 类型, const std::string& 文本);
};