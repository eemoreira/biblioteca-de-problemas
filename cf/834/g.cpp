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
    int n; cin >> n;
    vi b(n+1);
    for(int i = 0; i < n/2; i++){
        cin >> b[2*i+1];
    }
    map<int,int> have;
    for(int i = 0; i < n/2; i++){
        if(have.count(b[2*i+1])){
            cout << -1 << '\n';
            return;
        }
        have[b[2*i+1]] = 2*i;
    }
    priority_queue<int> pq;
    for(int i = n; i ; i--){
        if(!have.count(i)){
            if(!pq.empty()){
                int it = pq.top();
                /* cout << "it: " << it << ' ' << i << '\n'; */
                pq.pop();
                b[it] = i;
            }
            else{
                cout << -1 << '\n';
                return;
            }
        }
        else pq.push(have[i]);
        /* cout << pq.top() << ' ' << have[i] << '\n'; */
    }
    for(int i = 0; i < n; i++) cout << b[i] << ' ';
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


