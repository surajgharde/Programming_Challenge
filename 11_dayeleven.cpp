#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> permuteUnique(string s) {
        vector<string> result;
        sort(s.begin(), s.end()); // Sort to handle duplicates easily
        vector<bool> used(s.size(), false);
        string current = "";
        backtrack(s, used, current, result);
        return result;
    }

private:
    void backtrack(string &s, vector<bool> &used, string &current, vector<string> &result) {
        if (current.size() == s.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (used[i]) continue;
            // Skip duplicates
            if (i > 0 && s[i] == s[i-1] && !used[i-1]) continue;

            used[i] = true;
            current.push_back(s[i]);
            backtrack(s, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution sol;
    string s = "abc";
    vector<string> ans = sol.permuteUnique(s);

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "\"" << ans[i] << "\"";
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}
