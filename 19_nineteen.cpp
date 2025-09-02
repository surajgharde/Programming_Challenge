#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string expression) {
    stack<int> st;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
         
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);  
        } 
        
        else {
            st.push(stoi(token));
        }
    }

    return st.top();  
}

int main() {
    string expression = "2 1 + 3 *";
    cout << evaluatePostfix(expression) << endl;  
    return 0;
}
