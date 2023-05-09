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
const int lg = 31;
const int maxn = lg * (int)1e5 + 10;
int one[maxn], zero[maxn];
int cnt, root;

int newnode() {
    one[cnt] = zero[cnt] = -1;
    return cnt++;
}

void insert(int x) {
    int v = root;
    for (int i = lg; i >= 0; i--) {
        if (x >> i & 1) {
            if (one[v] == -1) one[v] = newnode();
            v = one[v];
        }
        else {
            if (zero[v] == -1) zero[v] = newnode();
            v = zero[v];
        }
    }
}

int query(int x) {
    int v = root;
    int ans = 0;
    for (int i = lg; i >= 0; i--) {
        if (x >> i & 1) {
            if (one[v] != -1) {
                v = one[v];
                ans |= 1 << i;
            }
            else if (zero[v] != -1) {
                v = zero[v];
            }
            else return ans;
        }
        else {
            if (zero[v] != -1) {
                v = zero[v];
            }
            else if (one[v] != -1) {
                v = one[v];
                ans |= 1 << i;
            }
            else return ans;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    root = newnode();
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;
        insert(now);
        x ^= now;
        cout << (x ^ query(x)) << '\n';
    }
}





