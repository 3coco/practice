// https://leetcode.com/problems/zigzag-iterator/description/

#include <queue>
#include <vector>

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        if(v1.size() > 0) {
            my_queue.push(make_pair(v1.begin(), v1.end()));
        }
        if(v2.size() > 0) {
            my_queue.push(make_pair(v2.begin(), v2.end()));
        }
    }

    int next() {
        vector<int>::iterator it = my_queue.front().first;
        vector<int>::iterator it_end =my_queue.front().second;
        my_queue.pop();
        if(it + 1 != it_end) {
            my_queue.push(make_pair(it + 1, it_end));
        }
        return *it;
    }

    bool hasNext() {
        return !my_queue.empty(); 
    }

private:
    queue<pair<vector<int>::iterator, vector<int>::iterator> > my_queue;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    // TODO
    return 0;
}
