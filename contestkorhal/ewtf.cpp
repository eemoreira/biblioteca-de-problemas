#include <bits/stdc++.h>

using namespace std;

/* stop freaking out pls */
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<char, int, custom_hash> htd;
/* map<char,int> htd; */

long long dpmin[1 << 16 | 5], dpmax[1 << 16 | 5], f[50];
char dth[40];
string nums[100];
int n;
const int mod = 1e9 + 7;

long long hextodec(string &t) {
    long long ans = 0;
    long long b = 1;
    for (int i = (int)t.size() - 1; i >= 0; i--) {
        ans += b * htd[t[i]];
        b <<= 4;
    }
    return ans;
};

string dectohex(long long t) {
    string ans = "";
    if (t == 0) return string(1, '0');
    while (t) {
        ans += dth[t % 16];
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
            if (mask >> htd[x] & 1) {
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
    for (int i = 0; i < 10; i++) {
        dth[i] = i + '0';
        htd[i + '0'] = i;
    }
    for (int i = 0; i < 6; i++) {
        dth[10 + i] = 'a' + i;
        htd[i + 'a'] = i + 10;
    }
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
