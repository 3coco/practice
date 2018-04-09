// https://leetcode.com/problems/the-skyline-problem/description/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution218 {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> > &buildings) {
        priority_queue<pair<int, int> > liveBlgs;
        vector<pair<int, int> > results;
        int i = 0;
        int n = buildings.size();

        while(i < n || !liveBlgs.empty()) {
            int curX = liveBlgs.empty() ? buildings[i][0] : liveBlgs.top().second;

            if(i >= n || buildings[i][0] > curX) {
                while(!liveBlgs.empty() && liveBlgs.top().second <= curX) {
                    liveBlgs.pop();
                }
            } else {
                curX = buildings[i][0];
                while(i < n && buildings[i][0] == curX) {
                    liveBlgs.push(make_pair(buildings[i][2], buildings[i][1]));
                    i++;
                }
            }

            int curH = liveBlgs.empty() ? 0 : liveBlgs.top().first;
            if(results.empty() || results.back().second != curH) {
                results.push_back(make_pair(curX, curH));
            }
        }

        return results;
    }
};

int main() {
    Solution218 sol;
    vector<vector<int> > vec1 {{2, 9, 10}, {3, 7, 15},
                               {5, 12, 12}, {15, 20, 10},
                               {19, 24, 8}};
    vector<pair<int, int> > ans1;
    ans1.push_back(make_pair(2, 10));
    ans1.push_back(make_pair(3, 15));
    ans1.push_back(make_pair(7, 12));
    ans1.push_back(make_pair(12, 0));
    ans1.push_back(make_pair(15, 10));
    ans1.push_back(make_pair(20, 8));
    ans1.push_back(make_pair(24, 0));
    vector<pair<int, int> > ret1 = sol.getSkyline(vec1);
    if(ret1 != ans1) {
        cout << "Test #1 failed" << endl;
    }
    return 0;
}
