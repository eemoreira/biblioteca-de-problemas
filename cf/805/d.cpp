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
    string s; cin >> s;
    int p; cin >> p;
    string w = s;
    sor(s);
    reverse(all(s));
    ll total = 0;
    int f[26];
    for(int i = 0; i < 26; i++) f[i] = 0;
    for(auto u : s)total += (u-'a'+1);
    /* cout << s << '\n'; */
    for(auto u : s){
        /* cout << total << ' ' << p << '\n'; */
        if(total <= p) break;
        total -= (u-'a'+1);
        f[u-'a']++;
    }
    for(auto u : w){
        if(f[u-'a']){
            f[u-'a']--;
        }
        else{
            cout <<u;
        }
    }
    cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


