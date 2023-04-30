#include <bits/stdc++.h>
#define ll long long
void solve();

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){
    ll n; cin >> n;
    set<ll> nums;
    while(n--){
        ll t; cin >>t;
        nums.insert(t);
    }
    cout << nums.size() << "\n";
}