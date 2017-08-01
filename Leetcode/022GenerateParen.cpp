class Solution 
{
private:
    void gene(vector<string> &sol, const string &str, int left, int right) {
        if (left > 0) {
            if (left > right) {
                return;
            }
            gene(sol, str + "(", left - 1, right);
            gene(sol, str + ")", left, right - 1);
        } else if (left == 0) {
            if (right == 0) {
                sol.push_back(str);
            } else if (right > 0){
                gene(sol, str + ")", 0, right - 1);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> strList;
        string str;
        gene(strList, str, n, n);
        return strList;
    }
};
