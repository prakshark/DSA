#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "ddd";
    vector<int>iPos;
    iPos.push_back(0);
    for(int it = 0; it < s.size(); it++) {
        if(s[it] == 'i') {
            iPos.push_back(it + 1);
        }
    }
    iPos.push_back(s.size() + 1);

    vector<bool>used(10, false);
    vector<string>ans;

    for(int i = 0; i < iPos.size() - 1; i++) {
        string temp = "";
        int r = iPos[i + 1];
        int l = iPos[i];
        for(int j = r; j > l; j--) {
            if(used[j] == false) {
                temp.push_back(j + '0');
                used[j] = true;
            }
        }
        ans.push_back(temp);
    }

    for(auto i: ans) {
        cout << i << " ";
    }

    // string finalAns = "";
    // for(int i = 0; i < ans.size(); i++) {
    //     finalAns += ans[i];
    //     // if(i != ans.size() - 1) finalAns += " ";
    // }
    // cout << finalAns << endl;

    return 0;
}