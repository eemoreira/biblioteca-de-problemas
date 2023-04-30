#include <bits/stdc++.h>
#define ll long long
void solve();

void ans(ll x, ll count){        
    if(x >= 5){
    if(x%5 != 0){
        ans(x-1,count);
    }
    else{
        ll t = x;
        while(x%5 == 0){
            count++;
            x = x/5;
    }
        ans(t-5, count);
    }
    }
    else{
        std::cout << count << "\n";
    }
}

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){
    ll n; cin >> n;
    ans(n,0);
}