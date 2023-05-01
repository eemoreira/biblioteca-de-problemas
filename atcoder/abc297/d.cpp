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

/* stop freaking out pls */
ll solve(ll a, ll b) {
    if (a == b) return 0;
    if (a < b) swap(a, b);
    ll ops = (a - 1) / b;
    return ops + solve(b, a - b * ops);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b) << '\n';
}





