#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for(int i = 1; i*i <= n; i++) {
        cout << i*i << " ";
    }
    // Only the perfect squares will be the bulbs that will be on. 
    // As the factors of a number are always in pairs, so the number of factors of a number will be odd only if the number is a perfect square.
    

    return 0;
}