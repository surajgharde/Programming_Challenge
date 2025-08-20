#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    unordered_map<int, vector<int>> seen;  // prefix_sum -> list of indices
    vector<pair<int, int>> result;
    int prefix_sum = 0;

    // prefix_sum = 0 means subarray from index 0..i has sum 0
    seen[0].push_back(-1);

    for (int i = 0; i < arr.size(); i++) {
        prefix_sum += arr[i];

        if (seen.find(prefix_sum) != seen.end()) {
            for (int start_index : seen[prefix_sum]) {
                result.push_back({start_index + 1, i});
            }
        }

        seen[prefix_sum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};

    vector<pair<int, int>> res = findZeroSumSubarrays(arr);

    if (res.empty()) {
        cout << "No subarray found\n";
    } else {
        for (auto &p : res) {
            cout << "(" << p.first << ", " << p.second << ")\n";
        }
    }
    return 0;
}
