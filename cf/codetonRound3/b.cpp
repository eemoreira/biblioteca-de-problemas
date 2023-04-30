#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqmin;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back
#define inf 1e9+5
#define linf 1e17+5

int ok2321 = 1;

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  int oz = 0;
  int oo = 0;
  int ones = 0;
  int zeros = 0;
  s.pb('&');
  for(int i = 0; i < n; i++){
    ones += s[i] == '1';
    zeros += s[i] == '0';
  }
  for(int i = 0; i < n;){
    int cnt = 0;
    while(s[i] == '0'){
      cnt++;
      i++;
    }
    oz = max(oz,cnt);
    cnt = 0;
    while(s[i] == '1'){
      i++;
      cnt++;
    }
    oo = max(oo,cnt);
  }
  cout << max((ll)ones*zeros, max((ll)oo*oo,(ll)oz*oz)) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



