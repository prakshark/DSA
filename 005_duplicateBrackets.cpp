#include<bits/stdc++.h>
using namespace std;

int main() {
    bool ans = false;
    string str = "(c+d)";
    stack<char>st;
    for(auto ch: str) {
        if(ch == ')') {
            if(st.top() == '(') {
                ans = true;
            }
            else {
                while(st.top() != '(') {
                    st.pop();
                }
                st.pop();
            }
        }
        else {
            st.push(ch);
        }
    }
    cout << ans << endl;

    return 0;
}