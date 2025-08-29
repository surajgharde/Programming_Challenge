#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, max_len = 0;

    for (int right = 0; right < s.size(); right++) {
        while (seen.count(s[right])) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl; // Output: 3
    return 0;
}
