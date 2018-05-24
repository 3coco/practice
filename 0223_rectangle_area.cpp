#include <iostream>

using namespace std;

class Solution223 {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        // Bug: int overflow
        // int interW = min(C, G) - max(A, E) < 0 ? 0 : min(C, G) - max(A, E);
        int interW = min(C, G) < max(A, E) ? 0 : min(C, G) - max(A, E);
        // int interH = min(D, H) - max(B, F) < 0 ? 0 : min(D, H) - max(B, F);
        int interH = min(D, H) < max(B, F) ? 0 : min(D, H) - max(B, F);
        return area1 - interW * interH + area2;
    }
};

int main() {
    Solution223 sol;
    int ret = sol.computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1);
    if(ret != 2) {
        cout << "Test #1 failed." << endl;
    }
}
