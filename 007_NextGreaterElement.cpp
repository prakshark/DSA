#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>vec = {4, 5, 2, 10, 8};
    stack<int>st;
    // Next Greater Element to the Right :-

    // To find the next greater element to the right of each element, we will traverse the array from right to the left. We will pop all the elements from the stack until the top of the stack has ana element graetaer thatn the current element. Once we get that, we will store the corresponding top of the stack value as the NGETR for the current element. If the stack is empty for any element, we store -1 as the NGETR for that element.

    vector<int>NGETR(vec.size(), -1);

    for(int i = vec.size() - 1; i >= 0; i--) {
        int curr = vec[i];
        if(st.size() == 0) {
            NGETR[i] = -1;
            st.push(curr);
        }
        else {
            while(st.size() > 0 && st.top() <= curr) {
                st.pop();
            }
            if(st.size() == 0) {
                NGETR[i] = -1;
            }
            else {
                NGETR[i] = st.top();
            }
            st.push(curr);
        }
    }
    for(auto i: NGETR) cout << i << " ";
    return 0;
}