#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(begin(v), end(v));
    for(auto u : v){
        mp[u]++;
    }
    int z =1;
    if(k==0 && v[0] != 1) {
        cout << 1 << endl;
        z = 0;
    }
    if(z){
    int count=0;
    for(auto u : mp){
        count += u.second;
        if(count == k){
            cout << u.first << endl;
            break;
        }
        if(count > k) {
            cout << -1 << endl;
            break;
        }
    }
}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

