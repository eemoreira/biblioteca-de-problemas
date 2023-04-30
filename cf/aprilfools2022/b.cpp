#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a = {1200,1400,1600,1900,2100,2300,2400,2600,3000};
    cout << *upper_bound(a.begin(), a.end(), n) << '\n';
}





