#include <bits/stdc++.h>
#define ll long long
const int MAX = 1e8;
int fib[MAX];

using namespace std;

ll dpp(ll p){
    if(fib[p] != -1) return fib[p];
    if(p==1) return 1;
    if(p==2) return 1;
    fib[p] = dpp(p-1) + dpp(p-2);
    return fib[p];
}

