// https://www.geeksforgeeks.org/shortest-common-supersequence/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum Move {
    Match,
    Del1,
    Del2
};

class ShortestCommonSupersequence {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        longestCommonSubsequence(str1, str2);
        return traceSupersequence(str1, str2, str2.size(), str1.size(), "");
    }

    int longestCommonSubsequence(string str1, string str2) {
        reset();
        for(int i = 0; i <= str2.size(); i++) {
            vector<int> results;
            vector<int> moves;
            results.push_back(0);
            moves.push_back(Del2);
            for(int j = 1; j <= str1.size(); j++) {
                if(i == 0) {
                    results.push_back(0);
                    moves.push_back(Del1);
                    continue;
                }
                if(str2[i - 1] == str1[j - 1]) {
                    results.push_back(1 + opt[opt.size() - 1][j - 1]);
                    moves.push_back(Match);
                } else {
                    int del1_res = results[results.size() - 1];
                    int del2_res = opt[opt.size() - 1][j];
                    results.push_back(max(del1_res, del2_res));
                    if(del1_res >= del2_res) {
                        moves.push_back(Del1);
                    } else {
                        moves.push_back(Del2);
                    }
                }
            } // end of inner for loop
            opt.push_back(results);
            traces.push_back(moves);
        } // end of outer for loop
        
        return opt[str2.size()][str1.size()];
    }

    void debug() {
        for(int i = 0; i < opt.size(); i++) {
            for(int j = 0; j < opt[0].size(); j++) {
                cout << opt[i][j] << " ";
            }
            cout << endl;
        }
        cout << "------" << endl;
        for(int i = 0; i < traces.size(); i++) {
             for(int j = 0; j < traces[0].size(); j++) {
                 cout << traces[i][j] << " ";
             }
             cout << endl;
         }
    }
private:
    string traceSupersequence(string str1, string str2, int i, int j, string partial) {
        if(i == 0 && j == 0) {
            return partial;
        }
        if(traces[i][j] == Match) {
            return traceSupersequence(str1, str2, i - 1, j - 1, str1[j - 1] + partial);
        } else if(traces[i][j] == Del1) {
            return traceSupersequence(str1, str2, i, j - 1, str1[j - 1] + partial);
        } else {
            return traceSupersequence(str1, str2, i - 1, j, str2[i - 1] + partial);
        }
    }

    void reset() {
        opt.clear();
        traces.clear();
    }

    vector<vector<int> > opt;
    vector<vector<int> > traces;
};


int main() {
    ShortestCommonSupersequence sol;

    int ret1 = sol.longestCommonSubsequence("", "abc");
    cout << ret1 << endl;
    int ret2 = sol.longestCommonSubsequence("abc", "");
    cout << ret2 << endl;
    int ret3 = sol.longestCommonSubsequence("", "");
    cout << ret3 << endl;
    int ret4 = sol.longestCommonSubsequence("abcde", "abcde");
    cout << ret4 << endl;
    int ret5 = sol.longestCommonSubsequence("ABCDGH", "AEDFHR");
    cout << ret5 << endl;
    int ret6 = sol.longestCommonSubsequence("AGGTAB", "GXTXAYB");
    cout << ret6 << endl;
    cout << sol.shortestCommonSupersequence("abc", "") << endl;
    cout << sol.shortestCommonSupersequence("geek", "eke") << endl;
    cout << sol.shortestCommonSupersequence("AGGTAB", "GXTXAYB") << endl;
    return 0;
}
