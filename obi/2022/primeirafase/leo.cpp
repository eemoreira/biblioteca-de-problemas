#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    map<int, int> freq;
    int ps[n + 1];
    ps[0] = 0;
    freq[0]++;
    int l = 0;
    int r = 0;
    int soma = 0;
    for (int i=1; i < n + 1; i++) {
        int num; cin >> num;
        soma += num;
        freq[soma]++;
        ps[i] = soma;
    }
    int resp = 0;
    for (int i=0; i < n + 1; i++) {
        int b = ps[i] - k;
        if (b < 0) continue;
        if (freq.find(b) != freq.end()) {
            resp += freq[b];
        }
    }
    cout << resp << endl;
}
