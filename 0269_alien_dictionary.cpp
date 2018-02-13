// https://leetcode.com/problems/alien-dictionary

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool dfs(char node, unordered_set<char> &visited,
            unordered_set<char> &onpath,
            unordered_map<char, unordered_set<char> > &g, string &order) {
    if(onpath.find(node) != onpath.end()) {
        return false;
    }
    if(visited.find(node) != visited.end()) {
        return true;
    }
    visited.insert(node);
    onpath.insert(node);
    for(auto iter = g[node].begin(); iter != g[node].end(); iter++) {
        if(!dfs(*iter, visited, onpath, g, order)) {
            return false;
        }
    }
    onpath.erase(node);
    order += node;
    return true;
}

string topo_sort(unordered_map<char, unordered_set<char> > &g) {
    string order = "";
    unordered_set<char> onpath;
    unordered_set<char> visited;
    
    for(auto iter = g.begin(); iter != g.end(); iter++) {
        if(!dfs(iter -> first, visited, onpath, g, order)) {
           return "";
        }
    }
    return order;
}

string alienOrder(vector<string>& words) 
{
    if(words.size() == 1) {
        return words[0];
    }
    unordered_map<char, unordered_set<char> > graph;

    for(int i = 1; i < words.size(); i++) {
        string w1 = words[i - 1];
        string w2 = words[i];
        bool done = false;
        for(int j = 0; j < max(w1.length(), w2.length()); j++) {
            if(j < w1.length() && graph.find(w1[j]) == graph.end()) {
                graph.insert(make_pair(w1[j], unordered_set<char>()));
            }
            if(j < w2.length() && graph.find(w2[j]) == graph.end()) {
                graph.insert(make_pair(w2[j], unordered_set<char>()));
            }
            // bug: check bound was missing
            // if(!done && w1[j] != w2[j]) { 
            if(!done && j < min(w1.length(), w2.length()) && w1[j] != w2[j]){
                graph[w2[j]].insert(w1[j]);
                done = true;
            }
        }
    }
    return topo_sort(graph);
}

int main() {
    vector<string> vec0;
    if(alienOrder(vec0) == "") {
        cout << "test case #0 passed" << endl;
    }

    string words1[2] = {"z", "x"};
    vector<string> vec1(words1, words1 + sizeof(words1) / sizeof(words1[0])); 
    if(alienOrder(vec1) == "zx") {
        cout << "test case #1 passed" << endl;
    }
    
    string words2[3] = {"z", "x", "z"};
    vector<string> vec2(words2, words2 + sizeof(words2) / sizeof(words2[0]));
    if(alienOrder(vec2) == "") {
        cout << "test case #2 passed" << endl;
    }

    string words3[5] = {
                         "wrt",
                         "wrf",
                         "er",
                         "ett",
                         "rftt"
                       };
    vector<string> vec3(words3, words3 + sizeof(words3) / sizeof(words3[0]));
    if(alienOrder(vec3) == "wertf") {
        cout << "test case #3 passed" << endl;
    }

    return 0;
}
