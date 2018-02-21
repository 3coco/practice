#include <iostream>
#include <vector>

using namespace std;

class Solution484 {
    public:
        vector<int> findPermutation(string s) {
            vector<int> result;
            if(s.size() == 0) {
                return result;
            }
            int low = 1;
            int countD = 0;
            s += 'I';
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == 'D') {
                    countD++;
               } else if(s[i] == 'I') {
                    int tmp_low = low + countD + 1;
                    while(countD > 0) {
                        result.push_back(low + countD);
                        countD--;
                    }
                    result.push_back(low);
                    low = tmp_low;
                }
            }
            return result;
        }
};

int main() {
    Solution484 sol;
    int arr[2] = {1, 2};
    vector<int> ans(arr, arr + 2); 
    vector<int> ret = sol.findPermutation("I");
    if(ret != ans) {
        cout << "Test#1 failed" << endl;
    }

    int arr2[3] = {2, 1, 3};
    vector<int> ans2(arr2, arr2 + 3);
    vector<int> ret2 = sol.findPermutation("DI");
    if(ret2 != ans2) {
        cout << "Test#2 failed" << endl;
    }

    return 0;
}
