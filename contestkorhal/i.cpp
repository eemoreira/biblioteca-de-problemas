#include <bits/stdc++.h>

using namespace std;
const int MAX = 5e5 + 50;
int h[MAX];
int n;

bool check(int x, int mid) {
    int q = 0;
    for (int i = x, cnt = 0, j = x; cnt < mid; i--, cnt++, j++) {
        if (h[i] < mid - q) return false;
        if (h[j] < mid - q) return false;
        q++;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int ans = 1;
    int l = 1, r = n + 10;
    while (l <= r) {
        int mid = (l + r) >> 1;
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (i - mid + 1 < 0 || i + mid - 1 >= n) continue;
            if (check(i, mid)) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}





