#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>vec= {6, 2, 5, 4, 5, 1, 6};

    vector<int>nextSmallerOnLeft;
    stack<int>st1; 
    for(int i = 0; i < vec.size(); i++) {
        int num = vec[i];
        if(st1.size() == 0) {
            nextSmallerOnLeft.push_back(0);  // 0 indicates no smaller element found
            st1.push(i);  // Store index instead of the element
        }
        else {
            while(st1.size() > 0 && vec[st1.top()] >= num) {
                st1.pop();
            }
            if(st1.size() == 0) {
                nextSmallerOnLeft.push_back(0);  // -1 means no smaller element found on the left
            }
            else {
                nextSmallerOnLeft.push_back(st1.top() + 1);  // Push the index of next smaller element
            }
            st1.push(i);  // Push the current index into the stack
        }
    }

    vector<int>nextSmallerOnRight;
    stack<int>st2;
    for(int i = vec.size() - 1; i >= 0; i--) {
        int num = vec[i];
        if(st2.size() == 0) {
            nextSmallerOnRight.push_back(vec.size() - 1);  // -1 indicates no smaller element found
            st2.push(i);
        }
        else {
            while(st2.size() > 0 && vec[st2.top()] >= num) {
                st2.pop();
            }
            if(st2.size() == 0) {
                nextSmallerOnRight.push_back(vec.size() - 1);  // -1 means no smaller element found on the right
            }
            else {
                nextSmallerOnRight.push_back(st2.top() - 1);  // Push the index of next smaller element
            }
            st2.push(i);  // Push the current index into the stack
        }
    }
    reverse(nextSmallerOnRight.begin(), nextSmallerOnRight.end());

    int maxArea = 0;
    for(int i = 0; i < vec.size(); i++) {
        int width = nextSmallerOnRight[i] - nextSmallerOnLeft[i] + 1;
        int area = vec[i] * width;
        maxArea = max(maxArea, area);
    }
    cout << maxArea << endl;

    return 0;
}
