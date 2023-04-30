#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
   int n;
   string s; cin >> n >> s;
   if(n != 5){
        cout << "NO" << endl;
        return;
   }
   map<char,int> tem;
   tem['T']++;
   tem['i']++;
   tem['m']++;
   tem['u']++;
   tem['r']++;
   int ok = 1;
   for(int i = 0; i < n; i++){
        if(tem[s[i]])tem[s[i]]++;
   }
   for(int i = 0; i < n; i++){
        if(tem[s[i]] > 2 || !tem[s[i]]) ok = 0;
   }
   cout << (ok ? "YES" : "NO") << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

