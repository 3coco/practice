// https://leetcode.com/problems/sentence-similarity-ii/description/

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution737 {
public:
    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2,
            vector<pair<string, string> > pairs){
        if(words1.size() != words2.size()) {
            return false;
        }
        unordered_map<string, string> m;
        for(int i = 0; i < pairs.size(); i++) {
            string parent1 = find(m, pairs[i].first);
            string parent2 = find(m, pairs[i].second);
            if(parent1 != parent2) {
                m[parent1] = parent2;
            }
        }
        for(int i = 0; i < words1.size(); i++) {
            if(words1[i] != words2[i] && find(m, words1[i]) != find(m, words2[i])) {
                return false;
            }
        }
        return true;
    }
private:
    string find(unordered_map<string, string> &m, string s) {
        return m.count(s) == 0 ? m[s] = s : (m[s] == s ? s : find(m, m[s]));
    }
};

int main() {
    Solution737 sol;
    vector<pair<string, string> > pairs1;
    pairs1.push_back(make_pair("great", "good"));
    pairs1.push_back(make_pair("fine", "good"));
    pairs1.push_back(make_pair("acting", "drama"));
    pairs1.push_back(make_pair("skills", "talent"));

    vector<string> words1;
    vector<string> words2;
    words1.push_back("great");
    words1.push_back("acting");
    words1.push_back("skills");
    words2.push_back("fine");
    words2.push_back("drama");
    words2.push_back("talent");
    
    if(!sol.areSentencesSimilarTwo(words1, words2, pairs1)) {
        cout << "Test #1 failed." << endl;
    }
    return 0;
}
