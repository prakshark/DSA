#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int copya = a, copyb = b;
    while(a % b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    int gcd = b;
    int lcm = (copya * copyb) / gcd;

    cout << "GCD: " << gcd << endl;
    cout << "LCM: " << lcm << endl;

    return 0;
}