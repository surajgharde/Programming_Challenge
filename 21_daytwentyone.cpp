#include <iostream>
#include <stack>
using namespace std;

 void insertAtBottom(stack<int> &st, int element) {
    if (st.empty()) {
        st.push(element);
        return;
    }
 
    int topElement = st.top();
    st.pop();

   
    insertAtBottom(st, element);

    
    st.push(topElement);
}

 
void reverseStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }
 
    int topElement = st.top();
    st.pop();
 
    reverseStack(st);

    
    insertAtBottom(st, topElement);
}

int main() {
    stack<int> st;

 
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack (Top to Bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
 
    reverseStack(st);

    cout << "Reversed Stack (Top to Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
