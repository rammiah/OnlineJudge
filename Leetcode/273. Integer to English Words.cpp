class Solution {
    vector<string> bigs = { "zero", "Thousand", "Million", "Billion" };
    vector<string> tens = { "zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    vector<string> integers = { "zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten" };
    vector<string> tenswhat = { "zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};

    string numberToWords(int num, int index) {
        string big;
        if (num >= 1000) {
            big = numberToWords(num / 1000, index + 1);
        }
        string result;
        int n = num % 1000;
        if (n >= 100) {
            if (result.empty()) {
                result.append(integers[n / 100] + " Hundred");
            }
            else {
                result.append(" " + integers[n / 100] + " Hundred");
            }
            n %= 100;
        }
        // 大于二十分开说
        if (n > 20) {
            if (result.empty()) {
                result.append(tens[n / 10]);
            }
            else {
                result.append(" " + tens[n / 10]);
            }
            n %= 10;
            if (n > 0) {
                result.append(" " + integers[n]);
            }
        }
        else if (n > 0) {
            if (result.empty()) {
                result.append(tenswhat[n]);
            }
            else {
                result.append(" " + tenswhat[n]);
            }
        }
        if (!result.empty() && index > 0) {
            result.append(" " + bigs[index]);
        }
        if (!big.empty()) {
            if (result.empty()) {
                return big;
            }
            return big + " " + result;
        }
        return result;
    }
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return numberToWords(num, 0);
    }
};