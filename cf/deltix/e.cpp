#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

vector<string> bit = {"a", "b", "c", "ab", "bc"};

int getmask[50][50];

bool has(string &s, const string &check){
  int cnt = 0;
  int n = check.size();
  for(int i = 0; i < (int)s.size(); i++){
    if(cnt < n && s[i] == check[cnt]){
      cnt++;
    }
  }
  return cnt == n;
}

int getMask(vector<string> &l, vector<string> &r){
  int ans = 0;
  for(auto &s : l){
    for(auto &t : r){
      string all = s + t;
      for(int i = 0; i < 5; i++){
        if(has(all, bit[i])){
          ans |= (1<<i);
        }
      }
    }
  }
  return ans;
}

void process(){
  for(int i = 0; i < 32; i++){
    for(int j = 0; j < 32; j++){
      vector<string> lmsk = {""}, rmsk = {""};
      for(int k = 0; k < 5; k++){
        if(i&(1<<k)){
          lmsk.emplace_back(bit[k]);
        }
        if(j&(1<<k)){
          rmsk.emplace_back(bit[k]);
        }
      }
      getmask[i][j] = getMask(lmsk,rmsk);
    }
  }
}

#define comp(a,b) min(a,b)
const int neutral = 1e9+5;

class SegTree{
  vector<vector<int>> dp;
  int n;
private:
  void combineMask(int v){
    dp[v].assign(50, neutral);
    for(int i = 0; i < 33; i++){
      if(dp[v << 1][i] == neutral){
        continue;
      }
      for(int j = 0; j < 33; j++){
        int mask = getmask[i][j];
        if(~mask){
          dp[v][mask] = min(dp[v][mask], dp[v << 1][i] + dp[1 + (v << 1)][j]);
        }
      }
    }
  }
  void build(int v, int l, int r, string &s){
    if(l == r){
      int msk = s[l-1] - 'a';
      dp[v][1 << msk] = 0;
      dp[v][0] = 1;
      return;
    }
    int mid = (l+r)>>1;
    build(2*v, l, mid, s);
    build(2*v+1, mid+1, r, s);
    combineMask(v);
  }
  void update(int v, int l, int r, int pos, char c){
    if(l == r){
      dp[v].assign(50, neutral);
      int msk = c - 'a';
      dp[v][1 << msk] = 0;
      dp[v][0] = 1;
      return;
    }
    int mid = (l+r)>>1;
    if(pos <= mid){
      update(2*v, l, mid, pos, c);
    }
    else{
      update(2*v+1, mid+1, r, pos, c);
    }
    combineMask(v);
  }
public:
  SegTree(string &s){
    n = (int)s.size();
    dp.resize(4*n, vector<int>(50,neutral));
    build(1,1,n,s);
  }
  void update(int pos, char c){
    update(1,1,n,pos,c);
  }
  int getMin(){
    dbg(dp[1]);
    return *min_element(dp[1].begin(), dp[1].end());
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  process();
  int n,q;
  cin >> n >> q;
  string s; 
  cin >> s;
  SegTree seg(s);
  while(q--){
    int i;
    char c;
    cin >> i >> c;
    seg.update(i,c);
    cout << seg.getMin() << '\n';
  }
}



