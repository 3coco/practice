// https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/description/

#include <iostream>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution158 {
public:
    char cache[4];
    int csize;
    char *cptr;
    
    Solution158(): csize(0), cptr(&cache[0]){};
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */ 
    int read(char *buf, int n) {
        if(n == 0) {
            return 0;
        }
        int cur = 0;
        int ret;
        while(csize > 0) {
            buf[cur++] = *cptr;
            cptr++;
            csize--;
            if(cur == n) {
                return n;
            }
        }
        while((ret = read4(buf + cur)) > 0) {
            cur += ret;
            if(cur >= n) {
                int i;
                for(i = 0; i < (cur - n); i++) {
                    cache[i] = buf[n + i];
                }
                cptr = &cache[0];
                csize = i;
                return n;
            }
        }
        return cur;
    }
};
