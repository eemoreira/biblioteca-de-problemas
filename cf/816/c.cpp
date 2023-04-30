#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void solve(){
    int n,m; cin>>n>>m;
    vector<int> a(n+1),dif(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    dif[1] = 1; 
    for(int i = 2; i <= n; i++){
        if(a[i-1] != a[i]) dif[i] = dif[i-1] + 1;
        else dif[i] = dif[i-1];
    }
    ull sum = 0;
    for(int i = 1; i <= n; i++) {
        sum+=dif[i];
    }
    ull cont=0;
    ull ans=sum;
    for(int i = 2; i <= n; i++){
        if(a[i-1] == a[i]){
            sum-=dif[i-1]-cont;
            ans+=sum;
        }
        else{
            int d = dif[i-1] + (n - i + 1) - cont;
            cont++;
            sum-=d;
            ans += sum;
        }
    }
    while(m--){
        ull ind,x;cin>>ind>>x;
        ull res = ans;
        if(x == a[ind]) ans = res;
        else if(ind > 1 && ind < n){
            if(x != a[ind - 1] && a[ind] == a[ind-1]) res += (ind-1)*(n-ind+1);
            if(x != a[ind + 1] && a[ind] == a[ind+1]) res += (ind)*(n-ind);
            if(x == a[ind - 1] && a[ind] != a[ind-1]) res -= (ind-1)*(n-ind+1);
            if(x == a[ind + 1] && a[ind] != a[ind+1]) res -= (ind)*(n-ind);
        }
        else{
            if(ind == 1){
                if(x != a[ind + 1] && a[ind] == a[ind+1]) res += n-1;
                if(x == a[ind + 1] && a[ind] != a[ind+1]) res -= (n-1);
            }
            if(ind == n){
                if(x != a[ind - 1] && a[ind] == a[ind-1]) res += n-1;
                if(x == a[ind - 1] && a[ind] != a[ind-1]) res-=(n-1);
            }
         }
        ans = res;
        a[ind] = x;
        cout << ans << endl;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

