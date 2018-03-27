class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1, b1, a2, b2;
        sscanf(a.c_str(), "%d+%di", &a1, &b1);
        sscanf(b.c_str(), "%d+%di", &a2, &b2);
        int a3 = a1 * a2 - b1 * b2, b3 = a1 * b2 + a2 * b1;
        string s;
        s.append(to_string(a3));
        s.append("+");
        s.append(to_string(b3));
        s.append("i");
        std::cout << s << "\n";
        return s;
    }
};