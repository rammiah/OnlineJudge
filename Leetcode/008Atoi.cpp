/*************************************************************************
	> File Name: 008Atoi.cpp
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年06月03日 星期六 14时12分01秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
class Solution {
public:
    int myAtoi(string str) {
        long ans=0;
        int len = str.length();
        int neg=1;
        int i=0;
        while(str[i]==' ')
            i++;
        if(str[i]=='-')
        {
            i++;
            neg=-1;
        }
        else if(str[i]=='+')
        {
            i++;
        }
               
        
        for(i;i<len;i++)
        {
            if(str[i]>='0' && str[i]<='9')
               { ans = ans*10 + (str[i]-48);
                   if(ans*neg >= INT_MAX)return INT_MAX;
        if(ans*neg <= INT_MIN)return INT_MIN;
               }
            else
            {
                break;
            }
        }
        
        
        return ans*neg;
    }
};
