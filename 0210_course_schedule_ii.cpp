// https://leetcode.com/problems/course-schedule-ii/description/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution207 {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> > &prereqs) {
        unordered_map<int, unordered_set<int> > graph;
        vector<int> ans;

        for(int i = 0; i < numCourses; i++) {
            graph.insert(make_pair(i, unordered_set<int>()));
        }
        for(auto it = prereqs.begin(); it != prereqs.end(); it++) {
            graph[it->second].insert(it->first);
        }

        bool can_finish = topo_sort(graph, ans);
        if(can_finish) {
            reverse(ans.begin(), ans.end());
            return ans;
        } else {
            return {};
        }
    }
private:
    bool dfs(int node, unordered_set<int> &visited, unordered_set<int> &onpath,
                unordered_map<int, unordered_set<int> > &graph, vector<int> &ans) {
        if(onpath.find(node) != onpath.end()) {
            return false;
        }
        if(visited.find(node) != visited.end()) {
            return true;
        }
        visited.insert(node);
        onpath.insert(node);

        for(auto it = graph[node].begin(); it != graph[node].end(); it++) {
            if(!dfs(*it, visited, onpath, graph, ans)) {
                return false;
            }
        }
        ans.push_back(node);
        onpath.erase(node);
        return true;
    }

    bool topo_sort(unordered_map<int, unordered_set<int> > &graph, vector<int> &ans) {
        unordered_set<int> visited;
        unordered_set<int> onpath;
        for(auto it = graph.begin(); it != graph.end(); it++) {
           if(!dfs(it -> first, visited, onpath, graph, ans)) {
               return false;
           }
        }
        return true;
    }
};

int main() {
    Solution207 sol;
    vector<pair<int, int> > prereqs0;
    vector<int> ans0 {0};

    if(sol.findOrder(1, prereqs0) != ans0) {
        cout << "Test #0 failed." << endl;
    }

    vector<pair<int, int> > prereqs1;
    prereqs1.push_back(make_pair<int, int>(1, 0));
    prereqs1.push_back(make_pair<int, int>(2, 0));
    prereqs1.push_back(make_pair<int, int>(3, 1));
    prereqs1.push_back(make_pair<int, int>(3, 2));

    vector<int> ret1 = sol.findOrder(5, prereqs1);
    vector<int> ans1 {0, 1, 2, 3, 4};
    if(ret1 != ans1) {
        cout << "Test 1 failed." << endl;
    }
    return 0;
}
