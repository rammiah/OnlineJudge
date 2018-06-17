#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string order_in, order_out;
    // freopen("data.txt", "r", stdin);
    int cnt;
    while (cin >> cnt) {
        cin >> order_in >> order_out;
        // 检测入栈出栈顺序是否正确，并打出顺序
        stack<char> cs;
        // 检查是否正确
        int idx_in = 0, idx_out = 0;
        bool ok = true;
        string result;
        while (!cs.empty() || idx_in < cnt || idx_out < cnt) {
            // 先看要不要出栈
            if (!cs.empty()) {
                if (idx_out < cnt && cs.top() == order_out[idx_out]) {
                    // 出栈一个吧
                    result.append("out\n");
                    cs.pop();
                    idx_out++;
                }
                else {
                    // 不相等压栈吧
                    if (idx_in < cnt) {
                        result.append("in\n");
                        cs.push(order_in[idx_in++]);
                    }
                    else {
                        // 出错了
                        ok = false;
                        break;
                    }
                }
            }
            else if (idx_in < cnt) {
                // 空了，进栈吧
                cs.push(order_in[idx_in++]);
                result.append("in\n");
            }
            else {
                ok = false;
                break;
            }
        }
        if (ok) {
            result = "Yes.\n" + result + "FINISH\n";
        }
        else {
            result = "No.\nFINISH\n";
        }
        cout << result;
    }


    return 0;
}