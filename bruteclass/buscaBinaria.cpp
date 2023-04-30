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

void solve(){

}

int main(){
    for(int i = 0; i < Q; i++){
        int target; cin >> target;
        bool achou= false;
        for(int j = 0; j < n; j++){
            if(arr[j] == target){
                achou = true;
            }
        }
        if(achou){
            cout << "esta no array\n";
        }
        else{
            cout << "nao esta no array\n";
        }
    }
}



