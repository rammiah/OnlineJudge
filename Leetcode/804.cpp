/*".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."*/
const vector<string> ch2morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string, bool> m;
        string s;
        for (const auto &word : words) {
            s = "";
            for (const auto &ch : word) {
                s.append(ch2morse[ch-'a']);
            }
            m[s] = true;
        }

        return m.size();
    }
};