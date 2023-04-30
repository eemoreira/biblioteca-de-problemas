#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    queue<int> q0,q1; 
    for(int i = 0 ; i < n; i++){
        int t,d; cin>> t >> d;
        if(d) q1.push(t);
        else q0.push(t);
    }
    int tempo = 0;
    if(!q1.empty() && !q0.empty()) tempo = q1.front() < q0.front() ? q1.front() : q0.front();

    while(!q1.empty() && !q0.empty()){
        int ok = 1,u=0;
        if(q1.front() < q0.front()){
            u = q1.front();
            q1.pop();
            while(!q1.empty()){
                if(q1.front() < 10+tempo){
                    u = q1.front();
                    q1.pop();
                }
                else if(q0.front() < 10+tempo){
                    ok =0;
                    tempo+=u+10;
                    break;
                }
                else{
                    tempo+=u+10;
                    ok = 0;
                    break;
                }
            }
            if(ok)tempo+=u;
        }
        else{
            u = q0.front();
            q0.pop();
            while(!q0.empty()){
                if(q0.front() < u + 10+tempo){
                    u = q0.front();
                    q0.pop();
                }
                else if(q1.front() < u + 10+tempo){
                    ok = 0;
                    tempo+=u;
                    break;
                }
                else{
                    ok = 0;
                    tempo+=u+10;
                    break;
                }
            }
            if(ok) tempo+=u+10;
        } 
    }
    if(q1.empty() && q0.empty()){
            cout << tempo << endl;
    }
    else if(q1.empty()){
        while(!q0.empty() && q0.front() < tempo){
            q0.pop();
        }
        while(!q0.empty()) {
            tempo = q0.front();
            q0.pop();
        }
        cout << tempo+10 << endl;
    }
    else if(q0.empty()){
        while(!q1.empty() && q1.front() < tempo){
            q1.pop();
        }
        while(!q1.empty()){
            tempo = q1.front();
            q1.pop();
        }
        cout << tempo+10 << endl;
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

