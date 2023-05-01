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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i && a[i] - a[i-1] <= d) {
            cout << a[i] << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}





