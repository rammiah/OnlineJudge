#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cctype>


/*
题目描述
给定一个英文字符串,请写一段代码找出这个字符串中首先出现三次的那个英文字符。
输入描述:
输入数据一个字符串，包括字母,数字等。
输出描述:
输出首先出现三次的那个英文字符
示例1
输入
Have you ever gone shopping and
输出
e
 */

int main() {
    // 直接使用字典，不考虑数组了
    std::map<char, int> count;
    std::string line;
    std::getline(std::cin, line);

    int len = line.length();
    for (int i = 0; i < len; ++i) {
        // 判断是否是字母
        if (std::isalpha(line[i])) {
            count[line[i]]++;
            // 个数超过3个就输出并结束
            if (count[line[i]] >= 3) {
                std::cout << line[i] << "\n";
                break;
            }
        }
    }


    return 0;
}