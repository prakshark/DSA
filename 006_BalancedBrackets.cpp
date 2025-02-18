#include<bits/stdc++.h>
using namespace std;

int main() {
    bool ans = true; // true -> valid, false -> invalid
    string str = "{(c+d)]}";
    stack<char>st;

    for(auto ch: str) {
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if(ch == ')') {
            if(st.size() == 0) {
                ans = false;
                return 0;
            }
            else if(st.top() != '(') {
                ans = false;
                return 0;
            }
            else {
                st.pop();
            }
        }
        else if(ch == '}') {
            if(st.size() == 0) {
                ans = false;
                return 0;
            }
            else if(st.top() != '{') {
                ans = false;
                return 0;
            }
            else {
                st.pop();
            }
        }
        else if(ch == ']') {
            if(st.size() == 0) {
                ans = false;
                return 0;
            }
            else if(st.top() != '[') {
                ans = false;
                return 0;
            }
            else {
                st.pop();
            }
        }
    }
    if(st.size() > 0) ans = false;
    if(ans == true) cout << "Valid" << endl;
    else cout << "Invalid" << endl;

    return 0;
}