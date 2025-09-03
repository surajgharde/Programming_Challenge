#include <iostream>
#include <stack>
using namespace std;

void insertInSortedOrder(stack<int>& st, int element) {

    if (st.empty() || element > st.top()) {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();
    insertInSortedOrder(st, element);
    st.push(temp);
}

void sortStack(stack<int>& st) {
    if (!st.empty()) {
        
        int temp = st.top();
        st.pop();
        sortStack(st);

        insertInSortedOrder(st, temp);
    }
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    cout << "Sorted Stack (Top to Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
