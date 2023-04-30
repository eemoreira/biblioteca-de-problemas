#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

int k, n;
bool check(vector<int>& a) {
    for (int i = 1; i < k; i++) {
        if (a[i] != a[i-1]) {
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n;
    vector<int> a(k);
    ii mn = {1e9,1e9};
    ii mx = {0, 0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        --x;
        a[x]++;
    }
    for (int i = 0; i < k; i++) {
        mx = max(mx, make_pair(a[i], i));
        mn = min(mn, make_pair(a[i], i));
    }
    a[mx.second]--;
    if (check(a)) {
        cout << '-' << mx.second + 1 << '\n';
        return 0;
    }
    a[mx.second]++;
    a[mn.second]++;
    if (check(a)) {
        cout << '+' << mn.second + 1 << '\n';
        return 0;
    }
    a[mx.second]--;
    if (check(a)) {
        cout << '-' << mx.second + 1 << " +" << mn.second + 1 << '\n';
        return 0;
    }
    cout << "*\n";
}





