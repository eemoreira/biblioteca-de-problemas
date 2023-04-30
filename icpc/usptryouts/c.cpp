#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 0;
const int mx = 1e6 + 5;

map<char,ll> t[mx];
ll value[mx];

struct trie{
    int nodes = 0;
    void insert(string &s, int v){
        int id = 0;
        ll d = 0;
        /* cout << s << ": "; */
        for(auto u : s){
            if(!t[id].count(u)){
                /* cout << "n tem: " << u << '\n'; */
                t[id][u] = ++nodes;
            }
            else{
                /* cout << "tem: " << u << '\n'; */
                d = max(value[t[id][u]],d);
            }
            id = t[id][u];
        }
        /* cout << "v antes: " << v << " d: " << d << " v agora: "; */
        value[id] = v + d;
        /* cout <<  value[id] << '\n'; */
    }
    ll getValue(string &s){
        int id = 0;
        for(auto u : s){
            if(!t[id].count(u)) return -1;
            id = t[id][u];
        }
        return value[id];
    }
};

void solve(){
    int n; cin >> n;
    vector<pair<pair<int,string>,int>> words;
    trie ty;
    for(int i = 0; i < n; i++){
        string s; int a; cin >> s >> a;
        pair<int,string> c = {(int)s.size(), s};
        words.eb(c,a);
    }
    sor(words);
    ll ans = 0;
    for(auto u : words){
        ty.insert(u.fst.snd,u.snd);
    }
    for(auto u : words){
        ans = max(ty.getValue(u.fst.snd),ans);
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}


