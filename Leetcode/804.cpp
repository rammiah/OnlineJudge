/*".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."*/
const vector<string> ch2morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> str_set;
        string s;
        for (const auto &word : words) {
            s = "";
            for (const auto &ch : word) {
                s.append(ch2morse[ch-'a']);
            }
            str_set.insert(s);
        }

        return str_set.size();
    }
};