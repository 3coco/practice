// https://leetcode.com/problems/longest-absolute-file-path/description/
#include <string>
#include <stack>
#include <iostream>
#include <sstream>

using namespace std;

class Solution388 {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        stack<int> mystack;
        string s;
        int tmp, cur_max = 0;
        
        mystack.push(0); //dummy value
        while(getline(ss, s, '\n')) {
            int level = s.rfind('\t');
            if(level == string::npos) {
                level = 0;
            } else {
                level++;
            }

            while(level < mystack.size() - 1) {
                mystack.pop();
            }

            if(s.rfind('.') == string::npos) {
                // is a dir
                mystack.push(mystack.top() + s.size() - level + 1);
            } else if((tmp = mystack.top() + s.size() - level) > cur_max) {
                cur_max = tmp;
            }
         }

        return cur_max;
    }
};

int main() {
    Solution388 sol;
    string str1 = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    int ans1 = 20;
    int ret1 = sol.lengthLongestPath(str1);
    if(ret1 != ans1) {
        cout << "Test#1 failed" << endl;
    }

    return 0;
}
