#include <bits/stdc++.h>

using namespace std;

const int MAX = 50000;

void solve(){
   int n; cin >> n;
   int id[MAX];
   int sairam[MAX];
   for(int i = 1; i <= n; i++){
        cin >> id[i];
   }
   int m; cin >> m;
   for(int i = 1; i <= m; i++){
        cin >> sairam[i];
   }
   for(int i = 1; i<= n; i++){
    for(int k = 1; k<= m;k++){
        if(sairam[k] == id[i]) remove(begin(id), end(id), sairam[k]);
    }
   }
   for(int i = 1; i<=n-m; i++){
        cout << id[i] << " ";
   }
   cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
