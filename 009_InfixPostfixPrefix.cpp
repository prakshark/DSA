#include<bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if(c == '+') return 1;
    if(c == '-') return 1;
    if(c == '*') return 2;
    if(c == '/') return 2;
}

int operation(int v1, int v2, char op) {
    if(op == '+') return v1 + v2;
    if(op == '-') return v1 - v2;
    if(op == '*') return v1 * v2;
    if(op == '/') return v1 / v2;
}

// In infix, we see precedence, and when we encounter an operator, then we deal with all the operators in the operatiorStack until the precedence is higher or equal to the current operator. We pop 2 operands and one operator and perform the operation and push the result back to the operandStack.

// In postfix, we simply push the operands to the operandStack and when we encounter an operator, we pop 2 operands and perform the operation and push the result back to the operandStack.

// In prefix, we push the operands to the operandStack and when we encounter an operator, we pop 2 operands and perform the operation and push the result back to the operandStack.

int main() {
    // Infix evaluation :-
    vector<string>vec2 = {"2", "+", "6", "*", "4", "/", "8"};
    stack<int>st2;
    stack<char>op;
    for(auto i: vec2) {
        if(i == "+" || i == "-" || i == "*" || i == "/") {
            while(!op.empty() && precedence(op.top()) >= precedence(i[0])) {
                int v2 = st2.top();
                st2.pop();
                int v1 = st2.top();
                st2.pop();
                st2.push(operation(v1, v2, op.top()));
                op.pop();
            }
            op.push(i[0]);
        }
        else {
            st2.push(stoi(i));
        }
    }
    while(!op.empty()) {
        int v2 = st2.top();
        st2.pop();
        int v1 = st2.top();
        st2.pop();
        st2.push(operation(v1, v2, op.top()));
        op.pop();
    }
    cout << st2.top() << endl;


    // Postfix Evaluation :-
    vector<string>vec = {"2", "6", "4", "*", "8", "/", "+"};
    stack<int>st;
    for(auto i: vec) {
        if(i == "+" || i == "-" || i == "*" || i == "/") {
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            st.push(operation(v1, v2, i[0]));
        }
        else {
            st.push(stoi(i));
        }
    }
    cout << st.top() << endl;

    // Prefix Evaluation :-
    vector<string>vec1 = {"+", "2", "/", "*", "6", "4", "8"};
    stack<int>st1;
    for(int i = vec1.size() - 1; i >= 0; i--) {
        if(vec1[i] == "+" || vec1[i] == "-" || vec1[i] == "*" || vec1[i] == "/") {
            int v1 = st1.top();
            st1.pop();
            int v2 = st1.top();
            st1.pop();
            st1.push(operation(v1, v2, vec1[i][0]));
        }
        else {
            st1.push(stoi(vec1[i]));
        }
    }
    cout << st1.top() << endl;
    
}