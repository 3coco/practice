#include <iostream>
#include <vector>

using namespace std;

class Solution274 {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for(int i = 0; i < citations.size(); i++) {
            if(citations[i] >= i + 1) {
                h = i + 1;
            } else {
                break;
            }
        }
        return h;
    }
};

int main() {
    Solution274 sol;
    vector<int> cits {3, 0, 6, 1, 5};
    if(sol.hIndex(cits) != 3) {
        cout << "Test #1 failed." << endl;
    }
    return 0;
}
