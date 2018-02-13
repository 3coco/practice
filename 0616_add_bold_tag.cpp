#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution616 {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> masks(s.length(), false);
        string result = "";

        for(int i = 0; i < s.length(); i++) {
            for(string pattern: dict) {
                if((i + pattern.length()) <= s.length() && (s.substr(i, pattern.length()) == pattern)) {
                    for(int j = i; j < (i + pattern.length()); j++) {
                        masks[j] = true;
                    }
                }
            }
        }  // end of 1st for loop
       
        for(int i = 0; i < s.length(); i++) {
            if(masks[i] == true && (i == 0 || !masks[i - 1])) {
                result += "<b>";
            }
            result += s[i];
            if(masks[i] == true && (i == s.length() - 1 || !masks[i + 1])) {
                result += "</b>";
            }
        }

        return result;
    }
};

int main() {
    Solution616 sol;

    string words1[2] = {"abc", "123"};
    vector<string> dict1(words1, words1 + sizeof(words1) / sizeof(words1[0]));
    string ret = sol.addBoldTag("abcxyz123", dict1);
    string ans = "<b>abc</b>xyz<b>123</b>";
    if(ret != ans) {
        cout << "Test#1 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    string words2[3] = {"aaa", "aab", "bc"};
    vector<string> dict2(words2, words2 + sizeof(words2) / sizeof(words2[0]));
    ret = sol.addBoldTag("aaabbcc", dict2);
    ans = "<b>aaabbc</b>c";
    if(ret != ans) {
        cout << "Test#2 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    return 0;
}
