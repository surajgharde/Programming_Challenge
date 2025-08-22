#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    // Step 1: Remove extra spaces
    stringstream ss(s);
    string word;
    vector<string> words;

    while (ss >> word) {   // ss >> word automatically ignores extra spaces
        words.push_back(word);
    }

    // Step 2: Reverse the words
    reverse(words.begin(), words.end());

    // Step 3: Join words with a space
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) {
            result += " ";
        }
    }

    return result;
}

int main() {
    string s = "  the   sky   is  blue ";
    cout << reverseWords(s) << endl;
    return 0;
}
