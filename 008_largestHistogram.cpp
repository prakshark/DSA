#include<bits/stdc++.h>
using namespace std;

int main() {
    // For finding the largest poosible area in a histogram, for each of the bar(element), we need to find that keeping that as the height, what is the maximum width(range) that can be included in the histogram on its left and right that can be used to calculate the area, keeping that as the height.
    // Hence, we need to find the (next smaller element on the left + 1) and (right - 1) of each element in the histogram.
    // We do +1 and -1 as that is the valid range. Not considering that will make us reach an elenent that is less than the current element, which does not need to be included.
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
