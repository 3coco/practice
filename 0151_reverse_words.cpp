// https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution151 {
public:
    void reverseWords(string &s) {
        reverseEachWord(s);
        reverse(s.begin(), s.end());
    }
private:
    // leading and trailing spaces should be removed
    // multiple spaces btw. words should be reduced to one space
    void reverseEachWord(string &s) {
        int i = 0, j = 0, l;
        int len = s.length();
        int count = 0;  /* word count */

        while(true) {
            while(i < len && s[i] == ' ') {
                i++;  /* i always travels faster or equal to j */
            }
            if(i == len) {
                break;
            }
            if(count > 0) {
                s[j++] = ' ';   /* need to append a space to all words except the first word. */
            }
            l = j;  /* record the starting position of the current word */
            while(i < len && s[i] != ' ') {
                s[j++] = s[i++];
            }
            reverse(s.begin() + l, s.begin() + j);
            count++;
        }
        s.resize(j);
    }
};

int main() {
    Solution151 sol;
    string s1 = "the sky is blue";
    sol.reverseWords(s1);
    if(s1 != "blue is sky the") {
        cout << "Test #1 failed." << endl;
    }
    return 0;
}
