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
    ll sum = n*(n+1)/2;
    set<ll> s1,s2;
    string res = "NO\n";
    if(sum%2==0){
        res = "YES\n";
    ll halfsum = sum/2;
    ll t = n;
    for(ll k=0;k<n;k++){
        s1.insert(k+1); 
    }
    while(halfsum != 0){
        if(halfsum - t >= 0){
        s2.insert(t);
        s1.erase(t);
        halfsum -= t;
        }
        t--;
    }
    }
    cout << res;
    cout << s1.size() << "\n";
    for(ll u : s1){
        cout << u << " ";
    }
    cout << "\n";
    cout << s2.size() << "\n";
    for(ll u : s2){
        cout << u << " ";
    }   
    
}
