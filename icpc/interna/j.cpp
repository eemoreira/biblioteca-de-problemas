#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s; cin >> s;
    int n; cin >> n;
    int sum=0,tam;
    for(int i = 0; i < n; i++){
        int start, end; cin >> start >> end;
        sum+=start;
        tam = end;
    }
    cout << s.substr(sum,tam) << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

