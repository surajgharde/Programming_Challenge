#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N;
    cin >> N;

    int count = 0;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            if (i == N / i) {
                count++; 
            } else {
                count += 2; 
            }
        }
    }

    cout << count << endl;
    return 0;
}
