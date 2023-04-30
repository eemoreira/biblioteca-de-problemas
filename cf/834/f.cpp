#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 1;

void solve(){
    int n,base; cin >> n >> base;
    vll a(n);
    for(auto &u : a) cin >> u;
    map<int,int> f;
    for(auto u : a)f[u]++;
    int cnt = 0;
    if(base <= 100 || a[n-1] <= 100){
        bool ok = true;
        for(int i = 0; i < a[n-1]; i++) ok &= (f[i]!=0);
        if(ok){
            int t = base - 1;
            while(f[t] && t > a[n-1]) t--;
            /* cout << "t: " << t << '\n'; */
            cout << t - a[n-1] << '\n';
            return;
        }
    }
    int ans = base - a[n-1];
    /* cout << base << ' ' << a[n-1] << ' ' << ans << '\n'; */
    int it = n-2;
    while(it >= 0){
        if(a[it] == base-1){
            if(it == 0) f[1]++;
            it--;
        }
        else{
            f[++a[it]]++;
            break;
        }
    }
    f[0]++;
    if(n==1)f[1]++;
    int t = a[n-1]-1;
    while(f[t]) t--;
    t = max(0,t);
    /* cout << "t: " << t << '\n'; */
    cout << ans + t << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


