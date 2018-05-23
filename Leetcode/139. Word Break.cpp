#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
vector<bool> state;    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(!s.size()) {
            return true;
        }
        
        if(!wordDict.size() && s.size()) {
            return false;
        }
        
        state.resize(s.size() + 1, false);

        sort(wordDict.begin(), wordDict.end(), [](const string& a, const string& b) {
            if(a.size() == b.size()) {
                return a < b;
            }
            return a.size() < b.size();
        });
        
        
        int i = s.size();
        state[s.size()] = true;
        while(i) {
            if(state[i]) {
                for(auto &w : wordDict) {
                    int j = i - w.size();
                    if(j < 0)
                        break;
                    if(s.substr(j, w.size()) == w)
                        state[j] = true;
                }
            }
            --i;
        }
        
                
        return state[0];
    }
};
