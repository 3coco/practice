// https://leetcode.com/problems/count-primes/description/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution204 {
public:
    int countPrimes(int n) {
        if(n < 2) {
            return 0;
        }
        vector<bool> primes(n, true);
        int count = 0;
        for(int i = 2; i < (sqrt(n) + 1); i++) {
            if(primes[i]) {
                int j = i * i;
                while(j < n) {
                    primes[j] = false;
                    j += i;
                }
            }
        }
        for(int i = 2; i < n; i++) {
            if(primes[i]) {
                count++;
            }
        }
       return count; 
    }
};

int main() {
    Solution204 sol;
    if(sol.countPrimes(10) != 4) {
        cout << "Test #1 failed." << endl;
    }
    return 0;
}
