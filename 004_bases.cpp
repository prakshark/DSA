#include<bits/stdc++.h>
using namespace std;

// Function to convert decimal to base
int decimalToBase(int n, int base) {
    string ans = "";
    while(n > 0) {
        int rem = n % base;
        ans = to_string(rem) + ans;
        n /= base;
    }
    int finalAns = stoi(ans);
    return finalAns;
}

int baseToDecimal(int n, int base) {
    int ans = 0;
    int power = 0;
    while(n > 0) {
        int rem = n % 10;
        ans += rem * pow(base, power);
        power++;
        n /= 10;
    }
    return ans;
}

int main() {
    // int n; cin >> n;
    // Hence, we can convert any base to any base, add, subtract, multiply, divide in any base using the above 2 functions.
    

    return 0;
}