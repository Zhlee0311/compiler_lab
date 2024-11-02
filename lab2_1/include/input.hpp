#ifndef __INPUT_HPP
#define __INPUT_HPP

#include <iostream>
#include <unordered_map>

/**
 *@brief 一个用于存储操作符优先级的哈希表
 * 0-9(48-57)
 * 字母a-z(97-122)
 * 字母A-Z(65-90)
 * 两个特殊符号'('和')'，不参与优先级运算
 */
std::unordered_map<char, int> precedence = {
    {'*', 3}, // 闭包
    {'@', 2}, // 连接
    {'|', 1}  // 或
};

/**
 * @brief 在正规式需要连接的地方插入‘@’表示连接
 * @param string 待预处理的串
 * @return 处理后的串
 */
std::string pre_process(std::string s);

/**
 * @brief 中缀表达式转换为后缀表达式
 * @param string 中缀表达式
 * @return 后缀表达式
 */
std::string trans_postfix(std::string s);

#endif