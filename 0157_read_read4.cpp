// https://leetcode.com/problems/read-n-characters-given-read4/description/

#include <iostream>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution157 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cur = 0;
        int ret;
        while((ret = read4(buf + cur)) > 0) {
            cur += ret;
        }
        return min(cur, n);
    }
};
