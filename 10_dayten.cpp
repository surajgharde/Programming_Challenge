#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    
    for (string word : strs) {
        vector<int> count(26, 0);
        for (char c : word) {
            count[c - 'a']++;
        }
        
        // Convert count vector into a string key
        string key;
        for (int freq : count) {
            key += to_string(freq) + "#"; 
        }
        
        mp[key].push_back(word);
    }
    
    vector<vector<string>> result;
    for (auto &entry : mp) {
        result.push_back(entry.second);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> groups = groupAnagrams(strs);
    
    for (auto group : groups) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
