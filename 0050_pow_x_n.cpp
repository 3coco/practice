// https://leetcode.com/problems/powx-n/description/

#include <iostream>

using namespace std;

class Solution50 {
public:
	double myPow(double x, int n) {
		long long N = n;
		if(n < 0) {
			x = 1.0 / x;
			N = -N;
		}

		double ans = 1;
		double cur_product = x;

		for(long long i = N; i > 0; i >>= 1) {
			if((i & 1) == 1) {
				ans *= cur_product;
			}
			cur_product *= cur_product;
		}
		return ans;
	}
};

int main() {
	Solution50 sol;
	double ret1 = sol.myPow(2.0000, 10);
	double ans1 = 1024.00;

	if(ret1 != ans1) {
		cout << "Test#1 failed." << endl;
	}

	double ret2 = sol.myPow(2.0000, -3);
	double ans2 = 0.125;
	if(ret2 != ans2) {
		cout << "Test#2 failed" << endl;
	}
	return 0;
}