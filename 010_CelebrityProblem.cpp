#include<bits/stdc++.h>
using namespace std;

// Celebrity Problem: YOu are given an nxn matrix. arr[i][j] tells if i knows j or not. If 1, then i knows j, else not. A celebrity is a person who is known by everyone but doesn't know anyone. Find the celebrity in the given matrix.

// Method 1: Traverse the matrix and check for each person if he is celebrity or not. O(n^2)
// Method 2: Use stack to find the celebrity. O(n)

// Method 2: Push all elements into the stack. Pop 2 elements at a time, and check if a knows b. If a knows b, then a can't be celebrity, so push b into stack. Else, push a into stack. At the end, we will have only 1 element in the stack. Check if that element is celebrity or not.

int main() {
    vector<vector<int>>vec;
    for(int i = 0; i < 5; i++) {
        vector<int>temp;
        for(int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        vec.push_back(temp);
    }

    stack<int>st;
    for(int i = 0; i < 5; i++) {
        st.push(i);
    }

    while(st.size() != 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(vec[a][b] == 1) { // a knows b
            st.push(b);
        } 
        else { // a doesn't know b
            st.push(a);
        }
    }

    int possibleCelebrity = st.top();
    bool isCelebrity = true;
    for(int i = 0; i < 5; i++) {
        if(vec[possibleCelebrity][i] == 1) {
            isCelebrity = false;
            break;
        }
    }

    if(isCelebrity) {
        cout << "Celebrity is: " << possibleCelebrity << endl;
    } 
    else {
        cout << "No Celebrity" << endl;
    }



    return 0;
}