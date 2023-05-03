#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

const int maxn = 2e5 + 5;
int n;
ll a[maxn];
vector<int> qntr, qntl;

bool go(int mx, int l, int r) {
    if (l == r) return a[l] > mx;
    bool ok = false;
    dbg(l, r);
    if (a[l] > a[r]) {
        if (qntr[l] & 1) return true;
        if (a[r] > mx) ok |= !go(a[r], l, r - 1);
    }
    if (a[r] > a[l]) {
        if (qntl[r] & 1) return true;
        if (a[l] > mx) ok |= !go(a[l], l + 1, r);
    }
    else {
        ok |= qntr[l] & 1;
        ok |= qntl[r] & 1;
    }
    return ok;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    qntr = vector<int>(n);
    qntl = vector<int>(n);
    for (int i = 0; i < n; i++) {
        int t = i + 1;
        int qnt = 1;
        while (t < n && a[t] > a[t - 1]) {
            qnt++;
            t++;
        }
        for (int j = i; j < t; j++) {
            qntr[j] = qnt--;
        }
        i = t - 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        int t = i - 1;
        int qnt = 1;
        while (t >= 0 && a[t] > a[t + 1]) {
            qnt++;
            t--;
        }
        for (int j = i; j > t; j--) {
            qntl[j] = qnt--;
        }
        i = t + 1;
    }
    dbg(qntl, qntr);
    cout << (go(0, 0, n - 1) ? "Alice\n" : "Bob\n");
}


