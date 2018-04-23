// https://leetcode.com/problems/course-schedule/description/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution207 {
public:
    bool canFinish(int numCourses, vector<pair<int, int> > &prereqs) {
        unordered_map<int, unordered_set<int> > graph;
        for(auto it = prereqs.begin(); it != prereqs.end(); it++) {
            if(graph.find(it->second) == graph.end()) {
                graph.insert(make_pair(it->second, unordered_set<int>()));
            }
            graph[it->second].insert(it->first);
        }

        return topo_sort(graph);
    }
private:
    bool dfs(int node, unordered_set<int> &visited, unordered_set<int> &onpath,
                unordered_map<int, unordered_set<int> > &graph) {
        if(onpath.find(node) != onpath.end()) {
            return false;
        }
        if(visited.find(node) != visited.end()) {
            return true;
        }
        visited.insert(node);
        onpath.insert(node);

        for(auto it = graph[node].begin(); it != graph[node].end(); it++) {
            if(!dfs(*it, visited, onpath, graph)) {
                return false;
            }
        }
        onpath.erase(node);
        return true;
    }

    bool topo_sort(unordered_map<int, unordered_set<int> > &graph) {
        unordered_set<int> visited;
        unordered_set<int> onpath;
        for(auto it = graph.begin(); it != graph.end(); it++) {
           if(!dfs(it -> first, visited, onpath, graph)) {
               return false;
           }
        }
        return true;
    }
};

int main() {
    Solution207 sol;
    vector<pair<int, int> > prereqs1;
    prereqs1.push_back(make_pair<int, int>(0, 1));
    prereqs1.push_back(make_pair<int, int>(1, 0));

    if(sol.canFinish(2, prereqs1) != false) {
        cout << "Test #1 failed" << endl;
    }

    vector<pair<int, int> > prereqs2;
    prereqs2.push_back(make_pair<int, int>(0, 1));
    
    if(sol.canFinish(2, prereqs2) != true) {
        cout << "Test #2 failed" << endl;
    }
    return 0;
}
