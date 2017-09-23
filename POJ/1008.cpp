#include <iostream>
#include <string>
#include <map>

const size_t allHaabMonth = 19;
const size_t allHollyMonth = 20;

const std::string haab[allHaabMonth] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
                                        "zac",
                                        "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
const std::string holly[allHollyMonth] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk",
                                          "ok",
                                          "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

// 定义一个map
std::map<std::string, int> monthToDays;

// 初始化map
void init() {
    // 直接给天数
    for (int i = 0; i < 19; ++i) {
        monthToDays[haab[i]] = i * 20;
    }
}

// 直接输出吧，返回参数好麻烦
void getHolly(const int &day, const std::string &month, const int &year) {
    // 由于从0开始，天数加个1
    int days = day + monthToDays[month] + year * 365 + 1;
    // 查出来的
    int h_year = (days - 1) / 260;
    int h_month = (days - 1) % 20;
    int h_day = days % 13 == 0 ? 13 : days % 13;

    // 输出
    std::cout << h_day << " " << holly[h_month] << " " << h_year << std::endl;
}

int main() {
    init();
    // 要输入的变量
    int day = 0;
    std::string month;
    int year = 0;
    int count = 0;
    // 输入次数
    std::cin >> count;
    // 跳到坑里不知自拔哎
    std::cout << count << std::endl;
    // 收小点
    char ch;
    for (int i = 0; i < count; ++i) {
        // 输入数据
        std::cin >> day >> ch >> month >> year;
        // 处理
        getHolly(day, month, year);
    }

    return 0;
}

/*
 * Sample Input

3
10. zac 0
0. pop 0
10. zac 1995

Sample Output

3
3 chuen 0
1 imix 0
9 cimi 2801
 * */
