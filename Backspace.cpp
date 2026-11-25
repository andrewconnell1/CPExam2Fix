#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;

    for(int i = 0; i < s.length(); i++) {
        if (s[i] != '<') st.push(s[i]);
        else (st.pop());
    }

    vector<char> s1;

    while(!st.empty()) {
        s1.push_back(st.top());
        st.pop();
    }

    reverse(s1.begin(), s1.end());

    for(int i = 0; i < s1.size(); i++) {
        cout << s1[i];
    }

    cout << "\n";
    return 0;

}