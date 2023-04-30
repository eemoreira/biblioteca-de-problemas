#include <bits/stdc++.h>
#define ll long long
void solve();

using namespace std;
const ll md = 1000000007;

ll pow1(ll b, ll p, ll x){
    ll ans=1;
    for(ll i=1;i<=p;i++){
        ans = (ans*b) % x;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){
    ll n; cin >> n;
    cout << pow1(2,n,md) << "\n";
}
