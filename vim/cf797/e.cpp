#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 2e5 + 5;

void solve(){
    int n,k;cin>>n>>k;
    ll md[mx];
    ll res=0;
    for(int i = 0 ; i < n ; i++){
        ll a; cin>>a;
        res+=a/k;
        md[i] = a%k;
    }
    int s=0,b=n-1;
    sort(begin(md),begin(md)+n);
    while(s<b){
        if(md[s] + md[b] >= k){
            res++;s++;b--;
        }
        else s++;
    }
    cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
    while(t--)
    solve();
	return 0;
}

