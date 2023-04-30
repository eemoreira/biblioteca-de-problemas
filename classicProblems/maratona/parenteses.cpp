#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    while(n--){
    stack<char> st;
    string s; cin >> s;
    int count = 0;
    for(auto u : s){
        if(st.empty() && u != '.')  st.push(u);
        else if (st.top() =='<' && u == '>') {
            st.pop();
            count++;
        }
        else if (u != '.') st.push(u);
    }
    cout << count << endl;
}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

