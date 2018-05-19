/*************************************************************************
	> File Name: _012IntToRoman.cpp
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年06月12日 星期一 22时10分02秒
 ************************************************************************/

#include <iostream>

using namespace std;

string intToRoman(int num) {
    string c[4][10]={
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
    };
    string roman;
    roman.append(c[3][num / 1000 % 10]);
    roman.append(c[2][num / 100 % 10]);
    roman.append(c[1][num / 10 % 10]);
    roman.append(c[0][num % 10]);

    return roman;
}

int main() {
    int num;
    std::cout << "Enter a decimal number: ";
    std::cin >> num;
    cout << intToRoman(num) << endl;

    return 0;
}
