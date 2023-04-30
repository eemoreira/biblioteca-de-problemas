#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        deque<int> dq;
        int desc = 0;
        vector<int> res;
            for(int i = 0; i < n; i++){
                dq.push_back(i+1);
            }
    while(desc != n - 1){
        auto u = dq.front();
        dq.pop_front(); desc++;
        res.push_back(u);
        auto proxima = dq.front();
        dq.push_back(proxima);
        dq.pop_front();        
        
    }
    cout << "Discarded cards: ";
    for(int i = 0; i < res.size(); i++){
        if(i < res.size() - 1 )cout << res[i] << ", ";
        else cout << res[i] << endl; 
    } 
    cout << "Remaining card: " << dq.back() << endl;   
}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    solve();
	return 0;
}

