#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int gap = ceil((double)(m + n) / 2);

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < (m + n)) {
            // Case 1: both in arr1
            if (i < m && j < m) {
                if (arr1[i] > arr1[j]) {
                    swap(arr1[i], arr1[j]);
                }
            }
            // Case 2: i in arr1, j in arr2
            else if (i < m && j >= m) {
                if (arr1[i] > arr2[j - m]) {
                    swap(arr1[i], arr2[j - m]);
                }
            }
            // Case 3: both in arr2
            else {
                if (arr2[i - m] > arr2[j - m]) {
                    swap(arr2[i - m], arr2[j - m]);
                }
            }
            i++;
            j++;
        }

        if (gap == 1) break;
        gap = ceil((double)gap / 2);
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    merge(arr1, arr2, arr1.size(), arr2.size());

    cout << "arr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
