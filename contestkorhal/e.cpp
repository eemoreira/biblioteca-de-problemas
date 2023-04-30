#include <bits/stdc++.h>

using namespace std;

/* stop freaking out pls */
long long dpmin[1 << 16 | 5], dpmax[1 << 16 | 5], f[50];
string nums[100];
int n;
const int mod = 1e9 + 7;

int htd(char c) {
    if (c >= 'a') {
        return 10 + c - 'a';
    }
    return c - '0';
}

char dth(int i) {
    if (i >= 10) {
        i-=10;
        return 'a' + i;
    }
    return '0' + i;
}

long long hextodec(string &t) {
    long long ans = 0;
    long long b = 1;
    for (int i = (int)t.size() - 1; i >= 0; i--) {
        ans += b * htd(t[i]);
        b <<= 4;
    }
    return ans;
};

string dectohex(long long t) {
    string ans = "";
    if (t == 0) return string(1, '0');
    while (t) {
        ans += dth(t % 16);
        t >>= 4;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

long long getsum(long long mask) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        string now = "";
        for (auto x : nums[i]) {
            if (mask >> htd(x) & 1) {
                continue;
            }
            now += x;
        }
        ans += hextodec(now);
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    n = hextodec(s);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    f[0] = 1;
    for (int i = 1; i < 17; i++) {
        f[i] = f[i-1] * i % mod;
    }
    for (int i = 0; i < 1 << 16; i++) {
        dpmax[i] = -9e18;
        dpmin[i] = 9e18;
    }
    dpmax[0] = dpmin[0] = 0;
    long long all = 0;
    for (long long i = 1; i < 1 << 16; i++) {
        long long sum = getsum(i);
        int bits = 0;
        for (int j = 0; j < 16; j++) {
            if (i >> j & 1) {
                bits++;
                dpmax[i] = max(dpmax[i ^ (1 << j)] + sum, dpmax[i]);
                dpmin[i] = min(dpmin[i ^ (1 << j)] + sum, dpmin[i]);
            }
        }
        long long g = ((sum % mod) * f[16 - bits]) % mod;
        all += (g * f[bits] % mod) % mod;
        all %= mod;
    }
    cout << dectohex(dpmin[(1 << 16) - 1]) << ' ' << dectohex(dpmax[(1 << 16) - 1]) << ' ' << dectohex(all) << '\n';
}
