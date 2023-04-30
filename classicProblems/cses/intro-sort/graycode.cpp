#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

int n;
string bin(int x) {
    string ans;
    int cnt = 0;
    while (x) {
        ans += ('0' + (x & 1));
        x >>= 1;
        cnt++;
    }
    for (int i = cnt; i < n; i++) ans += '0';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 1 << n; i++) {
        cout << bin(i ^ (i >> 1)) << '\n';
    }
}





