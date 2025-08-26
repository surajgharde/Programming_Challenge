#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mapping = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        // If it's an opening bracket
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // If it's a closing bracket
        else {
            if (st.empty() || st.top() != mapping[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    cout << boolalpha; // to print true/false instead of 1/0
    cout << isValid("[{()}]") << endl; // true
    cout << isValid("([)]") << endl;   // false
    cout << isValid("{[]}") << endl;   // true
    cout << isValid("(") << endl;      // false
    return 0;
}
