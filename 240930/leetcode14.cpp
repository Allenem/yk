#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort by ascii/字母顺序
        sort(strs.begin(), strs.end(), [](string a, string b) {
            return a < b;
        });
        // for(auto s : strs) cout << s << " ";
        string smin = strs[0], smax = strs[strs.size() - 1];
        int sminlen = min(smin.length(), smax.length());

        // cout << smin << " " << smax << endl;
        for(int i = 0; i < sminlen; i++) {
            if(smin[i] != smax[i]) return smin.substr(0, i);
        }
        return smin;
    }
};

int main() {
    Solution solution;

    vector<string> strs = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(strs) << endl;

    strs = {"dog", "racecar", "car"};
    cout << solution.longestCommonPrefix(strs) << endl;

    return 0;
}