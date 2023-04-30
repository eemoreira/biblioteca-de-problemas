#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a,s,d; cin >> a >> s >> d;
    int res = 0;
    int count = 0;
    while(1){
        res += s;
        count++;
        if(res >= a) break;
        res -= d;
    }
    cout << count << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}