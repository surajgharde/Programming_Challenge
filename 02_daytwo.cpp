#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& arr, int n) {
    int totalSum = n * (n + 1) / 2;
    int arraySum = 0;
    for (int num : arr) arraySum += num;
    return totalSum - arraySum;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    cout << findMissingNumber(arr, n) << endl;
    return 0;
}