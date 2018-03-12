// https://leetcode.com/problems/fraction-to-recurring-decimal/description/

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution166 {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) {
            return "0";
        }

        string res;
        long long n = numerator;
        long long d = denominator;
        long long remainder = 0;
        unordered_map<long long, int> map;

        if((n < 0) ^ (d < 0)) {
            res += '-';
        }

        n = abs(n);
        d = abs(d);
        res += to_string(n / d);
        remainder = n % d;
        if(remainder == 0) {
            return res;
        }
        res += '.';
        
        while(remainder != 0) {
           if(map.find(remainder) != map.end()) {
               res.insert(map[remainder], 1, '(');
               res += ')';
               break;
           }
           map[remainder] = res.size();
           remainder *= 10;
           res += to_string(remainder / d);
           remainder = remainder % d;
        }

        return res;
    }
};

int main() {
    Solution166 sol;
    if(sol.fractionToDecimal(0, 1) != "0") {
        cout << "Test #1 failed" << endl;
    }
    if(sol.fractionToDecimal(20, 4) != "5") {
        cout << "Test #2 failed" << endl;
    }
    if(sol.fractionToDecimal(1, 2) != "0.5") {
        cout << "Test #3 failed" << endl;
    }
    if(sol.fractionToDecimal(-1, 8) != "-0.125") {
        cout << "Test #4 failed" << endl;
    }
    if(sol.fractionToDecimal(1, -8) != "-0.125") {
        cout << "Test #5 failed" << endl;
    }
    if(sol.fractionToDecimal(-1, -4) != "0.25") {
        cout << "Test #6 failed" << endl;
    }
    if(sol.fractionToDecimal(-2147483648, -1) != "2147483648") {
        cout << "Test #7 failed" << endl;
    }
    if(sol.fractionToDecimal(1, 3) != "0.(3)") {
        cout << "Test #8 failed" << endl;
    }
    if(sol.fractionToDecimal(15, 7) != "2.(142857)") {
        cout << "Test #9 failed" << endl;
    }
}
