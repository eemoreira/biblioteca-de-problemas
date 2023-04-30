#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;


void solve(){
   ll n,k,b,s; cin>>n>>k>>b>>s;
   vector<ll> a(n);
   for(auto &u : a) u = 0;
   a[0] = s;
   int i = 1;
   int ok = 1;
   while(a[0]/k != b){
       if(i >= n) {
          ok = 0;
          break;
       }
       a[0] -= k-1;
       a[i] += k-1;
       i++;
   }
   if(!ok) cout << -1 << endl;
   else{
       for(int i = 0 ; i < n ; i++) cout << a[i] << ' ';
       cout << endl;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

