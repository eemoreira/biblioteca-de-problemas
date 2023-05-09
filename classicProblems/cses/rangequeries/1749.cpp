#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

const int maxn = 2e5 + 5;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ordered_set<int> S;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S.insert(i);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int pos = *S.find_by_order(x - 1);
        S.erase(pos);
        cout << a[pos] << " \n"[i == n - 1];
    }
}





