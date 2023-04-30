#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
    int n, m;
    cin >> n >> m;
    cout << "? " << 1 << ' ' << m << endl;
    cout.flush();
    int a, b;
    cin >> a;
    cout << "? " << n << ' ' << m << endl;
    cout.flush();
    cin >> b;
    pair<int,int> f = {1 + a, m - a}, g = {n - b, m - b};
    dbg(f, g);
    if (f.second <= 0) {
        cout << "? " << f.first << ' ' << 1 << endl;
        cout.flush();
        int now;
        cin >> now;
        cout << "! " << f.first << ' ' << 1 + now << endl;
    }
    else if (g.first <= 0) {
        cout << "? " << 1 << ' ' << g.second << endl;
        cout.flush();
        int now;
        cin >> now;
        cout << "! " << 1+now << ' ' << g.second << endl;

    }
    else if (g.second <= 0) {
        cout << "? " << g.first << ' ' << 1 << endl;
        cout.flush();
        int now;
        cin >> now;
        cout << "! " << g.first << ' ' << 1 + now << endl;
    }
    else if (f.first == g.first) {
        cout << "? " << f.first << ' ' << 1 << endl;
        cout.flush();
        int now;
        cin >> now;
        cout << "! " << f.first << ' ' << 1 + now << endl;
    }
    else if (f.second == g.second) {
        cout << "? " << 1 << ' ' << f.second << endl;
        cout.flush();
        int now;
        cin >> now;
        cout << "! " << 1 + now << ' ' << f.second << endl;
    }
    else if (f.second < g.second) {
        cout << "? " << f.first << ' ' << 1 << endl;
        int now;
        cin >> now;
        cout << "! " << f.first << ' ' << 1+now << endl;
    }
    else if (g.second < f.second) {
        cout << "? " << g.first << ' ' << 1 << endl;
        int now;
        cin >> now;
        cout << "! " << g.first << ' ' << 1+now << endl;
    }
    else assert(false);
    cout.flush();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





